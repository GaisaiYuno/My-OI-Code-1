var tin,tout:text;
 n,q,i,j,s,t:longint;
 a:array[1..1000]of longint;
 b:array[1..1000,0..1]of longint;
begin
 assign(tin,'librarian.in');
 reset(tin);
 assign(tout,'librarian.out');
 rewrite(tout);
 read(tin,n,q);
 for i:=1 to n do
  read(tin,a[i]);
 for j:=1 to q do
  read(tin,b[j,0],b[j,1]);
 for j:=1 to q do
 begin
  s:=-1;
  t:=1;
  for i:=1 to b[j,0] do
   t:=t*10;
  for i:=1 to n do
   if ((a[i] mod t)=b[j,1]) then
    if(a[i] < s)or(s=-1)then s:=a[i];
  b[j,0]:=s;
 end;
 for j:=1 to q do
  writeln(tout,b[j,0]);
 close(tin);
 close(tout);
end.

