var n,q,w,l,i,j,max:longint;
    f:boolean;
    t:char;
    s:string;
    a:array[0..1001]of string;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);

  readln(n,q);
  a[0]:='-1';
  for i:=1 to n do
  begin
    while not eoln do
    begin
      read(t);
      a[i]:=t+a[i];
    end;
    readln;
  end;
  for i:=1 to q do
  begin
    s:='';
    while not eoln do begin read(t); s:=t+s; end; readln;
    l:=length(s)-2;
    delete(s,l,2);
    max:=0;
    f:=false;
    for j:=1 to n do
    begin
      if (pos(s,a[j])=1) and ((a[j]>a[max]) or (max=0)) then
        max:=j;
      if a[j]=s then begin writeln(a[j]); f:=true; break; end;
    end;
    if not f then writeln(a[max]);
  end;

  close(input);
  close(output);
end.
