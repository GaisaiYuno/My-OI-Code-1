var a,b,y,i,j,k:longint;
    x:qword;
    book,books,guest,guestn,z,tf:array[1..1000] of longint;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  x:=1;
  y:=1000000;
  read(a,b);
  for i:=1 to a do readln(book[i]);
  for i:=1 to b do begin
    read(guestn[i]);
    read(guest[i]);
  end;
  for i:=1to b do  begin
    for j:=1 to guestn[i] do begin
      x:=x*10;
    end;
    for j:=1 to a do begin
      if book[j] mod x=guest[i] then books[j]:=book[j];
      end;
    for j:=1 to a do begin
      for k:=1 to i do begin
        if(books[j]<>z[k]) and (book[j]<>0) then tf[j]:=1;
      end;
    end;
    for k:=1 to a do begin
      if (y>books[k]) and (tf[k]=1) then y:=books[j]
      else y:=y;
    end;
    if y=1000000 then writeln('-1')
    else writeln(y);
    z[i]:=y;
    y:=1000000;
    x:=1;
  end;
  close(input);
  close(output);
end.

















