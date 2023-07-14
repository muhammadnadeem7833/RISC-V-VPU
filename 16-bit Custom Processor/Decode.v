module Decode(instr,opcode,mem_sig,reg_sig1,reg_sig2,reg_sig3,pc_sig);
  input [15:0] instr; //from instruction register
  output [3:0] opcode; //opcode to CU
  output [5:0] mem_sig; //for immediate value or memory to read
  output [2:0] reg_sig1; //when only 1 source register is used
  output [5:0] reg_sig2; //when only 2 source registers are used
  output [2:0] reg_sig3; //for destination register
  output [8:0] pc_sig; //for PC to run jump instruction
  
  //assigning to all appriopriate bits
  assign opcode=instr[3:0];
  assign mem_sig=instr[15:10];
  assign reg_sig1=instr[9:7];
  assign reg_sig2=instr[12:7];
  assign reg_sig3=instr[6:4];
  assign pc_sig=instr[12:4];

endmodule
