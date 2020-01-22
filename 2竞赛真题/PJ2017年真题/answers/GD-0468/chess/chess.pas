var p,s,m,n,i,j,ans,k,f:longint;
    a:array [1..101,1..101] of longint;
    x,y,c:array [1..10001] of longint;
begin
 assign(input,'chess.in');
 assign(output,'chess.out');
 reset(input);
 rewrite(output);
 readln(m,n);
 f:=1;
 for i:=1 to n do
  readln(x[i],y[i],c[i]);
 for i:=1 to m do
  for j:=1 to m do
   a[i,j]:=2;
 for k:=1 to n do
  begin
   for i:=1 to m do
    for j:=1 to m do
     if (i=x[k])and(j=y[k]) then a[x[k],y[k]]:=c[k];
  end;
 i:=1; j:=1;
 repeat
  repeat
   if (i=m)and(j=m) then break;

   if (a[i,j]=a[i,j+1])and(a[i,j+1]<>2)and(j<>m) then begin if f=0 then a[i,j]:=2;inc(j); break; f:=1;end
    else if (a[i,j]=a[i+1,j])and(a[i+1,j]<>2)and(i<>m) then begin if f=0 then a[i,j]:=2;inc(i); break; f:=1;end;

   if (a[i,j]<>a[i,j+1])and(a[i,j+1]<>2)and(j<>m) then begin if f=0 then a[i,j]:=2;inc(j); inc(ans); break;f:=1;end
    else if (a[i,j]<>a[i+1,j])and(a[i+1,j]<>2)and(i<>m) then begin if f=0 then a[i,j]:=2;inc(i); inc(ans); break;f:=1;end;

   if f=1 then if (a[i,j]<>a[i,j+1])and(a[i,j+1]=2)and(j<>m) then if a[i,j]=0 then begin a[i,j+1]:=0; ans:=ans+2; break;f:=0;end
    else begin a[i,j+1]:=1; ans:=ans+2; break;f:=0;end;

   if f=1 then if (a[i,j]<>a[i+1,j])and(a[i,j+1]=2)and(i<>m) then if a[i,j]=0 then begin a[i+1,j]:=0; ans:=ans+2; break;f:=0;end
    else begin a[i+1,j]:=1; ans:=ans+2; break; f:=0; end;
   inc(p);
   if p>10000000 then begin write('-1'); exit; end;
  until s=1;
 until (i=m)and(j=m);
 write(ans);
 close(input);
 close(output);
end.
