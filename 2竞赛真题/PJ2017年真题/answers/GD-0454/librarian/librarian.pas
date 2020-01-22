 var
  i,j,k,l,m,n,t,ans,p:longint;
  a:array[0..1001]of string;
  b:string;
  w:boolean;
  function pd(i,j:longint):longint;
  var k,l:longint;
  begin
   if length(a[i])<length(a[j]) then exit(i);
   if length(a[i])>length(a[j]) then exit(j);
   val(a[i],k);
   val(a[j],l);
   if k>l then exit(j);
   if l>k then exit(i);
   exit(j);

  end;
begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  for i:=1 to m do
    begin
      read(t);readln(b);
      delete(b,1,1);
      ans:=0;
    for j:=1 to n do
       begin
        p:=t;w:=true;
        for k:=length(a[j]) downto length(a[j])-t+1 do
         begin
          if a[j][k]<>b[p] then begin w:=false;break;end;
          dec(p);
         end;
         if w then
           begin
            if ans=0 then ans:=j
                     else ans:=pd(j,ans);
           end;


        end;
      if ans>0 then writeln(a[ans])
        else writeln(-1);
    end;
 close(input);close(output);
end.
