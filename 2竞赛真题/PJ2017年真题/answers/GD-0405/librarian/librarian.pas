VAR n,i,q,t,b,j:longint;
    a:array[1..100]of longint;
    yon:boolean;
procedure px;
VAR i,j,t:longint;
begin
  for i:=1 to n-1 do
  begin
    for j:=i+1 to n do
    begin
      if a[i]>a[j] then
      begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
      end;//QTL¡«
    end;
  end;
end;
function ok(w,b:longint):boolean;
VAR s,s1,ss,ss1:string;
    i:longint;
begin
  s:='';s1:='';ss:='';ss1:='';
  str(w,ss);
  str(a[b],ss1);
  if length(ss)>length(ss1) then
  begin
    exit(false);
  end;
  for i:=length(ss) downto 1 do
  begin
    s:=s+ss[i];
  end;
  for i:=length(ss1) downto 1 do
  begin
    s1:=s1+ss1[i];
  end;
  for i:=1 to length(s) do
  begin
    if s[i]<>s1[i] then
    begin
      exit(false);
    end;
  end;
  exit(true);
end;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,q);
  for i:=1 to n do
  begin
    readln(a[i]);
  end;
  px;
  for i:=1 to q do
  begin
    readln(t,b);
    yon:=false;
    for j:=1 to n do
    begin
      if ok(b,j) then
      begin
        writeln(a[j]);
        yon:=true;
        break;
      end;
    end;
    if yon then
    begin
      continue;
    end;
    writeln(-1);
  end;
  close(input);
  close(output);
end.