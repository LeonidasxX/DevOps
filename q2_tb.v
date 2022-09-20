`timescale 1ns/1ns
`include "q2.v" //Name of the Verilog file
module q2_tb();
reg a,b,c,d;
//Input
wire f,g;
//Output
q1 qx1(a,b,c,d,f,g); //Instantiation of the module
initial
begin
$dumpfile("q2_tb.vcd");
$dumpvars(0, q2_tb);
a=1'b0;b=1'b0; c=1'b0; d=1'b0;
#20;
a=1'b0;b=1'b0; c=1'b0; d=1'b1;
#20;
a=1'b0;b=1'b0; c=1'b1; d=1'b0;
#20;
a=1'b0;b=1'b0; c=1'b1; d=1'b1;
#20;
a=1'b0;b=1'b1; c=1'b0; d=1'b0;
#20;
a=1'b0;b=1'b1; c=1'b0; d=1'b1;
#20;
a=1'b0;b=1'b1; c=1'b1; d=1'b0;
#20;
a=1'b0;b=1'b1; c=1'b1; d=1'b1;
#20;
a=1'b1;b=1'b0; c=1'b0; d=1'b0;
#20;
a=1'b1;b=1'b0; c=1'b0; d=1'b1;
#20;
a=1'b1;b=1'b0; c=1'b1; d=1'b0;
#20;
a=1'b1;b=1'b0; c=1'b1; d=1'b1;
#20;
a=1'b1;b=1'b1; c=1'b0; d=1'b0;
#20;
a=1'b1;b=1'b1; c=1'b0; d=1'b1;
#20;
a=1'b1;b=1'b1; c=1'b1; d=1'b0;
#20;
a=1'b1;b=1'b1; c=1'b1; d=1'b1;
#20;
$display("Test complete");
end
endmodule