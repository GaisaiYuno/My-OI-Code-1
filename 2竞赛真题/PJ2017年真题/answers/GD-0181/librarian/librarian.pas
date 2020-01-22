var n,m,i,t,j,k,l1,l2:longint;
    c:char;
    p:boolean;
    a:array[1..1000]of string;
    s:string;
procedure kp(x:longint;y:longint);
var i,j:longint;
    k,t:string;
begin
  i:=x;
  j:=y;
  k:=a[(i+j) div 2];
  while (i<=j) do
  begin
    while ((length(a[i])<length(k))or((length(a[i])=length(k))and(a[i]<k))) do inc(i);
    while ((length(a[j])>length(k))or((length(a[j])=length(k))and(a[j]>k))) do dec(j);
    if (i<=j) then
    begin
      t:=a[i];
      a[i]:=a[j];
      a[j]:=t;
      inc(i);
      dec(j);
    end;
  end;
  if (i<y) then kp(i,y);
  if (x<j) then kp(x,j);
end;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
    readln(a[i]);
  end;
  kp(1,n);
  for i:=1 to m do
  begin
    read(t,c);
    readln(s);
    for j:=1 to n do
    begin
      l1:=length(a[j]);
      l2:=length(s);
      if (l1<l2) then continue;
      p:=true;
      for k:=1 to l2 do
      begin
        if (a[j][l1-k+1]<>s[l2-k+1]) then
        begin
          p:=false;
          break;
        end;
      end;
      if p then
      begin
        writeln(a[j]);
        break;
      end;
    end;
    if j=n then writeln('-1');
  end;
  close(input);
  close(output);
end.
