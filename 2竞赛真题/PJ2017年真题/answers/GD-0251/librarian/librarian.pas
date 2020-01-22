var n,q,i,j,e:integer; b:longint;
    s,sfind:string;
    slib:array[0..1001]of string;
begin
  assign(input,'librarian.in'); assign(output,'librarian.out'); reset(input); rewrite(output);
  readln(n,q);
  for i:=1 to n do begin
    readln(s);
    for j:=length(s) downto 1 do
      slib[i]:=slib[i]+s[j];
  end;

  for i:=1 to q do begin
    sfind:='';
    readln(j,b);
    str(b,s);
    for j:=length(s) downto 1 do
      sfind:=sfind+s[j];
    s:='';
    for j:=1 to n do
      if pos(sfind,slib[j])=1 then begin
        s:=slib[j];
        e:=j;
        break;
      end;
    for j:=(e+1) to n do
      if (pos(sfind,slib[j])=1) and (slib[j]<s) then s:=slib[j];
    if s='' then writeln('-1')
    else begin
      for j:=length(s) downto 1 do write(s[j]);
      writeln;
    end;
  end;
  close(input); close(output);
end.
