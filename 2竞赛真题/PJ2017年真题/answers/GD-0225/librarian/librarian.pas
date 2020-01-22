var s:array[0..1020] of string;
var s1:string;
var n,m,i,j,ans,x,y,k,d:longint;
var r:boolean;
var a,l:array[0..1020] of longint;
procedure qsort(l1,r:longint);
var i,j,mid,t:longint;
var tt:string;
begin
  i:=l1;j:=r;mid:=a[(l1+r)>>1];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then begin
      t:=a[i];a[i]:=a[j];a[j]:=t;
      t:=l[i];l[i]:=l[j];l[j]:=t;
      tt:=s[i];s[i]:=s[j];s[j]:=tt;
      inc(i);dec(j);
    end;
  until i>j;
  if l1<j then qsort(l1,j);
  if i<r then qsort(i,r);
end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  read(n,m);
  for i:=1 to n do begin read(a[i]);str(a[i],s[i]);l[i]:=length(s[i]);end;
  qsort(1,n);
  //for i:=1 to n do writeln(s[i]);
  for i:=1 to m do
  begin
    read(x,y);str(y,s1);
    for j:=1 to n do
    if x<=l[j] then
    begin
      k:=l[j];d:=x;r:=true;
      while d>0 do
      begin
        //writeln(d,' ',k,' ',s[k],' ',s1[d],' ',j);
        if s[j,k]<>s1[d] then begin r:=false;break;end;
        dec(d);dec(k);
      end;
      if r then begin writeln(a[j]);break;end;
    end else r:=false;
    if not r then writeln(-1);
  end;
  close(input);close(output);
end.