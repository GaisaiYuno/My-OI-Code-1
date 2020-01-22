var
  a:array[0..101,0..101,1..2]of longint;
  b:array[0..10000,0..5]of 0..20000;
  n,m,i,j,x,y,c,l:longint;
  f:boolean;
begin
  assign(input,'chess.in'); reset(input);
  assign(output,'chess.out'); rewrite(output);
  readln(m,n);
  for i:=1 to m do
  begin
    a[0,i,1]:=3;
    a[i,0,1]:=3;
    a[m+1,i,1]:=3;
    a[i,m+1,1]:=3;
  end;
  for i:=1 to m do
    for j:=1 to m do a[i,j,1]:=2;
  for i:=1 to m do
    for j:=1 to m do a[i,j,2]:=20000;
  for i:=1 to n do
  begin
    readln(x,y,c);
    a[x,y,1]:=c;
  end;
  x:=0;
  l:=1;
  b[l,1]:=1;
  b[l,2]:=1;
  a[1,1,2]:=0;
  b[l,4]:=a[1,1,1];
  f:=false;
  repeat
    inc(x);
    if (b[x,1]=m)and(b[x,2]=m) then
    begin
      f:=true;
      break;
    end;
    if a[b[x,1],b[x,2],1]=2 then
    begin
      if (a[b[x,1]+1,b[x,2],1]=1)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-5)<a[b[x,1]+1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        a[b[x,1]+1,b[x,2],2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-5);
        b[l,4]:=1;
      end;
      if (a[b[x,1]-1,b[x,2],1]=1)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-5)<a[b[x,1]-1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]-1;
        b[l,2]:=b[x,2];
        a[b[x,1]-1,b[x,2],2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-5);
        b[l,4]:=1;
      end;
      if (a[b[x,1],b[x,2]+1,1]=1)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-5)<a[b[x,1],b[x,2]+1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]+1;
        a[b[x,1],b[x,2]+1,2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-5);
        b[l,4]:=1;
      end;
      if (a[b[x,1],b[x,2]-1,1]=1)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-5)<a[b[x,1],b[x,2]-1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]-1;
        a[b[x,1],b[x,2]-1,2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-5);
        b[l,4]:=1;
      end;
      if (a[b[x,1]+1,b[x,2],1]=0)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-4)<a[b[x,1]+1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        a[b[x,1]+1,b[x,2],2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-4);
        b[l,4]:=0;
      end;
      if (a[b[x,1]-1,b[x,2],1]=0)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-4)<a[b[x,1]-1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]-1;
        b[l,2]:=b[x,2];
        a[b[x,1]-1,b[x,2],2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-4);
        b[l,4]:=0;
      end;
      if (a[b[x,1],b[x,2]+1,1]=0)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-4)<a[b[x,1],b[x,2]+1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]+1;
        a[b[x,1],b[x,2]+1,2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-4);
        b[l,4]:=0;
      end;
      if (a[b[x,1],b[x,2]-1,1]=0)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-4)<a[b[x,1],b[x,2]-1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]-1;
        a[b[x,1],b[x,2]-1,2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-4);
        b[l,4]:=0;
      end;
    end;
    if (a[b[x,1],b[x,2],1]<>2) then
    begin
      if (a[b[x,1]+1,b[x,2],1]<2)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[x,1]+1,b[x,2],1])<a[b[x,1]+1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        a[b[x,1]+1,b[x,2],2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=a[b[l,1],b[l,2],1];
      end;
      if (a[b[x,1]-1,b[x,2],1]<2)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[x,1]-1,b[x,2],1])<a[b[x,1]-1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]-1;
        b[l,2]:=b[x,2];
        a[b[x,1]-1,b[x,2],2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=a[b[l,1],b[l,2],1];
      end;
      if (a[b[x,1],b[x,2]+1,1]<2)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[x,1],b[x,2]+1,1])<a[b[x,1],b[x,2]+1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]+1;
        a[b[x,1],b[x,2]+1,2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=a[b[l,1],b[l,2],1];
      end;
      if (a[b[x,1],b[x,2]-1,1]<2)and(a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[x,1],b[x,2]-1,1])<a[b[x,1],b[x,2]-1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]-1;
        a[b[x,1],b[x,2]-1,2]:=a[b[x,1],b[x,2],2]+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=a[b[l,1],b[l,2],1];
      end;
      if (a[b[x,1]+1,b[x,2],1]=2)and(a[b[x,1],b[x,2],2]+2<a[b[x,1]+1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        a[b[x,1]+1,b[x,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-0);
        b[l,4]:=4;
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        if a[b[x,1],b[x,2],2]+2+abs(b[x,4]-1)<a[b[l,1],b[l,2],2] then a[b[l,1],b[l,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=5;
      end;
      if (a[b[x,1]-1,b[x,2],1]=2)and(a[b[x,1],b[x,2],2]+2<a[b[x,1]-1,b[x,2],2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1]-1;
        b[l,2]:=b[x,2];
        a[b[x,1]+1,b[x,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-0);
        b[l,4]:=4;
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        if a[b[x,1],b[x,2],2]+2+abs(b[x,4]-1)<a[b[l,1],b[l,2],2] then a[b[l,1],b[l,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=5;
      end;
      if (a[b[x,1],b[x,2]+1,1]=2)and(a[b[x,1],b[x,2],2]+2<a[b[x,1],b[x,2]+1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]+1;
        a[b[x,1]+1,b[x,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-0);
        b[l,4]:=4;
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        if a[b[x,1],b[x,2],2]+2+abs(b[x,4]-1)<a[b[l,1],b[l,2],2] then a[b[l,1],b[l,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=5;
      end;
      if (a[b[x,1],b[x,2]-1,1]=2)and(a[b[x,1],b[x,2],2]+2<a[b[x,1],b[x,2]-1,2]) then
      begin
        inc(l);
        b[l,1]:=b[x,1];
        b[l,2]:=b[x,2]-1;
        a[b[x,1]+1,b[x,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-0);
        b[l,4]:=4;
        inc(l);
        b[l,1]:=b[x,1]+1;
        b[l,2]:=b[x,2];
        if a[b[x,1],b[x,2],2]+2+abs(b[x,4]-1)<a[b[l,1],b[l,2],2] then a[b[l,1],b[l,2],2]:=a[b[x,1],b[x,2],2]+2+abs(b[x,4]-a[b[l,1],b[l,2],1]);
        b[l,4]:=5;
      end;
      a[b[x,1],b[x,2],1]:=3;
    end;
  until x=l;
  for i:=1 to m do
  begin
    for j:=1 to m do write(a[i,j,2],' ');
    writeln;
  end;
  if f then writeln(a[m,m,2])
    else writeln(-1);
  close(input);
  close(output);
end.
