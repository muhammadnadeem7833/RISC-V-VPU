module PC(PC_select, Jump_address, clk, rstn, instr_addr);

  input PC_select; //flag to differ between simple & J-type instructions
  input rstn, clk;
  input [7:0] Jump_address; //address to be jumped on
  output [7:0] instr_addr; //current instruction's address //by-default wire

  reg [7:0] instr_addr;


  always@(posedge clk or negedge rstn)//rstn is used here as active low
  begin
    if (!rstn)//rstn == 0 reset the circuit
      instr_addr <= 0;
    else  //rstn == 1
    begin
      if(PC_select)      //when there is the Jump instruction
        instr_addr <= Jump_address;
      else
        instr_addr <= instr_addr + 1;    //when non-jump instruction
    end
  end

endmodule
