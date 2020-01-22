type arr=array[0..101,0..101] of longint;
var m,n,i,k,s,x,y,c,min:longint;
    a:arr;
begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
  read(m,n);
  for i:=1 to 100 do
    for k:=1 to 100 do
      a[i,k]:=3;
  for i:=1 to n do
  begin
    read(x,y,c);
    a[x,y]:=c;
  end;
  for i:=1 to m do
    for k:=1 to m do
       if (a[i-1,k-1]=3) and (a[i-1,k]=3) and (a[i-1,k+1]=3) and
         (a[i,k-1]=3) and (a[i,k+1]=3) and (a[i+1,k-1]=3) and
         (a[i+1,k]=3) and (a[i+1,k+1]=3) and ((a[i,k]=0) or (a[i,k]=1)) then
         begin writeln('-1'); close(input); close(output); exit; end;
  i:=1;
  k:=1;
  while (i<m) or (k<m) do
  begin
    if abs(a[i,k]-a[i,k+1])=0 then begin inc(k); end
    else if abs(a[i,k]-a[i+1,k])=0 then begin inc(i); end
    else if abs(a[i,k]-a[i,k+1])=1 then begin inc(s); inc(k); end
    else if abs(a[i,k]-a[i+1,k])=1 then begin inc(s); inc(i); end
    else if abs(a[i,k]-a[i,k+1])>1 then begin s:=s+2; a[i,k+1]:=a[i,k]; inc(k); end
    else if abs(a[i,k]-a[i+1,k])>1 then begin s:=s+2; a[i+1,k]:=a[i,k]; inc(i); end;
  end;
  writeln(s);
close(input);
close(output);
end.
