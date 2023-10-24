module VRF0( clk, rstn, Read, Write, src1_start_addr, src2_start_addr,
	vec_length, 
	Bnk0_Din, Bnk1_Din, Bnk2_Din, Bnk3_Din, 
	Bnk4_Din, Bnk5_Din, Bnk6_Din, Bnk7_Din, 
	Bnk0_Dout, Bnk1_Dout, Bnk2_Dout, Bnk3_Dout, 
	Bnk4_Dout, Bnk5_Dout, Bnk6_Dout, Bnk7_Dout );

	integer i;
	input clk, rstn, Read, Write, src1_start_addr, src2_start_addr, vec_length; 
	input [31:0] Bnk0_Din, Bnk1_Din, Bnk2_Din, Bnk3_Din, Bnk4_Din, Bnk5_Din, Bnk6_Din, Bnk7_Din;
	output [31:0] Bnk0_Dout, Bnk1_Dout, Bnk2_Dout, Bnk3_Dout, Bnk4_Dout, Bnk5_Dout, Bnk6_Dout, Bnk7_Dout;

	reg [31:0] Bank0[0:127];
	reg [31:0] Bank1[0:127];
	reg [31:0] Bank2[0:127];
	reg [31:0] Bank3[0:127];
	reg [31:0] Bank4[0:127];
	reg [31:0] Bank5[0:127];
	reg [31:0] Bank6[0:127];
	reg [31:0] Bank7[0:127];

	always @(posedge clk or negedge rstn)
	begin
		if(!rstn)
		begin
			for(i = 0; i<128; i=i+1)
				Bank0[i] = 0;
			for(i = 0; i<128; i=i+1)
				Bank1[i] = 0;
			for(i = 0; i<128; i=i+1)
				Bank2[i] = 0;
			for(i = 0; i<128; i=i+1)
				Bank3[i] = 0;
			for(i = 0; i<128; i=i+1)
				Bank4[i] = 0;
			for(i = 0; i<128; i=i+1)
				Bank5[i] = 0;
			for(i = 0; i<128; i=i+1)
				Bank6[i] = 0;
			for(i = 0; i<128; i=i+1)
				Bank7[i] = 0;
		end	
		else
		begin
			
		end	
	end
endmodule
