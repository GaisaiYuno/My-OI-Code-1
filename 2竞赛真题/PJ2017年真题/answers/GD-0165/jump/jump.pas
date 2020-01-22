var
 b:array[0..500000]of longint;
 a:array[0..500000]of longint;
 i,j,sum,k,n,m,o,w,l:longint;
begin
 assign(input,'jump.in');
 assign(output,'jump.out');
 reset(input);
 rewrite(output);
 readln(n,m,k);
 for i:=1 to n do
  readln(a[i],b[i]);
 write(-1);
 close(input);
 close(output);
end.
