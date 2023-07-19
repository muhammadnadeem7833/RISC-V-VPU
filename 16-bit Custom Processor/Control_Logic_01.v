module Control_logic_01(clk, rstn, instr_addr, PC_select, Source2_select, ALU_out_Select, RegWrite_Flag, Jump_addr, Immediate_Addr, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, OPCODE);
  input clk, rstn; //inputs
 //outputs of module
  output [7:0] instr_addr;
  output PC_select, Source2_select, ALU_out_Select, RegWrite_Flag;
  output [7:0] Jump_addr;
  output [5:0] Immediate_Addr;
  output [2:0] Rreg_Sig1, Rreg_Sig2, Wreg_Sig;
  output [3:0] OPCODE;

  wire  pc_select; //jump_flag (output from decode and input for PC)
  wire [7:0] jump_addr; //address for jump (output from decode and input for PC)
  wire [7:0] inst_address; //address of instruction (output of PC module)

//modules calling
  PC obj_PC(pc_select, jump_addr, clk, rstn, inst_address);

  wire [15:0] instruction;
  IM_ROM obj_IM(inst_address, instruction);

  wire [15:0] instruction1;
  IR obj_IR(instruction, clk, rstn, instruction1);

  wire source2_select, ALU_out_select,regwrite_flag;
  wire [5:0] immediate_addr;
  wire [2:0] Rreg_sig1, Rreg_sig2, Wreg_sig;
  wire [3:0] opcode;
  Decode obj_Dec(instruction1, pc_select, source2_select, ALU_out_select, regwrite_flag, jump_addr, immediate_addr, Rreg_sig1, Rreg_sig2, Wreg_sig, opcode);
//assigning output 
  assign instr_addr = inst_address;
  assign PC_select = pc_select;
  assign Source2_select = source2_select;
  assign ALU_out_Select = ALU_out_select;
  assign RegWrite_Flag = regwrite_flag;
  assign Jump_addr = jump_addr;
  assign Immediate_Addr = immediate_addr;
  assign Rreg_Sig1 = Rreg_sig1;
  assign Rreg_Sig2 = Rreg_sig2;
  assign Wreg_Sig = Wreg_sig;
  assign OPCODE = opcode;
endmodule
