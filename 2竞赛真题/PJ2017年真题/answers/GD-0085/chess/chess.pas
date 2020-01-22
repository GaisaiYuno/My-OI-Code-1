var m,meiyong,n,n2,c,t:longint;
    f2:boolean;
    f:array[1..100,1..100] of longint;
function dfs(k,l:longint):longint;
begin
  if f[k+1,l]>0 then inc(dfs);
  if f[k,l+1]>0 then inc(dfs);
end;
procedure rearch(x,y:longint);
var i:longint;
begin
  if (x=m) and (y=m) then exit;
  if x>m then exit;
  if y>m then exit;
  f2:=false;
  if (f[x+1,y]>0) and (dfs(x+1,y)=1) then
  begin
    if f[x,y]<>f[x+1,y] then
    begin
      rearch(x+1,y);
      inc(t);
      exit;
    end
    else
    begin
      rearch(x+1,y);
      exit;
    end;
  end;
  if f[x,y+1]>0 then
  begin
    if f[x,y]<>f[x,y+1] then
    begin
      rearch(x,y+1);
      inc(t);
      exit;
    end
    else
    begin
      rearch(x,y+1);
      exit;
    end;
  end;
  if f[x,y]=0 then
    if (not(f2)) and (dfs(x,y)>0) then
    begin
      f2:=true;
      if (f[x+1,y]>0) and (dfs(x+1,y)>dfs(x,y+1)) then rearch(x+1,y)
                                                  else rearch(x,y+1);
      t:=t+2;
    end;
  t:=-1;
  exit;
end;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  read(m,meiyong);
  while eof(input) do
  begin
    read(n,n2,c);
    f[n,n2]:=1;
    if c=0 then inc(f[n,n2]);
  end;
  rearch(1,1);
  if m=1 then writeln(0)
         else writeln(t);
  close(input);
  close(output);
end.
