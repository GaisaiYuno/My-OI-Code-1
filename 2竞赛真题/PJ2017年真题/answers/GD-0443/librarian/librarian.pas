var n1,q1,i,t,k,j:longint;
    ql,nl,s,n,q:array[1..1000] of longint;
    tr:boolean;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
  readln(n1,q1);
  for i:=1 to n1 do
  begin
    read(n[i]);
    s[i]:=10000000;
  end;
  for i:=1 to q1 do
  begin
    read(ql[i]);
    read(q[i]);
  end;
  for i:=1 to q1 do
  begin
    tr:=false;
    for k:=1 to n1 do
    begin
      t:=1;
      for j:=1 to ql[i] do
        t:=t*10;
      t:=n[k] mod t;
      if (t=q[i]) and (s[i]>n[k]) then begin s[i]:=n[k]; tr:=true; end;
    end;
    if tr=false then s[i]:=-1;
  end;
  for i:=1 to n1 do
    writeln(s[i]);
close(input);
close(output);
end.
