var n,q,i,j,m,w,k:longint;
    ww:char;
   ans,x:array[0..1000] of longint;
   s:string;
   a:array[0..1000] of string;
begin
  assign(input,'librarian.in');
  assign(output,'libraian.out');
  reset(input);
  rewrite(output);


  readln(n,q);
  for i:=1 to n do
      readln(a[i]);
  for i:=1 to q do
      begin
        read(x[i]);
        readln(s);
        ans[i]:=10000001;
        for j:=1 to n do
            begin
              m:=x[i]+1;
              for k:=length(a[j]) downto 1 do
                  begin
                  if m=1 then
                     begin
                       val(a[j],w);
                       if w<ans[i] then
                       ans[i]:=w;


                     end;
                  if a[j][k]<>s[m] then break
                  else dec(m);
                  end;
              if m=1 then
                 begin
                   val(a[j],w);
                   if w<ans[i] then
                      ans[i]:=w;
                 end;
            end;
      end;
  for i:=1 to q do
      if ans[i]=10000001 then
         writeln('-1')
      else writeln(ans[i]);

  close(input);
  close(output);
end.
