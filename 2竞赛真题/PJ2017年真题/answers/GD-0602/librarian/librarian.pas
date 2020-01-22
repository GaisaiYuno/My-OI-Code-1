const
 num:array[0..9]of longint=(1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000);
var
 a:array[1..1000]of longint;
 n,q,i,j,k,l,b,a1:longint; f,f1:boolean;
procedure sort(l,r: longint);
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
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);
 readln(n,q);
 for i:=1 to n do
  readln(a[i]);
 sort(1,n);
 for i:=1 to q do begin
  readln(l,b);f1:=false;
  for j:=1 to n do
  if f1 then break else
   begin
    a1:=a[j] mod num[l];
    if a1=b then begin f1:=true;break;end;
   end;
  if f1 then writeln(a[j]) else writeln(-1);
 end;
close(input);close(output);
end.

