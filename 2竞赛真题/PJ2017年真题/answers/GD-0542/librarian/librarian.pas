program librarian(input,output);
var a,c,ans:array [0..1001] of string;
    b:array [0..1001] of longint;
    i,j,n,p,t,tt,ss:longint;
    ttt:string;
function find(x,y:string):boolean;
begin
  if (x='') or (y='') then begin find:=false; exit; end;
  if length(x)<length(y) then find:=true
  else
    if length(x)>length(y) then find:=false
    else
    if x[1]<y[1] then find:=true
    else
    if x[1]>y[1] then find:=false
    else
    begin
      delete(x,1,1);
      delete(y,1,1);
      find(x,y);
    end;
end;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
  readln(a[i]);
  for i:=1 to p do
  begin
    readln(c[i]);
    t:=pos(' ',c[i]);
    val(copy(c[i],1,t-1),b[i]);
    delete(c[i],1,t);
  end;

  for i:=1 to p do
  begin
    for j:=1 to n do
    begin
      tt:=pos(c[i],a[j]);
      ttt:=a[j];
      while tt<>0 do
      begin
        t:=tt;
        delete(ttt,tt,b[i]);
        inc(ss,b[i]);
        tt:=pos(c[i],ttt);
      end;
      t:=t+ss-b[i];
      ss:=0;
      if (t<>0) and (t+b[i]-1=length(a[j])) then
      if (find(a[j],ans[i])) or (ans[i]='') then ans[i]:=a[j];
      t:=0;
    end;
    if ans[i]='' then ans[i]:='-1';
  end;
  for i:=1 to p do
  writeln(ans[i]);
  close(input);
  close(output);
end.
