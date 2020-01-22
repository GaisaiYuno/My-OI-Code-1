 program librarian;
 var
 n,q,i,k,j,xiao:longint;
 Shu,A,B:array[1..1000]of longint;
 begin
 assign(input,'librarian.in');reset(input);
 assign(output,'librarian.out');rewrite(output);
 read(n,q);
 k:=10;
 for i:= 1 to n do
   readln(Shu[i]);
 for i:=1 to q do
  begin
    xiao:=100000000;
    readln(A[i],B[i]);
    if A[i]=2 then  k:=100;
    if A[i]=3 then  k:=1000;
    if A[i]=4 then  k:=10000;
    if A[i]=5 then  k:=100000;
    if A[i]=6 then  k:=1000000;
    if A[i]=7 then  k:=10000000;
    if A[i]=8 then  k:=100000000;
    for j:=1 to n do
     begin
      if (Shu[j] mod k)=B[i] then
        if Shu[j]<xiao then
          xiao:=Shu[j];
     end;
     if xiao=100000000 then writeln('-1')
     else writeln(xiao);
  end;
 close(input);
 close(output);
 end.
