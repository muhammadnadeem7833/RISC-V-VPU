module CL_02(clk, rstn);
//inputs
  input clk, rstn;
//outputs

  wire [7:0] instr_addr;
  wire PC_select, Source2_select, ALU_out_Select, RegWrite_Flag;
  wire [7:0] Jump_addr;
  wire [5:0] Immediate_Addr;
  wire [2:0] Rreg_Sig1, Rreg_Sig2, Wreg_Sig;
  wire [3:0] OPCODE;

  Control_logic_01 obj_CL_01(clk, rstn, instr_addr, PC_select, Source2_select, ALU_out_Select, Jump_addr, Immediate_Addr, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, OPCODE);
 
  wire [1:0] ALU_signal; 
  ALU_CON obj_ALU_CON(OPCODE, ALU_signal);

  wire [15:0] Ext_Immed_Addr;
  Bits_E obj_BE(Immediate_Addr, Ext_Immed_Addr);

  wire [15:0] MUX_res2;
  wire [15:0] Dout1;
  wire [15:0] Dout2;
  wire [15:0] Dout3;  //in case of sw instruction
  RF obj_RF(RegWrite_Flag, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, MUX_res2, clk, rstn, Dout1, Dout2, Dout3);

  wire [15:0] res1;
  MUX_1 obj_M1(Source2_select, Dout2, Ext_Immed_Addr, res1);

  wire [15:0] ALU_res;
  ALU obj_ALU(Dout1, res1, ALU_signal, ALU_res);
  
  wire [15:0] Mem_Data;
  DM obj_DM(!RegWrite_Flag, ALU_res, Dout3, clk, rstn, Mem_Data);

  MUX_2 obj_M2(ALU_out_Select, ALU_res, Mem_Data, MUX_res2);
 
endmodule
