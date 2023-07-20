module SPR(clk, rstn, SR, Lo, Hi);
  input clk, rstn;
//special purpose registers
  output [8:0] SR;
  output [15:0] Lo;
  output [15:0] Hi;

  reg [8:0] SR;
  reg [15:0] Lo;
  reg [15:0] Hi;
 
  always @(posedge clk or negedge rstn)
  begin
    if(!rstn)
    begin
//initialize the registers
       SR <= 0;
       Lo <= 0;
       Hi <= 0;
    end
  end
endmodule
