var n,i,j,m,p,k:longint;
    t,c:string;
    a,y:array [1..10001] of string;
    x,b:array [1..10001] of longint;
begin
 assign(input,'librarian.in');
 assign(output,'librarian.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to n do
  readln(a[i]);
 for i:=1 to m do
  readln(x[i],y[i]);
 for i:=1 to n do
  val(a[i],b[i]);
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if b[i]>b[j] then begin
                      t:=a[i]; a[i]:=a[j]; a[j]:=t;
                      k:=b[i]; b[i]:=b[j]; b[j]:=k;
                     end;
 for i:=1 to m do
  delete(y[i],1,1);
 for i:=1 to n do
  begin
   for j:=1 to m do
    begin
     c:=copy(a[j],length(a[j])-x[i]+1,x[i]);
     if c=y[i] then begin writeln(a[j]); break; end;
     if j=m then writeln('-1');
    end;
  end;
 close(input);
 close(output);
end.



