module DM(wflag,ALU_res,datain,dataout);
  input wflag; //write flag
  input [15:0] ALU_res; //final address after adition
  input [15:0] datain; //data to be write on address
  output reg [15:0] dataout; //data to be read from address and sent out
  reg [15:0] Data_Mem[0:65535]; //Data memory array
 
  //to read/write data
  always @(*)
  begin
    if(wflag)
      Data_Mem[ALU_res]=datain; //write data
    else
      dataout=Data_Mem[ALU_res]; //raed data
  end

endmodule
