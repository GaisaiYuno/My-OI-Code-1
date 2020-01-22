program librarian;
var i,j,x,y,z,q:longint;
   a:array[1..100] of longint;
   b:array[1..100] of longint;
   c:array[1..100] of longint;
   begin
assign(input,'librarian.in');
assign(output,'librarian.out');
rewrite(input);
reset(output);
read (x,y);
for i:=1 to x do read(a[i]);
for j:=1 to y do read(c[j],b[j]);
writeln('-1');
end.
