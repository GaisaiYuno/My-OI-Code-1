var n,q,i,j,rec,l:longint;
    need,s:string;
    book:array[0..1010] of string;
    num:array[0..1010] of longint;
  function pd(a:string;b:longint):boolean;
    var k:longint;
  begin
    k:=0;
    while b>0 do
      begin
        inc(k);
        if ord(a[length(a)-k+1])-48<>b mod 10 then exit(false);
        b:=b div 10;
      end;
    exit(true);
  end;
  procedure sort;
    var i,j,temp:longint;
        temp1:string;
  begin
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if num[i]>num[j] then
          begin
            temp:=num[i];
            num[i]:=num[j];
            num[j]:=temp;
            temp1:=book[i];
            book[i]:=book[j];
            book[j]:=temp1;
          end;
  end;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  book[0]:='-1';
  readln(n,q);
  for i:=1 to n do
  begin
    readln(book[i]);
    val(book[i],num[i]);

  end;
  sort;
  for i:=1 to q do
    begin
      readln(s);
      rec:=0;
      need:=copy(s,pos(' ',s)+1,length(s)-pos(' ',s));
      val(need,l);
      for j:=1 to n do
        if pd(book[j],l) then begin rec:=j; break; end;
      writeln(book[rec]);
    end;
  close(input);
  close(output);
end.
