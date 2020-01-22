var i,j,k,l,n,m,x,y,ans,t,t1,s:longint;
    f:array[1..4,1..2] of longint=((0,-1),(-1,0),(0,1),(1,0));
    a,b,v,c:array[1..100,1..100] of longint;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  read(n,m);
  for i:=1 to m do
  begin
        read(k,l,j);
        a[k,l]:=j+1;
  end;
  t:=1;
  t1:=t;
  for i:=1 to m do
    for j:=1 to m do c[i,j]:=1000;
  b[1,1]:=1;
  b[1,2]:=1;
  b[1,3]:=a[1,1];
  b[1,4]:=0;
  ans:=maxlongint;
  v[1,1]:=1;
  for i:=2 to 100 do b[i,4]:=1000;
  while (true) do
  begin
         if (s=t)then break;
        s:=t;
        for i:=t1 to t do
        begin
                for j:=1 to 4 do
                begin
                        x:=b[i,1]+f[j,1];
                        y:=b[i,2]+f[j,2];
                        if (x<=n)and(y<=n)and(x>0)and(y>0)and(v[x,y]=0) then
                        if (b[i,4]<=c[b[i,1],b[i,2]]) then
                        if (b[i,3]=a[x,y])and(a[x,y]>0) then
                        begin
                          t:=t+1;
                          b[t,1]:=x;
                          b[t,2]:=y;
                          b[t,3]:=a[x,y];
                          b[t,4]:=b[i,4];
                          b[t,5]:=0;
                          v[b[i,1],b[i,2]]:=1;
                        end
                        else if (b[i,3]<>a[x,y])and(a[x,y]>0) then
                        begin
                          t:=t+1;
                          b[t,1]:=x;
                          b[t,2]:=y;
                          b[t,3]:=a[x,y];
                          b[t,4]:=b[i,4]+1;
                          if (b[t,4]<c[x,y]) then c[x,y]:=b[t,4];
                          b[t,5]:=0;
                          v[b[i,1],b[i,2]]:=1;
                        end
                        else if (a[x,y]=0)and(b[i,5]=0)then
                          begin
                            t:=t+1;
                            b[t,1]:=x;
                            b[t,2]:=y;
                            b[t,3]:=b[i,3];
                            b[t,4]:=b[i,4]+2;
                            if (b[t,4]<c[x,y]) then c[x,y]:=b[t,4];
                            b[t,5]:=1;
                            v[x,y]:=1;
                          end;
                       if(b[t,4]<ans)and(x=n)and(y=n) then ans:=b[t,4];
                end;
        end;
        if (t1=1) then t1:=t1+1
        else t1:=s+1;
  end;
  if (ans<>maxlongint) then write(ans)
  else write(-1);
  close(input);
  close(output);
end.