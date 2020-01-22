var a,s,d,f,g,h,j,k:longint;
    z,x,zx:array[1..1000]of string;
    x2:array[1..1000]of longint;
    ok:array[1..1000]of boolean;
    m,n,q,w:string;
begin
 assign(input,'librarian.in');
 assign(output,'librarian.out');
 reset(input);
 rewrite(output);
 readln(a,s);//z=books;x=people;z[d];x[f];
 for d:=1 to a do
  readln(z[d]);
 for f:=1 to s do
 begin
  readln(x2[f],x[f]);
  delete(x[f],1,1);
 end;
 for d:=1 to s do
  for f:=1 to a do
  begin
   m:='';
   if length(z[f])>=length(x[d]) then
                                 begin
                           m:=z[f];
                           delete(m,1,length(z[f])-x2[d]);
                           if m=x[d] then begin
                                           if (
                                              (z[f]<zx[d])
                                                 or
                                              (length(z[f])<length(zx[d]))
                                                      )
                                           or(not(ok[d]))then zx[d]:=z[f];
                                           ok[d]:=true;
                                          end;
                                end;
   end;
 for d:=1 to s do
  if ok[d] then writeln(zx[d]) else writeln('-1');
 close(input);
 close(output);
end.

