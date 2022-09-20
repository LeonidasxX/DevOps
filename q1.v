module q1(a,b,c,d,f,g);
    input a,b,c,d;
    output f,g;
    assign f = (((~a)|b)&((~c)|d));
    assign g = ~((~((~((~(b&b))&a)) & (~((~(d&d))&c))))&~((~((~(b&b))&a)) & (~((~(d&d))&c))));
endmodule