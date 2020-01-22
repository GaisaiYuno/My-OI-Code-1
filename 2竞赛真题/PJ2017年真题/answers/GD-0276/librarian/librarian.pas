var a,b,c,i,j,n,q:longint;
    f,f1,f2,f3:array[1..1000] of longint;
function lnj(qq,w:longint):longint;
var r,t:longint;
begin
  r:=1;
  for t:=1 to w do r:=r*10;
  exit(qq mod r);
end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,q);
  for i:=1 to n do readln(f[i]);
  for i:=1 to q do begin
    readln(f3[i],f1[i]);
    f2[i]:=maxlongint;
  end;
  for i:=1 to q do begin
    a:=f3[i];
    for j:=1 to n do begin
      if lnj(f[j],a)=f1[i] then begin
        if f[j]<f2[i] then f2[i]:=f[j];
      end;
    end;
  end;
  for i:=1 to q do if f2[i]=maxlongint then f2[i]:=-1;
  for i:=1 to q do writeln(f2[i]);
  close(input);
  close(output);
end.
