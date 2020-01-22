var
  a,book:array[1..1000]of string;
  i,j,k,n,m,q:longint;
  c,date:string;
  b:boolean;
procedure qs(l,r:longint);
var
  i,j:longint;
  t,mid:string;
begin
  i:=l;j:=r;mid:=book[(i+j)div 2];
  repeat
    while (length(book[i])<length(mid))or ((length(book[i])=length(mid))and(book[i]<mid)) do inc(i);
    while (length(book[j])>length(mid))or ((length(book[j])=length(mid))and(book[j]>mid)) do dec(j);
    if i<=j then
    begin
      t:=book[i];book[i]:=book[j];book[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qs(i,r);
  if l<j then qs(l,j);
end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,q);
  for i:=1 to n do
    readln(book[i]);
  qs(1,n);
  for i:=1 to q do
  begin
    b:=false;
    readln(c);
    m:=ord(c[1])-48;
    delete(c,1,pos(' ',c));
    for j:=1 to n do
      if length(book[j])>=m then
      begin
        date:=copy(book[j],length(book[j])-m+1,m);
        if date=c then
        begin
          b:=true;
          break;
        end;
      end;
    if b then writeln(book[j]) else writeln(-1);
   end;
   close(input);close(output);
end.


