var
 n,m,i,j:longint;
 a:array[0..1001] of longint;
 d:array[0..1001,1..2] of longint;

procedure qsort(l,r:longint);
 var
 i,j,key,t:longint;
begin
 i:=l; j:=r; key:=a[(l+r) div 2];
 repeat
  while a[i]<key do inc(i);
  while a[j]>key do dec(j);
  if i<=j then
   begin
    t:=a[i];
    a[i]:=a[j];
    a[j]:=t;
    inc(i);
    dec(j);
   end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;


procedure find(ans,w:longint);
 var
  i,tot,len,j:longint;
  s,s2:string;
begin
 for i:=1 to n do
  begin
   str(a[i],s);
   len:=length(s);
   if len>=w then
    begin
     for j:=1 to len-w do
      delete(s,1,1);
     str(ans,s2);
     if s2=s then begin
                    writeln(a[i]);
                    exit;
                   end;
    end;
  end;
  writeln('-1');
end;

begin
 assign(input,'librarian.in');reset(input);
 assign(output,'librarian.out');rewrite(output);
 readln(n,m);
 for i:=1 to n do
  readln(a[i]);
 qsort(1,n);
 for i:=1 to m do
 begin
  readln(d[i,1],d[i,2]);
  find(d[i,2],d[i,1]);
 end;
 close(input);
 close(output);
end.
