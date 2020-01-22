var
 a,c:array[0..1000]of string;
 b,len:array[0..1000]of longint;
 s:string;
 p:boolean;
 n,q,i,j:longint;
begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);
 readln(n,q);
 for i:=1 to n do
  begin
   readln(a[i]);
   len[i]:=length(a[i]);
  end;
 for i:=1 to q do readln(b[i],c[i]);
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if len[i]>len[j] then
                     begin
                      len[0]:=len[i];len[i]:=len[j];len[j]:=len[0];
                      a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
                     end;
 for i:=1 to n do
  begin
   p:=true;
   for j:=1 to n do
    begin
     s:=copy(a[j],length(a[j])-b[i]+1,b[i]);
     s:=' '+s;
     if s=c[i] then
      begin
       writeln(a[j]);
       p:=false;
       break;
      end;
    end;
   if p then writeln(-1);
  end;
close(input);close(output);
end.