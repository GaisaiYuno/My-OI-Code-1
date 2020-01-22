var
n,q,j,i,s:longint;
a,arr,ar:array[0..1000]of string;

procedure kp(l,r:longint);
var
m:string;
i,j:longint;
begin
 i:=l;
 j:=r;
 m:=a[(l+j) div 2];
 repeat
    while a[i]>m do inc(i);
    while a[j]<m do dec(j);
    if i<=j then
    begin
       a[0]:=a[i];
       a[i]:=a[j];
       a[j]:=a[0];
       inc(i);
       dec(j);
    end;
 until i>j;
 if i<r then kp(i,r);
 if l<j then kp(l,j);
end;

begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
reset(output);
 readln(n,q);
 j:=0;
 for i:=1 to n do
 begin
    readln(a[i]);
    if j<length(a[i]) then j:=length(a[i]);
 end;
 for i:=1 to n do
    while length(a[i])<j do
       a[i]:='0'+a[i];
 for i:=1 to q do
 begin
    readln(ar[i]);
    val(copy(ar[i],1,pos(' ',ar[i])-1),s);
    delete(ar[i],1,pos(' ',ar[i]));
    arr:=a;
    for j:=1 to n do
       if copy(a[j],length(a[j])-length(ar[i])+1,length(ar[i]))<>ar[i] then a[j]:='';
    kp(1,n);
    j:=1;
    while a[j]>'' do
       inc(j);
    if a[1]='' then writeln('-1')
    else
    begin
       a[0]:=a[j-1];
       while a[0][1]='0' do
          delete(a[0],1,1);
       writeln(a[0]);
    end;
    a:=arr;
 end;
close(input);
close(output);
end.
