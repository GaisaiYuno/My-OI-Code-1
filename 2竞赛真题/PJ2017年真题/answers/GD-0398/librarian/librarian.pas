type
  arr=record
    num,w,m:longint;
  end;
  arrr=array[1..1000] of arr;
var
  a,b:arrr;
  ans:array[1..1000] of longint;
  n,q,i,last,lastleng,j,t:longint;
  bo:boolean;
  s:string;

procedure qsort(var c:arrr;l,r:longint);
var
  i,j,mid:longint;
  t:arr;
begin
  i:=l;
  j:=r;
  mid:=c[(i+j) div 2].num;
  repeat
    while c[i].num<mid do inc(i);
    while c[j].num>mid do dec(j);
    if i<=j then begin
      t:=c[i];
      c[i]:=c[j];
      c[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then qsort(c,l,j);
  if i<r then qsort(c,i,r);
end;

function com(x,y:longint):boolean;
var
  s1,s2:string;
  l1,l2:longint;
begin
  str(x,s1);
  str(y,s2);
  l1:=length(s1);
  l2:=length(s2);
  while l2>0 do begin
    if s2[l2]<>s1[l1] then exit(false);
    dec(l2);
    dec(l1);
  end;
  exit(true);
end;

begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);

  readln(n,q);
  for i:=1 to n do begin
    readln(a[i].num);
    str(a[i].num,s);
    a[i].w:=length(s);
  end;
  qsort(a,1,n);
  for i:=1 to n do begin
    readln(b[i].w,b[i].num); ;
    b[i].m:=i;
  end;
  qsort(b,1,n);
  last:=1;
  lastleng:=a[1].w;
  for i:=1 to q do begin
    bo:=false;
    if b[i].w>lastleng then begin
      for j:=last+1 to n do
       if a[j].w>=b[i].w then begin
         lastleng:=a[j].w;
         t:=j;
         break;
       end;
      last:=t;
    end;
    for j:=last to n do
     if com(a[j].num,b[i].num) then begin
       ans[b[i].m]:=a[j].num;
       bo:=true;
       break;
     end;
    if bo=false then
     ans[b[i].m]:=-1;
  end;
  for i:=1 to q do writeln(ans[i]);

close(input);close(output);
end.
