module Pendulum(
	// Inputs
	CLOCK_50,
	KEY,
	SW,
	GPIO_0,
	GPIO_1,

	// Outputs
	HEX0,
	HEX1,
	HEX2,
	HEX3,
	HEX4,
	HEX5,
	HEX6,
	HEX7,
	

	// Bidirectionals
	SRAM_DQ,
	
	// Outputs
	SRAM_ADDR,
	SRAM_CE_N,
	SRAM_WE_N,
	SRAM_OE_N,
	SRAM_UB_N,
	SRAM_LB_N,
	MonitorISR,
	
	LEDR,
	LEDG
);

// Inputs
input			CLOCK_50;
input		[3:0]	KEY;
input		[17:0] SW;
inout		[35:0] GPIO_0, GPIO_1;

// Outputs
output			MonitorISR;
output	[6:0]	HEX0;
output	[6:0]	HEX1;
output	[6:0]	HEX2;
output	[6:0]	HEX3;
output	[6:0]	HEX4;
output	[6:0]	HEX5;
output	[6:0]	HEX6;
output	[6:0]	HEX7;
output	[17:0] LEDR;
output	[7:0] LEDG;


//SRAM
// Bidirectionals
inout		[15:0]	SRAM_DQ;
// Outputs
output	[17:0]	SRAM_ADDR;
output				SRAM_CE_N;
output				SRAM_WE_N;
output				SRAM_OE_N;
output				SRAM_UB_N;
output				SRAM_LB_N;

wire	[1:0]	PIO_Encoder			= GPIO_0[4:3];
wire			PIO_beam				= GPIO_0[5];
wire 	[9:0] Voltage;  
wire	[1:0]	PIO_HbridgeIn;
wire 			PIO_Hbridge_PWM;

assign GPIO_0[1:0] = PIO_HbridgeIn;
assign GPIO_0[2] = PIO_Hbridge_PWM;

wire a_filtered;
wire b_filtered;
wire [1:0] PIO_Encoder_Filtered = {a_filtered, b_filtered};
inertial_filter i1 (
	.clk			(CLOCK_50),
	.CE			(1'b1),
	.synch_reset(KEY[0]),
	.data_in		(PIO_Encoder[1]),
	.data_out	(a_filtered)
);

inertial_filter i2 (
	.clk			(CLOCK_50),
	.CE			(1'b1),
	.synch_reset(KEY[0]),
	.data_in		(PIO_Encoder[0]),
	.data_out	(b_filtered)
);



nios_system u0 (
        .clk_clk                        (CLOCK_50),              			//clk.clk
        .reset_reset_n                  (KEY[0]),                 		//reset.reset_n
        .sram_0_external_interface_DQ   (SRAM_DQ),   							// sram_0_external_interface.DQ
        .sram_0_external_interface_ADDR (SRAM_ADDR), 							//.ADDR
        .sram_0_external_interface_LB_N (SRAM_LB_N), 							//.LB_N
        .sram_0_external_interface_UB_N (SRAM_UB_N), 							//.UB_N
        .sram_0_external_interface_CE_N (SRAM_CE_N), 							//.CE_N
        .sram_0_external_interface_OE_N (SRAM_OE_N), 							//.OE_N
        .sram_0_external_interface_WE_N (SRAM_WE_N), 							//.WE_N
        .slidersw_export                (SW),									//slidersw.export
        .hexdisplay3to0_HEX0            (HEX0),            					//hexdisplay3to0.HEX0
        .hexdisplay3to0_HEX1            (HEX1),            					//.HEX1
        .hexdisplay3to0_HEX2            (HEX2),            					//.HEX2
        .hexdisplay3to0_HEX3            (HEX3),            					//.HEX3
        .hexdisplay7to4_HEX4            (HEX4),            					//hexdisplay7to4.HEX4
        .hexdisplay7to4_HEX5            (HEX5),            					//.HEX5
        .hexdisplay7to4_HEX6            (HEX6),            					//.HEX6
        .hexdisplay7to4_HEX7            (HEX7),            					//.HEX7
		  .ledgreen_export                (LEDG),	              				//ledgreen.export
        .ledred_export                  ({LEDR[17:1], encoderISRConfirm}),                 		//ledred.export
        .keys_export                    (KEY),                    		//keys.export
        .microseconds_export            (microseconds),           		//microseconds.export
		  .monitor_isr_export             (MonitorISR),							//monitor_isr.export
		  .pio_encoder_export				 (PIO_Encoder_Filtered),			//pio_encoder.export
		  .motor_voltage_export           (Voltage[9:0]), 						//motor_voltage.export
		  .beam_export                    (PIO_beam)    						//beam.export 				/*UPDATED*/
    );	
	 
wire dir;	 
assign PIO_HbridgeIn[1:0] = {dir, ~dir};
pwm	p0(
	.clk					(CLOCK_50),
	.synch_reset		(~KEY[0]),
	.CE					(clkE),
	.OE					(KEY[2]),//;1'b1), //~KEY[1]
	//.data_in				(SW[17:8]), // Manual control
	.data_in				(Voltage[9:0]),  // Connect signal - Why doesn't it work?
	.out					(PIO_Hbridge_PWM),
	.dir					(dir)
);
	 
	 
//assign LEDR[17:0] = Voltage[9:0];//SW[17:0];
wire clkE = (freqk10 == 500);

reg [9:0] freqk10 = 0; 
always @(posedge CLOCK_50)
begin
	if(freqk10 == 500)
		freqk10 <= 10'b0;
	else
		freqk10 <= freqk10 + 1'b1;
end

reg 		[5:0]	CEcount; //Edge Counter to get Microseconds
wire				CE_micro = (CEcount == 6'd50); //Microsecond Condition
always @(posedge CLOCK_50)
begin
	if (CE_micro)
		CEcount <= 0;
	else
		CEcount <= CEcount + 1'b1;
end

reg		[31:0]	microseconds;
always @(posedge CLOCK_50)
begin
	if (CE_micro) microseconds <= microseconds + 1'b1;
end

//Measuring Output Latency to ISR Routine.
wire encoderISRConfirm;
wire encoderEdge;

//assign GPIO_1[0] = encoderISRConfirm;
assign LEDR[0] = encoderISRConfirm;
//assign GPIO_1[1] = encoderEdge;
assign encoderEdge = PIO_Encoder_Filtered[0];

assign GPIO_1[35:18] = {18{encoderISRConfirm}};
assign GPIO_1[17:0] = {18{encoderEdge}};
endmodule 