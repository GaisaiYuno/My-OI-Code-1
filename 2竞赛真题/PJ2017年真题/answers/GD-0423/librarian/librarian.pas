program librarian(input,output);
var
  n,q,i,j,re:longint;
  a,b,c,r,t:array[-10..10000] of longint;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  read(n,q);
  for i:=1 to n do
   readln(a[i]);
  for i:=1 to q do
   begin
     readln(b[i],c[i]);
     r[i]:=-1;
   end;
  for i:=1 to q do
   begin
    t[i]:=1;
    for j:=1 to b[i] do
     t[i]:=t[i]*10;
   end;
  for i:=1 to q do
   for j:=1 to n do
     begin
       re:=a[j] mod t[i];
       if re=c[i] then
        if (a[j]<r[i]) or (r[i]=-1) then
         r[i]:=a[j];
     end;
  for i:=1 to q do
   writeln(r[i]);
  close(input);close(output);
end.
