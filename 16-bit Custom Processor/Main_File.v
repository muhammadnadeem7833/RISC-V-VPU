module main(clk, rstn);
  input clk, rstn;
  input [7:0] pc_out;
  output [7:0] pc_in;

  assign pc_in=pc_out+1;

  PC obj_pc (pc_in, pc_out, clk, rstn);
  
endmodule
