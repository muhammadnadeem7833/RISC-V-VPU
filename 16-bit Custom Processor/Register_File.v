module RF(,RegWrite_Flag,Rreg1,Rreg2,Wreg,Datain,Dout1,Dout2);
  input RegWrite_Flag;
  input [2:0] Rreg1;
  input [2:0] Rreg2;
  input [2:0] Wreg; 
  input [15:0] Datain;
  output [15:0] Dout1;
  output [15:0] Dout2;
  reg [15:0] RegMem[0:7];
  
  assign Dout1 = RegMem[Rreg1];
  assign Dout2 = RegMem[Rreg2];
  
  always @(*)
  begin
    if(RegWrite_Flag)
      RegMem[Wreg] = Datain;
  end

endmodule