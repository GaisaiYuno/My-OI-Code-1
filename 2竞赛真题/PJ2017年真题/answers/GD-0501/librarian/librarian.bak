var  n,q,i,j,ii,ans,k:longint; a,xx:array[0..1001] of string;
     l,yy,b:array[0..1001] of integer;   max:string;
begin
  assign(input,'librarian.in'); assign(output,'librarian.out');
  reset(input); rewrite(output);
  readln(n,q);
  for i:=1 to n do
    begin
      readln(a[i]);
      l[i]:=length(a[i]);
    end;
  for i:=1 to q do
    begin
      read(yy[i]);
      readln(xx[i]);
    end;
  for ii:=1 to n do
    begin
      ans:=0;
      for i:=1 to n do
        if b[i]=0 then
         begin
           k:=0;
           for j:=2 to yy[ii]+1 do
             begin
               max:='999999999';
               if xx[ii][j]=a[i][l[i]-yy[ii]-1+j] then
                inc(k);
             end;
           if (k=yy[ii])and(max>a[i]) then
            begin
              ans:=i;
              max:=a[i];
            end;
         end;
      if (ans=0) then writeln('-1')
       else writeln(a[ans]);
      b[ans]:=1;
    end;
  close(input); close(output);
end.
