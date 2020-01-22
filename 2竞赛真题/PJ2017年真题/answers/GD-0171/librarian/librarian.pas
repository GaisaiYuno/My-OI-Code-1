function f(s:string):string;
var i:longint;
begin
  for i:=1 to length(s) do
    f:=f+s[i];
end;
var
  n,q,i,j,l:longint;
  s:array[1..1000] of string;
  t:array[1..1000] of boolean;
  ls,a:string;
  lt:boolean;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n,q);
  for i:=1 to q do
    readln(s[i]);
  for i:=1 to q-1 do
    for j:=i+1 to q do
      if(f(s[i])<f(s[j])) then
        begin
          ls:=s[i];
          s[i]:=s[j];
          s[j]:=ls;
        end;
  for i:=1 to n do
    begin
      lt:=true;
      readln(l,a);
      delete(a,1,1);
      for j:=1 to q do
        if(t[j]=false) and (pos(a,s[j])=length(s[j])-l+1) and (length(s[j])>=l) then
          begin
            t[j]:=true;
            writeln(s[j]);
            lt:=false;
            break;
          end;
      if lt then
        writeln(-1);
    end;
  close(input);
  close(output);
end.