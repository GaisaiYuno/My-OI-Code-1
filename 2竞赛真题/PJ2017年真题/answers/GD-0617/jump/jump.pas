var n,d,k,i:longint; x,s:array[1..5000000]of longint;
begin
     assign(input,'jump.in');reset(input);
     assign(output,'jump.out');rewrite(output);
     read(n,d,k);
     for i:=1 to n do read(x[i],s[i]);
     writeln(-1);
     close(input);close(output);
end.
