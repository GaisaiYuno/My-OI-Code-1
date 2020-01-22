var
 a:array[0..1000] of longint;
 b:array[0..1000] of string;
 n,m,i,j,ans:longint; c:string; d:longint;


procedure qso(x,y:longint);
var
 i,j,mid:longint;
begin
 if x>=y then exit;
 i:=x; j:=y; mid:=a[(i+j) div 2];
 repeat
  while a[i]<mid do inc(i); while a[j]>mid do dec(j);
  if i<=j then
   begin
    a[0]:=a[i]; a[i]:=a[j]; a[j]:=a[0];
    b[0]:=b[i]; b[i]:=b[j]; b[j]:=b[0];
    inc(i); dec(j);
   end;
   qso(i,y); qso(x,j);
 until i>j;
end;



procedure dddd(d:longint);
var
 i,j:longint; g:string;
begin
 for i:=1 to n do
  if length(b[i])>=d then
   begin
    g:=' ';
    g:=g+copy(b[i],length(b[i])-d+1,d);
    if g=c then begin ans:=a[i]; exit; end;
   end;
end;



begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
 readln(n,m);
 for i:=1 to n do
  begin
   readln(a[i]);
   str(a[i],b[i]);
  end;
 qso(1,n);

 d:=0; c:='';
 for i:=1 to m do
  begin
   readln(d,c);
   ans:=-1;
   dddd(d);
   writeln(ans);
  end;
close(input);
close(output);
end.
