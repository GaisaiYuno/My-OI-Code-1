var
  i,j,k,n,q:longint;
  s,s1,s2:string;
  b,f:boolean;
  a:array[0..1001]of string;
function cheak(a,b:string):boolean;
var i:longint;
begin
  for i:=1 to length(a) do
    if a[i]<b[i] then exit(true)
      else if a[i]>b[i] then exit(false);
  exit(false);
end;
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
    readln(s);
    j:=1;
    s2:='999999999';
    b:=false;
    while s[j]<>' ' do inc(j);
    delete(s,1,j);
    k:=length(s);
    for j:=1 to n do
      if k<=length(a[j]) then
      begin
        s1:=a[j];
        delete(s1,1,length(s1)-k);
        if s1=s then
          if length(a[j])<length(s2) then
          begin
            s2:=a[j];
            b:=true;
          end
            else
              if length(a[j])=length(s2) then
                if cheak(a[j],s2) then
                begin
                  s2:=a[j];
                  b:=true;
                end;
      end;
    if b then writeln(s2)
      else writeln('-1');
  end;
  close(input);
  close(output);
end.
