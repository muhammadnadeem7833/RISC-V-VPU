module Control_logic_01(clk, rstn, instr_addr);
  input clk, rstn;
  output [7:0] instr_addr;

  wire  pc_select;
  wire [7:0] jump_addr;
  wire [7:0] inst_address;

  PC obj_PC(pc_select, jump_addr, clk, rstn, inst_address);
  assign instr_addr = inst_address;
endmodule
