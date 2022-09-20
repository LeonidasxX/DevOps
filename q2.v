module q1(a,b,c,d,f,g);
    input a,b,c,d;
    output f,g;
    assign f = ((~b)&(~c))|((~a)&(~c)&d)|((~b)&(~d));
    assign g = ~((~((~(b|c)) | (~(a|c|(~(d|d)))) | (~(b|d)))) | (~((~(b|c)) | (~(a|c|(~(d|d)))) | (~(b|d)))));
endmodule