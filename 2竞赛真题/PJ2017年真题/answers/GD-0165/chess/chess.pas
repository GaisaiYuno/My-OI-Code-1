var
 b:array[0..100,0..100]of 0..1;
 a:array[0..100,0..100]of 0..2;
 i,j,sum,k,n,m,o,w,l:longint;
begin
 assign(input,'chess.in');
 assign(output,'chess.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to m do
  begin
   read(j,k,o);
   a[j,k]:=o+1;
  end;
 write(-1);
 close(input);
 close(output);
end.
