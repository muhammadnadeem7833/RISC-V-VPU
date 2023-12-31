module tb_CL01();
//inputs
  reg clk, rstn;
//outputs
  wire [7:0] instr_addr;
  wire [15:0] Instruction;
  wire  PC_select;
  wire [7:0] Jump_addr;
  wire [1:0] Source2_select;
  wire ALU_out_Select, RegWrite_Flag, Rd_select, Mul_flag;
  wire [5:0] Immediate_Addr;
  wire [2:0] shift_amm;
  wire [2:0] Rreg_Sig1, Rreg_Sig2, Wreg_Sig;
  wire [3:0] OPCODE;

  Control_logic_01 obj_CL01(clk, rstn, instr_addr, Instruction, PC_select, Source2_select, ALU_out_Select, RegWrite_Flag, Rd_select, Mul_flag, Jump_addr, Immediate_Addr, shift_amm, Rreg_Sig1, Rreg_Sig2, Wreg_Sig, OPCODE);

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
