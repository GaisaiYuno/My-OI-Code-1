const
 cf:array[1..8]of longint=(10,100,1000,10000,100000,1000000,10000000,100000000);
var
 n,q,i,j,min:longint;
 a,b,c:array[0..1051] of longint;
  begin
   assign(input,'librarian.in');
   assign(output,'librarian.out');
   reset(input);
   rewrite(output);
   readln(n,q);
   for i:=1 to n do
    readln(a[i]);
   for i:=1 to q do
    readln(b[i],c[i]);
   for i:=1 to q do
    begin
     min:=maxlongint;
     for j:=1 to n do
      begin
        if (a[j] mod cf[b[i]])=c[i] then
          if a[j]<min then min:=a[j];
      end;
     if min=maxlongint then min:=-1;
     writeln(min);
    end;
   close(input);
   close(output);
  end.
