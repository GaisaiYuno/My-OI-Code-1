type
  mytype=record
  long:longint;
  bm:longint;
  end;
var
a,c:array[1..1000]of longint;
b:array[1..1000]of mytype;
i,j,k,n,q,pd:longint;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,q);
  for i:=1 to n do readln(a[i]);
  for i:=1 to q do readln(b[i].long,b[i].bm);
  pd:=1;


  for i:=1 to n do
  begin

    for j:=1 to q do
    begin
       for k:=1 to b[j].long do pd:=pd*10;


      if a[i] mod pd=b[j].bm then
      begin
        if c[j]=0 then c[j]:=a[i];
        if c[j]>a[i] then c[j]:=a[i];
      end;


      pd:=1;
    end;

  end;
  close(input);


  for i:=1 to q do if c[i]=0 then writeln(-1)
  else writeln(c[i]);
  close(output);
end.
