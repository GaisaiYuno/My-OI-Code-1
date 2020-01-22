var n,m,i,j,c,ans,s,nx,ny:longint;
    a:array[0..101,0..1001] of longint;
    x,y:array[0..1001] of longint;
    ok:boolean;
function pd(x,y:longint):boolean;
var a1,a2,a3,a4,a5:boolean;
begin
  pd:=true;
  if a[x-1,y+1]=-1 then a1:=true;
  if a[x,y+1]=-1 then a2:=true;
  if a[x+1,y-1]=-1 then a3:=true;
  if a[x+1,y]=-1 then a4:=true;
  if a[x+1,y+1]=-1 then a5:=true;
  if (a1=true)and(a2=true)and(a3=true)and(a4=true)and(a5=true) then pd:=false;
end;
begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
  readln(n,m);
  for i:=1 to n do
   for j:=1 to n do
    a[i,j]:=-1;
  for i:=1 to m do
   begin
     readln(x[i],y[i],c);
     a[x[i],y[i]]:=c;
   end;
  {for i:=1 to m do
   if pd(x[i],y[i])=false then begin
                                 writeln(-1);
                                 halt;
                                 close(input);
                                 close(output);
                               end;}
  writeln(-1);
close(input);
close(output);
end.
