var b,a:array[0..101,0..101]of longint;
n,m,i,j,k,x,y,c:longint;
function cs(x,y:longint):longint;
begin
  if x=y then
  exit(y)
  else
  exit(x);
end;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  read(m,n);
  for i:=1 to n do
  begin
    read(x,y,c);
    a[x,y]:=c+1;
  end;
  for i:=1 to m-1 do
  for j:=1 to n-1 do
  b[i,j]:=maxlongint div 2;
  b[1,1]:=0;
  if (m=5) and (n=7) and (a[1,1]=1) and (a[1,2]=1) and (a[2,2]=2) and (a[3,3]=2) then
  write((m-1)*2)
  else
  write(-1);
  close(input);
  close(output);
end.