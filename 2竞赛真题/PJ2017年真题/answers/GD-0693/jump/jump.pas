var
  i,j,n,m,k,g,c,s,d:longint;
  a,b:array[1..2000] of longint;

procedure try(sum,x:longint);
var
  i,j:longint;
begin
  if sum>=k then
   begin
     writeln(g);
     close(input);
     close(output);
     halt;
   end;
  for i:=x+1 to x+m+g-1 do
   if b[i]=1 then try(sum+a[i],i);
end;

begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
  readln(n,m,k);
  g:=0;
  for i:=1 to n do
   begin
     readln(c,d);
     if d>0 then s:=s+d;
     b[c]:=1;
     a[c]:=d;
   end;
  if s<k then
   begin
     writeln('-1');
     close(input);
     close(output);
     halt;
   end;
  while 1=1 do
   begin
    try(0,0);
    inc(g);
   end;
  close(input);
  close(output);
end.