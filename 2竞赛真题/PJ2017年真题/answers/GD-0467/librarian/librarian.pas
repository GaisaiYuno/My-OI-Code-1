var n,q,i,o,min,j:longint;
    tem:string;
    a:array[1..1000] of string;
    b,c,s:array[1..1000] of longint;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
  readln(n,q);
  for i:=1 to n do
   readln(a[i]);
  for i:=1 to q do
   begin
     min:=maxlongint;
     fillchar(s,sizeof(s),0);
     o:=0;
     readln(b[i],c[i]);
     str(c[i],tem);
     for j:=1 to n do
      if copy(a[j],length(a[j])-b[i]+1,b[i])=tem then begin
                                                        inc(o);
                                                        val(a[j],s[o]);
                                                      end;
     j:=0;
     for j:=1 to o do
      if s[j]<min then min:=s[j];
     if min=maxlongint then writeln(-1)
                       else writeln(min);
   end;
close(input);
close(output);
end.
