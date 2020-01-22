var
  a:array [1..1000] of longint;
  b:array [1..1000,1..2] of longint;
  t:array [1..1000] of longint;
  n,q,i,j,s,h,k,dai,shici:longint;

procedure qsort(l,r:longint);
  var
    i,j,mid,h:longint;
begin
  i:=l;
  j:=r;
  mid:=t[(i+j) div 2];
  repeat
    while t[i]<mid do inc(i);
    while t[j]>mid do dec(j);
    if i<=j then
      begin
        h:=t[i];
        t[i]:=t[j];
        t[j]:=h;
        inc(i);
        dec(j);
      end;
  until i>j;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,q) ;
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to q do
    begin
      read(b[i,1]);
      read(b[i,2]);
      readln;
    end;

  for i:=1 to n do
    begin
    s:=1;
    fillchar(t,sizeof(t),0);
    for j:=1 to q do
      begin
       dai:=a[j];
       h:=0;
       shici:=1;
       for k:=1 to b[i,1] do
         begin
           h:=h+(dai mod 10)*shici;
           dai:=dai div 10;
           shici:=shici*10;
         end;
       if h=b[i,2] then
         begin
           t[s]:=a[j];
           inc(s);
         end
      end;
      if s>1 then
      qsort(1,s-1);
      if (t[1] <> 0 ) then
        writeln(t[1])
        else
        writeln('-1');
     end;
  close(input);
  close(output);
end.







