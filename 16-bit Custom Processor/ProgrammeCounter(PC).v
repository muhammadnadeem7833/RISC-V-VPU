module PC(PC_select, Jump_address, clk, rstn, current_addr);

  input PC_select; //flag to differ between simple & J-type instructions
  input rstn, clk;
  input [7:0] Jump_address; //address to be jumped on
  output [7:0] current_addr; //current instruction's address //by-default wire

  reg [7:0] next_addr; //next instruction's address
  reg [7:0] temp;


  always@(posedge clk or negedge rstn)//rstn is used here as active low
  begin
    if (!rstn)//rstn == 0 reset the circuit
    begin 
      next_addr <= 0;
      temp <= 0;
    end
    else 
    begin
      temp <= next_addr;
      if(PC_select)      //rstn == 1 & when there is the Jump instruction
        next_addr <= Jump_address;
      else
        next_addr <= temp + 1;    //rstn == 1 & when non-jump instruction
    end
  end

  assign current_addr = temp;

endmodule
