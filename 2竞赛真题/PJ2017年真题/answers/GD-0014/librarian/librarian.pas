var s,copier:string;
    book,x,len,z:array[1..1000] of longint;
    copi,n,q,i,min,j,temp:longint;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,q);
  for i:=1 to n do
      z[i]:=1;
  for i:=1 to n do
      readln(book[i]);
  for i:=1 to q do
      readln(len[i],x[i]);
  for i:=1 to n-1 do
      for j:=i+1 to n do
          if book[j]<book[i]
             then begin
                    temp:=book[i];
                    book[i]:=book[j];
                    book[j]:=temp;
                  end;
  for i:=1 to q do
      begin
        min:=-1;
        j:=0;
        copi:=0;
        while (copi<>x[i]) and (j<=n) do
              begin
                inc(j);
                str(book[j],s);
                copier:=copy(s,length(s)-len[i]+1,len[i]);
                val(copier,copi);
              end;
        if (j<=n) and (z[j]=1)
           then begin
                  min:=book[j];
                  z[j]:=0;
                end;
        writeln(min);
      end;
  close(input);
  close(output);
end.




