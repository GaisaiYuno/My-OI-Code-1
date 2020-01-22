program jump;
var
n,d,k,i:longint;
zhong,jian,last,qian:longint;
long,fen:array[1..500000]of longint;
begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);
  read(n,d,k);
  zhong:=0;
  last:=0;
  for i:=1 to n do
   begin
    readln(long[i],fen[i]);
    if fen[i]>0 then
    begin
    if ((long[i]-last)>jian) then begin
    jian:=long[i]-last;   last:=long[i]; end;
    zhong:=zhong+fen[i];
    end;
    end;
   if zhong<k then write('-1');
   if zhong=k then
   begin
    if jian>d then begin
     qian:=jian-d;
     write(qian);
    end  else
    write('0');
   end;
   if zhong>k then write('2');
close(input);
close(output);
end.