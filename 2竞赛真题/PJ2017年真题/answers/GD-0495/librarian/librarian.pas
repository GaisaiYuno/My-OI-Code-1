var i,j,k,n,m:longint;
a,b:array[1..10000]of ansistring;
len:array[1..10000]of longint;
s,t:ansistring;
function check:boolean;
var x,y:longint;
begin
  x:=0;
  y:=0;
  repeat
    inc(x);
    inc(y);
    if t[x]<s[y]then
    exit(true)
    else
    if t[x]>s[y]then
    exit(false);
  until x=length(t);
  exit(false);
end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do
  readln(a[i]);
  for i:=1 to m do
  begin
    readln(s);
    j:=pos(' ',s);
    t:=copy(s,1,j-1);
    delete(s,1,j);
    b[i]:=s;
    val(t,len[i]);
  end;
  for i:=1 to m do
  begin
    s:='';
    t:='';
    for j:=1 to n  do
    begin
      t:=a[j];
      if copy(t,length(t)-len[i]+1,len[i])=b[i]then
      begin
        if (s='')then
        s:=t
        else
        if (length(t)<length(s))then
        s:=t
        else
        if (check)and(length(t)=length(s)) then
        s:=t;
      end;
    end;
    if s<>'' then
    writeln(s)
    else
    writeln(-1);
  end;
  close(input);close(output);
end.
