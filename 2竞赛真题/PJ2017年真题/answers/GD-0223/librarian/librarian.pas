Program librarian;
var n,q:0..1001;
    b,len,p,ans:array[0..1001] of longint;
    b1:array[0..1001] of string;
    i,j,code,num:longint;
procedure qs(i,j:longint);
var k,i1,j1,c:longint;
begin
  if i=j then exit;
  i1:=i;
  j1:=j;
  k:=b[i1];
  while (i<j) do
  begin
    while (i<j) and (b[j]>=k) do dec(j);
    while (i<j) and (b[i]<=k) do inc(i);
    if i<=j then
      if i<j then
      begin
        c:=b[i];
        b[i]:=b[j];
        b[j]:=c;
      end
             else
      begin
        c:=b[i1];
        b[i1]:=b[i];
        b[i]:=c;
        qs(i1,i-1);
        qs(i+1,j1);
      end;
  end;
end;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n,q);
  for i:=1 to q do ans[i]:=-1;
  for i:=1 to n do readln(b[i]);
  for i:=1 to q do readln(len[i],p[i]);
  qs(1,n);
  for i:=1 to n do str(b[i],b1[i]);
  for i:=1 to q do
    for j:=1 to n do
    begin
      val(copy(b1[j],length(b1[j])-len[i]+1,len[i]),num,code);
      if p[i]=num then
      begin
        val(b1[j],ans[i],code);
        break;
      end;
    end;
  for i:=1 to q do writeln(ans[i]);
  close(input);
  close(output);
end.

