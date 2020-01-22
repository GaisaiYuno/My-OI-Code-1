var n,i,j,m,q,t,kk:longint;
a,b:array[1..1001]of string;
l,k,min:qword;
gg:string;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  read(n,q);
  readln(l);
  str(l,a[1]);
  for i:=2 to n do
  readln(a[i]);
  for i:=1 to q do
  begin
    readln(b[i]);
    j:=pos(' ',b[i]);
    delete(b[i],1,j);
    min:=10000000000000000000;
    for j:=1 to n do
    begin
      l:=pos(b[i],a[j]);
      kk:=length(a[j]);
      for m:=length(b[i]) downto 1 do
      begin
        gg:=a[j][kk]+gg;
        dec(kk);
      end;
      if (l<>0) and (b[i]=gg) then
      begin
        val(a[j],k);
        if min>k then
        begin
          min:=k;
          t:=i;
        end;
      end;
      gg:='';
      k:=0;
    end;
    if (t=0) then
    writeln(-1)
    else
    writeln(min);
    t:=0;
  end;
  close(input);
  close(output);
end.