const
  dx:array[1..4]of integer=(0,0,1,-1);
  dy:array[1..4]of integer=(1,-1,0,0);
var
  n,m,i,j,k,c,ans:longint;
  a,d,b:array[0..100,0..100]of longint;

procedure bfs;
var
  i,j,k,x,y,h,t,e,f:longint;
  v:array[1..100000,1..3]of longint;
begin
  fillchar(v,sizeof(v),0);
  h:=0;t:=1;v[1,1]:=1;v[1,2]:=1;d[1,1]:=0;b[1,1]:=1;
  while h<t do
    begin
      inc(h);
      j:=v[h,1];k:=v[h,2];
      for i:=1 to 4 do
        begin
          x:=j+dx[i];y:=k+dy[i];
          if (x>0)and(y>0)and(x<=m)and(y<=m) then
            if v[h,3]=0 then
              begin
                if (a[x,y]=a[j,k])and(d[j,k]<d[x,y]) then
                  begin
                    d[x,y]:=d[j,k];
                    if b[x,y]=0 then
                      begin
                        b[x,y]:=1;
                        inc(t);
                        v[t,1]:=x;v[t,2]:=y;
                      end;
                  end else
                if (a[x,y]>0)and(d[j,k]+1<d[x,y]) then
                  begin
                    d[x,y]:=d[j,k]+1;
                    if b[x,y]=0 then
                      begin
                        b[x,y]:=1;
                        inc(t);
                        v[t,1]:=x;v[t,2]:=y;
                      end;
                  end else
                if (a[x,y]=0)and(d[j,k]+2<d[x,y]) then
                  begin
                    d[x,y]:=d[j,k]+2;
                    if b[x,y]=0 then
                      begin
                        inc(t);
                        b[x,y]:=t;
                        v[t,1]:=x;v[t,2]:=y;v[t,3]:=h;
                      end else
                      v[b[x,y],3]:=h;
                  end;
              end else
            begin
              e:=v[v[h,3],1];f:=v[v[h,3],2];
              if (a[x,y]=a[e,f])and(d[j,k]<d[x,y]) then
                  begin
                    d[x,y]:=d[j,k];
                    if b[x,y]=0 then
                      begin
                        b[x,y]:=1;
                        inc(t);
                        v[t,1]:=x;v[t,2]:=y;
                      end;
                  end;
                if (a[x,y]>0)and(d[j,k]+1<d[x,y]) then
                  begin
                    d[x,y]:=d[j,k]+1;
                    if b[x,y]=0 then
                      begin
                        b[x,y]:=1;
                        inc(t);
                        v[t,1]:=x;v[t,2]:=y;
                      end;
                  end;
            end;
        end;
      b[j,k]:=0;
    end;
end;

begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);rewrite(output);
  readln(m,n);
  for i:=1 to n do
    begin
      readln(j,k,c);
      a[j,k]:=c+1;
    end;
  fillchar(d,sizeof(d),$7f);
  bfs;
  if d[m,m]=d[0,0] then writeln(-1) else writeln(d[m,m]);
  close(input);close(output);
end.