var i,j,p,n,len,l,l2,len2,q:longint;
    c:string;
    x:char;
    s2,d:array[0..1000] of longint;
    s:array[1..1000] of string;
function librarian:longint;
var i,j,p:longint;
    s3:string;
begin
  for i:=1 to n do
  begin
    j:=1;
    s3:=s[i];
    while (s3[j]=c[j]) and (j<=len) do inc(j);
    if j-1=len then exit(i);
  end;
  exit(0);
end;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output); 
  readln(n,q);
  for i:=1 to n do readln(s2[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if s2[i]>s2[j] then
      begin
        s2[0]:=s2[i];
        s2[i]:=s2[j];
        s2[j]:=s2[0];
      end;
  for i:=1 to n do
  begin
    l:=s2[i];
    while l>0 do
    begin
      inc(len);
      c:=c+chr(l mod 10+48);
      l:=l div 10;
    end;
    s[i]:=c;
    c:='';
    if len>p then p:=len;
    len:=0;
  end;
  for i:=1 to q do
  begin
    readln(len,x,c);
    if len<=p then
    begin
      for j:=1 to len div 2 do
      begin
        x:=c[j];
        c[j]:=c[len-j+1];
        c[len-j+1]:=x;
      end;
      inc(l2);
      d[l2]:=librarian;
    end;
  end;
  for i:=1 to l2 do
    if d[i]>0 then writeln(s2[d[i]])
    else writeln(-1);
  close(input);
  close(output);
end.
