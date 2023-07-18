module main(pc_out,pc_in);
  //input clk;
  input [7:0] pc_out;
  output [7:0] pc_in;

  assign pc_in=pc_out+1;

  PC(pc_in,pc_out,1,1);
endmodule
