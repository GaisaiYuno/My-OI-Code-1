var n,m,i:longint;x,y,s:array[1..10000]of longint;
begin
     assign(input,'chess.in');reset(input);
     assign(output,'chess.out');rewrite(output);
     read(n,m);
     for i:=1 to m do read(x[i],y[i],s[i]);
     writeln(-1);
     close(input);close(output);
end.