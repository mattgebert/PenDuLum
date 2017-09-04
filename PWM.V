// Written by Lindsay Kleeman, Monash University
// last updated 2017

module pwm(clk, synch_reset, CE, OE, data_in, out, dir);
// PWM of out in proportion to data_in. dir=1 when data_in negative in 2's complement sense.
// Fundamental period of PWM  = 2**(PWM_IN_SIZE-1) * clk period / (proportion of clock period CE=1)
// Loads new data_in only at end of count cycle (ie all 1's) so that the output proportion 
//   is correct irrespective of when data_in update occurs with respect to the internal count value.
// Internal PWM counter updates on clk edge only when CE=1.
// out and dir are aligned wrt timing within less than one clk period.
// Sequential circuit.

parameter PWM_IN_SIZE = 10;

input clk, synch_reset; // reset is assumed to be synchronised to clk
input CE;  // clock enable -  internal counter increments when CE=1 and rising clk
			// used to divide down when clock active.
input OE; // output enable - OE must be 1 to produce 1 outputs from out.
input signed [PWM_IN_SIZE-1:0] data_in;  // signed 2's complement input
output reg out; 	// out=1 in proportion to (magnitude of data_in)/2**[PWM_IN_SIZE-1]		   
					// out=1 always only when data_in=100..0 (ie most negative input)
output reg dir; 	//  dir =1 when input negative
reg [PWM_IN_SIZE-2:0] count;  // note 1 bit smaller than data_in

// convert to magnitude (NB -2**[n-1] is the only case that needs all PWM_IN_SIZE bits
// (eg in 4 bit 2's complement -8 needs 4 bits for magnitude while all others use 3 bits
//  so that only -8 will result in out=1 always (and dir=1)
wire [PWM_IN_SIZE-1:0] cmp_magn_temp = (data_in[PWM_IN_SIZE-1]? 1'b0-data_in : data_in);
reg  [PWM_IN_SIZE-1:0] cmp_magn;
localparam [PWM_IN_SIZE-2:0] ff = {(PWM_IN_SIZE-1){1'b1}}; //~0;
reg dir1;

always @(posedge clk)
	if (synch_reset)
		begin
			count <= 0;
			cmp_magn <= cmp_magn_temp;
			dir1 <= data_in[PWM_IN_SIZE-1];
		end
	else if (CE) begin
		if (count == ff) // all 1's, so when count wraps to 0 cmp_magn ready
			begin
				dir1 <= data_in[PWM_IN_SIZE-1];
				cmp_magn <= cmp_magn_temp;
			end
		count <= count + 1'b1;
		dir <= dir1; // align dir & out timing
		if (count < cmp_magn)
			out <= OE;
		else out <= 0;
	end
endmodule
	
