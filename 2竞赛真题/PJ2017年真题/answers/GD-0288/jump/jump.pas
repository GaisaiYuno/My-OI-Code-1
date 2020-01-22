var a,b,c,i,s:longint;
    q,p:array[1..10021] of longint;
begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
readln(a,b,c);
for i:=1 to a do
begin
        readln(q[i],p[i]);
        s:=s+p[i];
        if (q[i]>b) and (p[i]>c) then begin writeln('0');exit;end;

end;
if s<c then begin writeln('-1');exit;end;
for i:=1 to b do
        if (q[i]>b-i) and (p[i]>c) then begin writeln(i);exit;end;

write('-1');
close(input);
close(output);
end.
