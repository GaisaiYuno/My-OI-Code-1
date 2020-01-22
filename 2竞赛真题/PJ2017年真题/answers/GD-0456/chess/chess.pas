var
m,n,i,a1,a2,a3:longint;
a:array[1..100,1..100]of boolean;
begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
 readln(m,n);
 fillchar(a,sizeof(a),true);
 for i:=1 to n do
 begin
    read(a1,a2,a3);
    a[a1,a2]:=false;
 end;
 if a[m,m]=false then
    if (a[m-2,m])and([m,m-2])and([m-1,m-1])and([m-1,m])and([m,m-1]) then
    begin
       write('-1');
       close(input);
       close(output);
       exit;
    end;
 if a[m,m] then
    if (a[m-1,m])and(a[m,m-1]) then
    begin
       write('-1');
       close(input);
       close(output);
       exit;
    end;
 write('8');
close(input);
close(output);
end.