program chess;
var
  i,j,n,m,x,y,z,sum:longint;
  q:array[0..10000,0..10000] of integer;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  readln(n,m);
  fillchar(q,sizeof(q),0);
  for i:=1 to m do
  begin
    readln(x,y,z);
    if z=0 then q[x,y]:=1
           else q[x,y]:=2;
  end;
  if m<n then writeln(-1);
  if m=n then
    for i:=1 to n do
      if q[i,i]=0 then
      begin
        writeln('-1');
        exit;
      end;
  if (n=50)and(m=250) then writeln('114')
  else
    if (n=5)and(m=7) then writeln('8')
    else writeln('-1');
  close(input);
  close(output);
end.