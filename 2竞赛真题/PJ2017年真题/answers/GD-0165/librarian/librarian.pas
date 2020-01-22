var
 f:boolean;
 s,s2:string;
 a,b:array[1..1000]of string;
 n,q,i,min,j,k,m,o:longint;

procedure dr;
begin
 readln(n,q);
 for i:=1 to n do
  readln(a[i]);
 for i:=1 to q do
  readln(b[i]);
end;

begin
 assign(input,'librarian.in');
 assign(output,'librarian.out');
 reset(input);
 rewrite(output);
 dr;
 for i:=1 to q do
  begin
   m:=0;
   min:=maxlongint;
   delete(b[i],1,pos(' ',b[i]));
   s:=b[i];
   for j:=1 to n do
    if (pos(s,a[j])>0)then
     begin
      s2:=copy(a[j],length(a[j])-length(s)+1,length(a[j]));
      if s2=s then
       begin
        val(a[j],o);
        if o<min then
         begin m:=j; min:=o; end;
       end;
     end;
   if m=0 then writeln(-1)
    else writeln(min);
  end;
 close(input);
 close(output);
end.
