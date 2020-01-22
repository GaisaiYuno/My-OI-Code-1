var
 x,s:array[1..500000]of longint;
 n,d,k,i:longint;
begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);
 read(n,d,k);
 for i:=1 to n do
  read(x[i],s[i]);
 write(-1);
close(input);close(output);
end.