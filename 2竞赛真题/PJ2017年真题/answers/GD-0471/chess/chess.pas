const
  dx:array[1..4]of longint=(-1,1,0,0);
  dy:array[1..4]of longint=(0,0,-1,1);
var
  s,x,y,z,i,j,k,m,n,min:longint;
  map,f:array[0..101,0..101]of longint;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  readln(m,n);
  for i:=0 to m+1 do
   for j:=0 to m+1 do
    begin
     map[i,j]:=-1;
     f[i,j]:=maxlongint div 3;
    end;
  f[1,1]:=0;
  for i:=1 to n do
   begin
    readln(x,y,z);
    map[x,y]:=z;
   end;
  for i:=1 to m do
   for j:=1 to m do
    begin
     if map[i,j]<>-1 then continue;
     if ((map[i-1,j]=-1)or(map[i-1,j]=-2))and((map[i+1,j]=-1)or(map[i+1,j]=-2))and((map[i,j-1]=-1)or(map[i,j-1]=-2))and((map[i,j+1]=-1)or(map[i,j+1]=-2))
     then
      map[i,j]:=-2;
    end;
  if //((map[1,2]=-1)and(map[2,2]=-1)and(map[2,1])=-1))or
     ((map[m-1,m]=-1)or(map[m-1,m]=-2))
     and((map[m,m-1]=-1)or(map[m,m-1]=-2))
     and((map[m-1,m-1]=-1)or(map[m-1,m-1]=-2)) then
   begin
    write(-1);
    close(input);close(output);
    exit;
   end;
  for i:=1 to m do
   for j:=1 to m do
    begin
     if map[i,j]=-2 then continue;
     min:=maxlongint div 3;
     for k:=1 to 4 do
      begin
       x:=i+dx[k];y:=j+dy[k];
       if (map[x,y]=-2)or(x<1)or(x>m)or(y<1)or(y>m) then continue;
       if (map[x,y]=map[i,j])and(map[i,j]<>-1)and(map[x,y]<>-1) then
        begin if f[x,y]<min then min:=f[x,y];break;end;
       if (map[i,j]<>-1)and(map[x,y]<>-1) then
        begin if f[x,y]+1<min then min:=f[x,y]+1;continue;end
       else
        begin if f[x,y]+2<min then min:=f[x,y]+2;continue;end;
      end;
     if ((map[i,j]=map[i-1,j-1])and(min=f[i-1,j-1]+4))or
        ((map[i,j]=map[i+1,j+1])and(min=f[i+1,j+1]+4))or
        ((map[i,j]=map[i-1,j+1])and(min=f[i-1,j+1]+4))or
        ((map[i,j]=map[i+1,j-1])and(min=f[i+1,j-1]+4)) then
      min:=min-2 else
     if ((map[i,j]<>map[i-1,j-1])and(min=f[i-1,j-1]+4))or
        ((map[i,j]<>map[i+1,j+1])and(min=f[i+1,j+1]+4))or
        ((map[i,j]<>map[i-1,j+1])and(min=f[i-1,j+1]+4))or
        ((map[i,j]<>map[i+1,j-1])and(min=f[i+1,j-1]+4)) then
      min:=min-1;
     if min<f[i,j] then f[i,j]:=min;
    end;
  write(f[m,m]);
  close(input);close(output);
end.
