module CL_02(clk, rstn, PC_value, Instruction, Source_01, MUX_01_R, ALU_ans, MUX_02_R, , MUX_03_ans, ALU_Signal);
//inputs
  input clk, rstn;
//outputs
  output [7:0] PC_value;
  output [15:0] Instruction, Source_01, MUX_01_R, ALU_ans, MUX_02_R, MUX_03_ans;
  output [2:0] ALU_Signal;


//Control_logic_01 module calling and defining outputs
  wire [7:0] instr_addr;
  wire [15:0] instruction;
  wire PC_select;
  wire [1:0] Source2_select;
  wire ALU_out_Select, RegWrite_Flag, Rd_Select, Mul_flag;
  wire [7:0] Jump_addr;
  wire [5:0] Immediate_Addr;
  wire [2:0] Shift_amm;
  wire [2:0] Rreg_Sig1, Rreg_Sig2, Wreg_Sig;
  wire [3:0] OPCODE;

  Control_logic_01 obj_CL_01(clk, rstn, instr_addr, instruction, PC_select, Source2_select, ALU_out_Select, RegWrite_Flag, Rd_Select, Mul_flag, Jump_addr, Immediate_Addr, Shift_amm, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, OPCODE);

//ALU control module calling 
  wire [2:0] ALU_signal; 
  ALU_CON obj_ALU_CON(OPCODE, ALU_signal);

//Bits Extend module calling
  wire [15:0] Ext_Immed_Addr;
  Bits_E obj_BE(Immediate_Addr, Ext_Immed_Addr);

//Register File module calling
  wire [15:0] MUX_res3;
  wire [15:0] Dout1;
  wire [15:0] Dout2;
  wire [15:0] Dout3;  //for sw instruction
  RF obj_RF(RegWrite_Flag, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, MUX_res3, clk, rstn, Dout1, Dout2, Dout3);

//MUX 01 module calling
  wire [15:0] res1;
  MUX_1 obj_M1(Source2_select, Dout2, Ext_Immed_Addr, Shift_amm, res1);

//ALU module calling
  wire [31:0] ALU_res;
  ALU obj_ALU(Dout1, res1, ALU_signal, ALU_res);

//ALU module calling
  wire [8:0] SR;
  wire [15:0] Lo;
  wire [15:0] Hi;
  SPR obj_SPR(clk, rstn, Mul_flag, ALU_res, SR, Lo, Hi);

//Data Memory module calling  
  wire [15:0] Mem_Data;
  DM obj_DM(!RegWrite_Flag, ALU_res[15:0], Dout3, clk, rstn, Mem_Data);

//MUX 02 module calling
  wire [15:0] MUX_res2;
  MUX_2 obj_M2(ALU_out_Select, ALU_res[15:0], Mem_Data, MUX_res2);

//MUX 03 module calling
  MUX_3 obj_M3(Rd_select, MUX_res2, Ext_Immed_Addr, MUX_res3);

//assigning outputs
  assign PC_value = instr_addr;
  assign Instruction = instruction;
  assign Source_01 = Dout1;
  assign MUX_01_R = res1;
  assign ALU_ans = ALU_res[15:0];
  assign MUX_02_R = MUX_res2;
  assign MUX_03_ans = MUX_res3;
  assign ALU_Signal = ALU_signal;
  

endmodule
