module PC(in, clk, rstn, out);
  input [7:0] in;
  input rstn, clk;
  output reg [7:0] out;

  always@(posedge clk or negedge rstn)//rstn is used here as active low
  begin
    if (!rstn)//rstn == 0 reset the circuit 
      out <= 0;
    else      //rstn == 1 normal working
      out <= in;    
  end

endmodule
