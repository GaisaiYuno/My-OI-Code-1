var
  a,b:array[1..1000]of string;
  n,q,i,j:longint;
  c:array[1..1000]of longint;
  s,max:string;
begin
  input(input,'librarian.in');
  output(output,'librarian.out');
  reset(input);
  rewrite(output);
  read(n,q);
  for i:=1 to n+1 do
    readln(a[i]);
  for i:=1 to q do
  begin
    read(c[i],b[i]);
  end;
  max:='99999999999';
  for i:=1 to q do
  begin
   for j:=1 to n do
   begin
     s:=' '+copy(a[j],length(a[j])-c[i]+1,c[i]);
     if s=b[i]  then
       if (length(max)>length(a[j]))or(max>a[j]) then max:=a[j];
   end;
   if max='99999999999' then writeln('-1')
     else writeln(max);
   max:='99999999999';
  end;
  close(input);
  close(output);
end.
