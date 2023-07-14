module IR(in_inst,out_inst,clk);
  input [15:0] in_inst;
  input clk;
  output reg [15:0] out_inst;

  always @(posedge clk)
  begin
    out_inst <= in_inst;
  end
endmodule
