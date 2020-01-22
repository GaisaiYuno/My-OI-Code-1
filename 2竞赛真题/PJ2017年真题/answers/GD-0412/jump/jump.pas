var n,d,k,i,g,j,q,p,c,sum:longint;
    t,x,s,u:array[0..500001]of longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
    begin
      readln(x[i],s[i]);
      if s[i]>0 then inc(sum,s[i]);
    end;
  for i:=1 to n do u[i]:=x[i];
  for i:=2 to n do dec(x[i],u[i-1]);
  if sum<k then
    begin
      writeln(-1);
      halt;
    end;
  g:=0;
  while g<1000000000 do
    begin
      fillchar(t,sizeof(t),0);
      q:=0;
      for i:=1 to n do
        if((g<d)and(x[i]>=d-g)and(x[i]<=d+g))or((g>=d)and(x[i]<=d+g))then
          begin
            inc(q);
            t[q]:=s[i];
          end;
      for i:=1 to q-1 do
        for j:=i+1 to q do
          if t[i]<t[j]then
            begin
              t[0]:=t[i];
              t[i]:=t[j];
              t[j]:=t[0];
            end;
      c:=0;
      p:=0;
      while(c<k)and(p<=q)do begin inc(c,t[p]); inc(p)end;
      if c>=k then
        begin
          writeln(g);
          halt;
        end;
      inc(g);
    end;
  close(input);
  close(output);
end.
