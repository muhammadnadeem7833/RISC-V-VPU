module RF(RegWrite_Flag, Rreg1, Rreg2, Wreg, Datain, clk, rstn, Dout1, Dout2, Dout3);

  input RegWrite_Flag; //control signal, whether write on destination register or not
  input [2:0] Rreg1; //3-bits of source-1 reg.
  input [2:0] Rreg2; //3-bits of source-2 reg.
  input [2:0] Wreg; //3-bits of destination reg.
  input [15:0] Datain; //data to be write on destination reg.
  input clk, rstn;

  output [15:0] Dout1; //source-1 out
  output [15:0] Dout2; //souerce-2 out
  output [15:0] Dout3; //destination register data (for sw instruction)

  reg [15:0] RegMem[0:7]; //array of 8 registers (16-bit each)
  integer i = 0;
  
  always @(posedge clk or negedge rstn)
  begin
    if (!rstn)
//initialize all registers with 0 value
      for(i = 0; i < 8; i = i + 1)
        RegMem[i] <= 0;
    else
//if write signal i== 1, write on the register-memeory
      if(RegWrite_Flag)
        RegMem[Wreg] <= Datain;
  end

//2 wires for 2 source registers
  assign Dout1 = RegMem[Rreg1];
  assign Dout2 = RegMem[Rreg2];
  assign Dout3 = RegMem[Wreg];

endmodule
