const
  h:array[1..9] of longint=(10,100,1000,10000,100000,1000000,10000000,100000000,1000000000);
var
  n,m,i,j,b,c,min:longint;
  a:array[1..1100] of longint;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  for i:=1 to m do
   begin
    readln(c,b);
    min:=maxlongint;
    for j:=1 to n  do
     if (a[j] mod h[c]=b)and(a[j]<min) then min:=a[j];
    if min<maxlongint then writeln(min)
                      else writeln('-1');
   end;
close(input);
close(output);
end.


