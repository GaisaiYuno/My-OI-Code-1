var a,b,c,d,e,f,i:longint;
u:array[1..1000]of string;
o:array[1..1000]of longint;
s:string;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);rewrite(output);
  readln(a,b);
  for c:=1 to b do o[c]:=999999999;
  for c:=1 to a do readln(u[c]);
  for c:=1 to b do begin
    readln(d,e);
    str(e,s);
    for f:=1 to a do begin
      if s=copy(u[f],length(u[f])-length(s)+1,length(s)) then begin
        val(u[f],i);
        if i<o[c] then o[c]:=i;
      end;
    end;
  end;
  for c:=1 to b do if o[c]<>999999999 then writeln(o[c])
  else writeln('-1');
  close(input);close(output);
end.
