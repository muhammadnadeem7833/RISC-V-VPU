module SPR(clk, rstn, flag, ALU_res, SR, Lo, Hi);
  input clk, rstn;
  input flag; //flag to write on Hi and Lo
  input [31:0] ALU_res; //multiplication result from ALU
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
    else if(flag) //if multiplication flag == 1, write resulte on Hi and Lo registers
         begin
           Lo <= ALU_res[15:0];
           Hi <= ALU_res[31:16];
         end
  end
endmodule
