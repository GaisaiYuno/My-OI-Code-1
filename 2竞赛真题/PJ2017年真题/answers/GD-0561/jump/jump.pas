var n,d,k,i,j,tot,g,max:longint;
    c,w:array [0..500010] of longint;
procedure dfs(dep,g,sum,o:longint);
var i,cha,he:longint;
begin
  if(sum>=k) then begin writeln(g); halt; end;
  cha:=d-g;
  he:=d+g;
  if(cha<=0) then cha:=1;
  for i:=o+1 to n do begin
    if(c[i]-dep>=cha) and (c[i]-dep<=he) then dfs(c[i],g,sum+w[i],i);
  end;
end;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  readln(n,d,k);
  max:=d;
  for i:=1 to n do begin
    readln(c[i],w[i]);
    if(w[i]>=0) then inc(tot,w[i]);
    if(c[i]>max) then max:=c[i];
  end;
  c[0]:=0;
  if(tot<k) then begin writeln(-1); halt; end;
  for i:=1 to max do begin
    dfs(0,i,0,0);
  end;
  writeln(-1);
  close(input);
  close(output);
end.
