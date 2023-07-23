module tb_CL02();
//inputs
  reg clk, rstn;
//outputs
  wire [7:0] PC_value;
  wire [15:0] Instruction, Source_01, MUX_01_R, ALU_ans, MUX_02_R, MUX_03_R;
  wire [2:0] ALU_Signal;

//calling Control logic 02 module
  CL_02 obj_CL02(clk, rstn, PC_value, Instruction, Source_01, MUX_01_R, ALU_ans, MUX_02_R, MUX_03_R, ALU_Signal);

  always
  #5
  clk = !clk;

  initial
  begin
    clk = 0; rstn = 0;
    #20
     rstn = 1;
  end

endmodule
