module PC(in,out,clk,rstn);
  input [7:0] in;
  output reg [7:0] out;
  input rstn, clk;

  always@(posedge clk or negedge rstn)//rstn is used here as active low
  begin
    if (!rstn)//rstn == 0 reset the circuit 
      out <= 0;
    else      //rstn == 1 normal working
      out <= in;    
  end

endmodule
