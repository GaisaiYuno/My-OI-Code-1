var n,d,k,i,j,l,total,ans,f,t:longint;
    x,s:array[-10..510] of longint;
begin
  assign(input,'jump.in'); reset(input);
  assign(output,'jump.out'); rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
  begin
    readln(x[i],s[i]);
    if s[i]>0 then l:=l+s[i];
    total:=total+s[i];
  end;
  if l<k then
  begin
    write(-1);
    close(input); close(output);
    halt;
  end;
  if total>=k then
  begin
    write(0);
    close(input); close(output);
    halt;
  end;
  t:=0;
  if d=1 then
  begin
    for i:=1 to n do
    begin
      if s[i]>0 then
      begin
        ans:=ans+x[i]-x[t]-1;
        f:=f+s[i];
        t:=i;
      end;
      if f>=k then
      begin
        write(ans);
        close(input); close(output);
        halt;
      end;
    end;
  end;
  close(input); close(output);
end.
