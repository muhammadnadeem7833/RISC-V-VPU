module IR(in_inst, clk, rstn, out_inst);
  input [15:0] in_inst; //instruction from ROM
  input clk, rstn;
  output reg [15:0] out_inst; //output register

  always @(posedge clk or negedge rstn) //run on positive edge only
  begin
    if (!rstn)
        out_inst <= 0;
    else
      out_inst <= in_inst; //value assigning(non-blocking statement)
  end
endmodule
