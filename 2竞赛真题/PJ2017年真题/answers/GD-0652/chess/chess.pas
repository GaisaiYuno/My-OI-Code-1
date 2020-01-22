const
 fx:array[1..2]of longint=(0,1);
 fy:array[1..2]of longint=(1,0);
var
 i,j,n,m,ans,x,y,z:longint;
 map:array[1..100,1..100]of longint;
 b:array[1..100,1..100]of boolean;
 bb:boolean;
 function check(a,b:longint):boolean;
  begin
   if (a>0)and(b>0)and(a<=m)and(b<=m) then exit(true); exit(false);
  end;
 procedure dfs(x,y,spend:longint;can:boolean);
  var i:longint;
 begin
  if (x=m)and(y=m) then
  begin
   if spend<ans then ans:=spend;
   bb:=true;
   exit;
  end;
  for i:=1 to 2 do
   begin
    if check(x+fx[i],y+fy[i]) then
     if b[x+fx[i],y+fy[i]] then
      begin
       if map[x+fx[i],y+fy[i]]=map[x,y] then
       dfs(x+fx[i],y+fy[i],spend,true) else
       dfs(x+fx[i],y+fy[i],spend+1,true);
      end else
     if can then
     begin
      b[x+fx[i],y+fy[i]]:=true;
      dfs(x+fx[i],y+fy[i],spend+2,false);
      b[x+fx[i],y+fy[i]]:=false;
     end;
   end;
 end;
procedure readd;
 var x,y,z:longint;
begin
 read(m,n);
 for i:=1 to n do
 begin
  readln(x,y,z);
  map[x,y]:=z;
  b[x,y]:=true;
 end;
end;
begin
 assign(input,'chess.in');
 assign(output,'chess.out');
 reset(input);
 rewrite(output);    
 readd;
 ans:=maxlongint;
 dfs(1,1,0,true);
 if bb then write(ans) else write(-1);
 close(input);
 close(output);
end.
