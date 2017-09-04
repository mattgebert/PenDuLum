module RTSLab(
	LEDR,
	LEDG,
	SW,
	HEX0,
	HEX1,
	HEX2,
	HEX3,
	HEX4,
	HEX5,
	HEX6,
	HEX7,
	KEY,
	CLOCK_50,
	SRAM_DQ,
	SRAM_ADDR,
	SRAM_CE_N,
	SRAM_WE_N,
	SRAM_OE_N,
	SRAM_UB_N,
	SRAM_LB_N
);

input		[17:0]	SW;
input		[3:0]		KEY;
input					CLOCK_50;
output	[17:0]	LEDR;
output	[7:0]		LEDG;
output	[6:0]		HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7;

// SRAM
inout		[15:0]	SRAM_DQ;
output	[17:0]	SRAM_ADDR;
output			SRAM_CE_N;
output			SRAM_WE_N;
output			SRAM_OE_N;
output			SRAM_UB_N;
output			SRAM_LB_N;


assign LEDR = SW;


reg 		[5:0]	CEcount; //Edge Counter to get Microseconds
wire					CE_micro = (CEcount == 6'd50); //Microsecond Condition
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



RTSlabSystem u0 (
        .clk_clk                        (CLOCK_50),                        //                       clk.clk
        .sram_0_external_interface_DQ   (SRAM_DQ),   // sram_0_external_interface.DQ
        .sram_0_external_interface_ADDR (SRAM_ADDR), //                          .ADDR
        .sram_0_external_interface_LB_N (SRAM_LB_N), //                          .LB_N
        .sram_0_external_interface_UB_N (SRAM_UB_N), //                          .UB_N
        .sram_0_external_interface_CE_N (SRAM_CE_N), //                          .CE_N
        .sram_0_external_interface_OE_N (SRAM_OE_N), //                          .OE_N
        .sram_0_external_interface_WE_N (SRAM_WE_N), //                          .WE_N
        .hexdisplay3to0_HEX0            (HEX0),            //            hexdisplay3to0.HEX0
        .hexdisplay3to0_HEX1            (HEX1),            //                          .HEX1
        .hexdisplay3to0_HEX2            (HEX2),            //                          .HEX2
        .hexdisplay3to0_HEX3            (HEX3),            //                          .HEX3
        .hexdisplay7to4_HEX4            (HEX4),            //            hexdisplay7to4.HEX4
        .hexdisplay7to4_HEX5            (HEX5),            //                          .HEX5
        .hexdisplay7to4_HEX6            (HEX6),            //                          .HEX6
        .hexdisplay7to4_HEX7            (HEX7),            //                          .HEX7
        .ledgreen_export                (LEDG),                //                  ledgreen.export
        //.ledred_export                  (LEDR),                  //                    ledred.export
        .slidersw_export                (SW),                //                  slidersw.export
        .keys_export                    (KEY),                    //                      keys.export
        .microseconds_export            (microseconds)             //              microseconds.export
    );
	 
endmodule

