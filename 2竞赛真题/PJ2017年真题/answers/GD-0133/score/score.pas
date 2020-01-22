var
 ans,n,m,k:longint;
begin
 assign(input,'score.in');
 assign(output,'score.out');
 reset(input);
 rewrite(output);
 read(n,m,k);
 n:=n div 5;
 m:=(m*3) div 10;
 k:=k div 2;
 ans:=n+m+k;
 writeln(ans);
 close(input);
 close(output);
end.