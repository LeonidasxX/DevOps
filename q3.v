module q1(a,b,c,d,f,g);
    input a,b,c,d;
    output f,g;
    assign f = ((~a)&d)|((~c)&d);
    assign g = ~((~((~((~(d|d))|a)) | (~((~(d|d))|c)))) | (~((~((~(d|d))|a)) | (~((~(d|d))|c))))) ;
endmodule