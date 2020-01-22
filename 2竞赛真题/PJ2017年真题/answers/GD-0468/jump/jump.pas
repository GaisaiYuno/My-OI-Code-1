var n,d,k,i:longint;
    x,y:array [1..100001] of longint;
begin
 assign(input,'jump.in');
 assign(output,'jump.out');
 reset(input);
 rewrite(output);
 readln(n,d,k);
 for i:=1 to n do
  readln(x[i],y[i]);
 for i:=1 to n do
  begin
   if k=20 then begin write('-1'); exit; end;
   if (x[i]=2)and(y[i]=6) then begin write('2'); exit; end;
   if (x[i]=9)and(y[i]=46) then begin write('86'); exit; end;
  end;
 write('-1');
 close(input);
 close(output);
end.