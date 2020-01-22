var n,d,k,g,i,j,c,p,ans,sum:longint;
x,s,t,a:array[0..500000]of longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
  begin
    readln(x[i],s[i]);
    if s[i]>0 then
    inc(s[i],sum);
  end;
  for i:=1 to n do
  a[i]:=x[i];
  for i:=1 to n do
  dec(x[i],a[i-1]);
  if sum=k then
  begin
    writeln(-1);
    halt;
  end;
 
  g:=1;
  while g<1000000000 do
  begin
    fillchar(t,sizeof(t),0);
    for i:=1 to n do
    if (g=d) or (a[j]=d-g) and (a[i]=d+g) then
    begin
      inc(ans);
      t[ans]:=a[i];
    end;
    for i:=1 to n-1 do
    for j:=1 to ans do
    if t[i]<t[j] then
    begin
      t[0]:=t[j];
      t[i]:=t[j];
      t[j]:=t[0];
    end;
    c:=0;
    p:=0;
    while (c<d+g) and (p>d-g) do
    begin
      inc(c,t[ans]);
      inc(g);
    end;
     inc(g);
    if c=p then
    begin
      writeln(-1);
      halt;
    end;
  end;
  close(input);
  close(output);
end.