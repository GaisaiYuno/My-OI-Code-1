var n1,n2,i,j,min,len:longint;
    st,t:string;
    a:array[0..1010]of string;
    b:array[0..1010]of longint;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n1,n2);
  for i:=1 to n1 do
    begin
      readln(a[i]);
      val(a[i],b[i]);
    end;
  b[0]:=2147483647;
  for i:=1 to n2 do
    begin
      min:=0;
      readln(len,st);
      delete(st,1,1);
      for j:=1 to n1 do
        begin
          t:=copy(a[j],ord(a[j][0])-len+1,len);
          if (t=st)and(b[j]<b[min]) then min:=j;
        end;
      if min=0 then writeln(-1)
               else writeln(b[min]);
    end;
  close(input);
  close(output);
end.
