var n,q,i,j,k,min,min1,now:longint;
a:array[1..1000] of longint;
duzhe:array[1..1000,1..2] of longint;
ans:array[1..1000] of longint;
s1,s2:string;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,q);
  min:=99999999;
  for i:=1 to n do readln(a[i]);
  for i:=1 to q do
  begin
    read(duzhe[i,2]);
    read(duzhe[i,1]);
  end;
  for i:=1 to q do ans[i]:=-1;
  for i:=1 to q do
  begin
    str(duzhe[i,1],s1);
    now:=length(s1);
    for j:=1 to n do
    begin
      str(a[j],s2);
      if length(s2)>=length(s1) then
      for k:=length(s2) downto (length(s2)-length(s1)+1) do
      begin
        if now=0 then break;
        if s2[k]<>s1[now] then break;
        if k=0 then break;
        if (s2[k]=s1[now])and(k=length(s2)-length(s1)+1) then
        begin
          val(s2,min1);
          break;
        end;
        dec(now);
      end else if length(s2)<now then continue;
      if (min>min1)and(min1<>-1)and(min1<>0) then min:=min1;
      now:=length(s1);
    end;
    if min<>99999999 then ans[i]:=min else ans[i]:=-1;
    min:=99999999;
    min1:=-1;
  end;
  for i:=1 to q do writeln(ans[i]);
  close(input);
  close(output);
end.
