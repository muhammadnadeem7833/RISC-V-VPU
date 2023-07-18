module main(clk, rstn);
  input clk, rstn;
  wire [7:0] pc_out;  //Output of PC
  wire [7:0] pc_in;   //Generated in this module

  assign pc_in=pc_out+1;

  PC obj_pc (pc_in, pc_out, clk, rstn);
  
endmodule
