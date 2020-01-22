var n,d,k,i,max,g,s1,s2,q,ans:longint;
    s,x,o,b:array[1..500000] of longint;
procedure hm1(d,g:longint);
var i,s:longint;
begin
  i:=d-g;
  while i<>d+g do
   begin
     inc(s);
     o[s]:=i;
     inc(i);
   end;
end;
procedure hm2(d,g:longint);
var i,s:longint;
begin
  i:=1;
  while i<>d+g do
   begin
     inc(s);
     o[s]:=i;
     inc(i);
   end;
end;
begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
   begin
     readln(s[i],x[i]);
     if x[i]>0 then max:=max+x[i];
     ans:=ans+x[i];
   end;
  if ans>k then begin
                  writeln(0);
                  halt;
                  close(input);
                  close(output);
                end
            else writeln(-1);
  {if max<k then begin
                  writeln(-1);
                  halt;
                  close(input);
                  close(output);
                end;
  for i:=1 to n do
   if x[i]>0 then begin s1:=s2; s2:=s[i]; inc(q); b[q]:=abs(s2-s1); end;
  for g:=1 to n do
   begin
     if g<d then hm1(d,g);
     if g>=d then hm2(d,g);

   end;}
close(input);
close(output);
end.
