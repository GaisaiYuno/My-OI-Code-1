const
    dx:array [1..4] of integer=(1,-1,0,0);
    dy:array [1..4] of integer=(0,0,-1,1);
var
    f:array [0..101,0..101,0..1] of longint;
    a,b:array [0..101,0..101] of longint;
    i,j,n,m,p,q,pq:longint;

function check(aa,bb:longint):boolean;
begin
    if (aa<1) or (aa>n) or (bb<1) or (bb>n) then exit(false);
    exit(true);
end;

procedure dfs(dep,x,y,rp:longint);
var
    i,j,k,l,xx,yy:longint;
begin
    j:=a[x,y];
    k:=rp;
    if b[x,y]<>1 then a[x,y]:=2
                 else k:=1;
    for i:=1 to 4 do
      begin
          xx:=x+dx[i]; yy:=y+dy[i];
          if check(xx,yy) then
             begin
                   if a[xx,yy]<>2 then
                     begin
                          if j=a[xx,yy] then
                            begin
                                if f[xx,yy,a[xx,yy]]>f[x,y,j]
                                then begin
                                          f[xx,yy,a[xx,yy]]:=f[x,y,j];
                                          dfs(f[x,y,j],xx,yy,k);
                                     end;
                            end
                          else begin
                                    if f[xx,yy,a[xx,yy]]>f[x,y,j]+1
                                    then begin
                                               f[xx,yy,a[xx,yy]]:=f[x,y,j]+1;
                                               dfs(f[x,y,j]+1,xx,yy,k);
                                         end;
                               end;
                     end
                     else if k=1 then
                        begin
                              for l:=0 to 1 do
                                if f[xx,yy,l]>f[x,y,j]+2+abs(j-l) then
                               begin
                                    f[xx,yy,l]:=f[x,y,j]+2+abs(j-l);
                                    a[xx,yy]:=l;
                                    dfs(f[x,y,j]+2+(j-l),xx,yy,0);
                               end;
                        end;
             end;
      end;
end;

begin
    assign(input,'chess.in'); reset(input);
    assign(output,'chess.out'); rewrite(output);
    readln(n,m);
    for i:=1 to n do
      for j:=1 to n do
        begin
             f[i,j,0]:=maxlongint;
             f[i,j,1]:=maxlongint;
             a[i,j]:=2;
        end;

    for i:=1 to m do
      begin
           readln(p,q,pq);
           a[p,q]:=pq;
           b[p,q]:=1;
      end;

    f[1,1,a[1,1]]:=0;

    dfs(0,1,1,1);
    if (f[n,n,0]=maxlongint) and (f[n,n,1]=maxlongint)
       then writeln('-1')
       else if f[n,n,0]>f[n,n,1]
                then writeln(f[n,n,1])
                else writeln(f[n,n,0]);
    close(input); close(output);
end.
