var n,q,i,j,min:longint;
    b,l,r:array[0..1001]of longint;
function mymi(x:longint):longint;
begin
  mymi:=1;
  while x>0 do
    begin
      mymi:=mymi*10;
      dec(x);
    end;
end;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n,q);
  for i:=1 to n do readln(b[i]);
  for i:=1 to q do
    begin
      readln(l[i],r[i]);
      l[i]:=mymi(l[i]);
    end;
  for i:=1 to q do
    begin
      min:=maxlongint;
      for j:=1 to n do
        if b[j]mod l[i]=r[i]then
          if b[j]<min then min:=b[j];
      if min=maxlongint then writeln(-1)
                        else writeln(min);
    end;
  close(input);
  close(output);
end.