program score(input,output,score);
var z,x,q:integer;
    t:file;
assign:(score);
reset(t);
read(t,z,x,q);
close(t);
assign(t,score.out);
rewrite(t);
write(t,z*0.2+x*0.3+q*0.5:5:3);
close(t);
end.
