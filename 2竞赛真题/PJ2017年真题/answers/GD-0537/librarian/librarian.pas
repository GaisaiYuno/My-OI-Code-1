 var a,b,c,d,e,f,h1:longint;
     g1:boolean;
     g:array [1..1000] of longint;
     h:array [1..1000,1..2] of longint;
begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);
  readln(e,f);
  for a:=1 to e do readln(g[a]);
  for a:=1 to e-1 do for b:=a+1 to e do if g[a]>g[b] then begin
    c:=g[a];g[a]:=g[b];g[b]:=c;
  end;
  for a:=1 to f do readln(h[a,1],h[a,2]);
  for a:=1 to f do begin
    g1:=true;
    for b:=1 to e do begin
      d:=0;
      h1:=1;
      for c:=1 to h[a,1] do h1:=h1*10;
      for c:=h[a,1] downto 1 do begin
        d:=g[b] mod h1 div (h1 div 10)+d*10;
        h1:=h1 div 10;
      end;
      if d=h[a,2] then begin g1:=false;writeln(g[b]);break;end;
    end;
    if g1=true then writeln('-1');
  end;
close(input);
close(output);
end.