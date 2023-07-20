module CL_02(clk, rstn, PC_value, Instruction, Source_01, MUX_01_R, ALU_ans, MUX_02_R);
//inputs
  input clk, rstn;
//outputs
  output [7:0] PC_value;
  output [15:0] Instruction, Source_01, MUX_01_R, ALU_ans, MUX_02_R;

//Control_logic_01 module calling and defining outputs
  wire [7:0] instr_addr;
  wire [15:0] instruction;
  wire PC_select, Source2_select, ALU_out_Select, RegWrite_Flag;
  wire [7:0] Jump_addr;
  wire [5:0] Immediate_Addr;
  wire [2:0] Rreg_Sig1, Rreg_Sig2, Wreg_Sig;
  wire [3:0] OPCODE;

  Control_logic_01 obj_CL_01(clk, rstn, instr_addr, instruction, PC_select, Source2_select, ALU_out_Select, Jump_addr, Immediate_Addr, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, OPCODE);

//ALU control module calling 
  wire [1:0] ALU_signal; 
  ALU_CON obj_ALU_CON(OPCODE, ALU_signal);

//Bits Extend module calling
  wire [15:0] Ext_Immed_Addr;
  Bits_E obj_BE(Immediate_Addr, Ext_Immed_Addr);

//Register File module calling
  wire [15:0] MUX_res2;
  wire [15:0] Dout1;
  wire [15:0] Dout2;
  wire [15:0] Dout3;  //in case of sw instruction
  RF obj_RF(RegWrite_Flag, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, MUX_res2, clk, rstn, Dout1, Dout2, Dout3);

//MUX 01 module calling
  wire [15:0] res1;
  MUX_1 obj_M1(Source2_select, Dout2, Ext_Immed_Addr, res1);

//ALU module calling
  wire [15:0] ALU_res;
  ALU obj_ALU(Dout1, res1, ALU_signal, ALU_res);

//Data Memory module calling  
  wire [15:0] Mem_Data;
  DM obj_DM(!RegWrite_Flag, ALU_res, Dout3, clk, rstn, Mem_Data);

//MUX 02 module calling
  MUX_2 obj_M2(ALU_out_Select, ALU_res, Mem_Data, MUX_res2);

//assigning outputs
  assign PC_value = instr_addr;
  assign Instruction = instruction;
  assign Source_01 = Dout1;
  assign MUX_01_R = res1;
  assign ALU_ans = ALU_res;
  assign MUX_02_R = MUX_res2;
  

endmodule
