module DM(wflag, ALU_res, datain, clk, rstn, dataout);

  input wflag; //write flag
  input [15:0] ALU_res; //final address after adition from ALU
  input [15:0] datain; //data to be write on final address
  input clk, rstn;

  output [15:0] dataout; //data to be read from address and send

  reg [15:0] Data_Mem[0:65535]; //Data memory array
  reg [15:0] dataout;
  integer i;
 
 
  always @(posedge clk or negedge rstn)
  begin
    if(!rstn)
//initialize all memory locations with 0 value
      for(i = 0; i < 65536; i = i + 1)
        Data_Mem[i] <= 0;
    else
//to read/write data from/to memory
      begin
        if(wflag)
          Data_Mem[ALU_res] <= datain; //write data
        else
          dataout <= Data_Mem[ALU_res]; //raed data
      end
  end

endmodule
