var
  n,q,i,j,k,c,d:longint;
  a:array[1..1000]of string;
  s:string;

function min(a,b:string):boolean;
var
  x,y:longint;
begin
  val(a,x);
  val(b,y);
  if x<y then exit(true) else exit(false);
end;

function max(a,b:string):boolean;
var
  x,y:longint;
begin
  val(a,x);
  val(b,y);
  if x>y then exit(true) else exit(false);
end;

procedure qsort(l,r:longint);
var
  i,j:longint;
  t,k:string;
begin
  if l>=r then exit;
  i:=l;j:=r;
  k:=a[(l+r) div 2];
  repeat
    while min(a[i],k) do inc(i);
    while max(a[j],k) do dec(j);
    if i<=j then
      begin
        t:=a[i];a[i]:=a[j];a[j]:=t;
        inc(i);dec(j);
      end;
  until i>j;
  qsort(i,r);
  qsort(l,j);
end;

begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);rewrite(output);
  readln(n,q);
  for i:=1 to n do
      readln(a[i]);
  qsort(1,n);
  for i:=1 to q do
    begin
      readln(s);
      delete(s,1,pos(' ',s));
      c:=0;
      for j:=1 to n do
        if length(a[j])>=length(s) then
          begin
            k:=length(a[j]);d:=length(s);
            while d>0 do
              if s[d]=a[j][k] then begin dec(d);dec(k);end else break;
            if d=0 then begin
                writeln(a[j]);
                c:=1;
                break;
              end;
          end;
      if c=0 then writeln('-1');
    end;
  close(input);close(output);
end.