var n,m,o,i1,t,k,c:longint;
    s,s1,s2:string;
    a:array[1..5000] of longint;
procedure sort(l,r:longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  read(n,m);
  for o:=1 to n do read(a[o]);
  sort(1,n);
  for o:=1 to m do
  begin
    t:=0;
    read(k);
    readln(s);
    delete(s,1,1);
    for i1:=1 to n do
       begin
         str(a[i1],s1);
         c:=length(s1);
         s2:=copy(s1,c-k+1,k);
         if (s=s2) then begin
                           t:=i1;
                           break;
                         end;
       end;
   if (t>0) then writeln(a[i1])
   else writeln(-1);
  end;
  close(input);
  close(output);
end.
