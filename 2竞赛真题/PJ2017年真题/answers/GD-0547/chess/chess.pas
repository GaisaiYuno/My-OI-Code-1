const   fx:array[1..4,1..2] of -1..1=((0,1),(0,-1),(1,0),(-1,0));
var     m,n,i,j,ans,tmp,x,y,c,xx,yy,k,sum:longint;
        a:array[1..100,1..100] of longint;
        f:array[1..100,1..100,0..1] of longint;
        d:array[1..500000,0..2] of longint;
function max(a,b:longint):longint;begin if a>b then max:=a else max:=b; end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        for i:=1 to 100 do
          for j:=1 to 100 do a[i,j]:=2;
        for i:=1 to n do
        begin
                readln(x,y,c);
                a[x,y]:=c;
        end;
        i:=0;
        j:=1;
        fillchar(f,sizeof(f),255);
        f[1,1,a[1,1]]:=0;
        d[1,0]:=2;
        d[1,1]:=1;
        d[1,2]:=1;
        while i<j do
        begin
                inc(i);
                if d[i,0]<>2 then a[d[i,1],d[i,2]]:=d[i,0];
                for k:=1 to 4 do
                begin
                        xx:=d[i,1]+fx[k,1];
                        yy:=d[i,2]+fx[k,2];
                        if (xx>0)and(xx<=m)and(yy>0)and(yy<=m)then
                        begin
                               if a[xx,yy]=2 then
                               begin
                                        if d[i,0]<>2 then continue
                                        else
                                        begin
                                                if (f[xx,yy,a[d[i,1],d[i,2]]]=-1)or(f[d[i,1],d[i,2],a[d[i,1],d[i,2]]]+2<f[xx,yy,a[d[i,1],d[i,2]]])then
                                                begin
                                                        inc(j);
                                                        d[j,0]:=a[d[i,1],d[i,2]];
                                                        d[j,1]:=xx;d[j,2]:=yy;
                                                        f[xx,yy,a[d[i,1],d[i,2]]]:=f[d[i,1],d[i,2],a[d[i,1],d[i,2]]]+2;
                                                end;
                                                if (f[xx,yy,1-a[d[i,1],d[i,2]]]=-1)or(f[d[i,1],d[i,2],a[d[i,1],d[i,2]]]+3<f[xx,yy,1-a[d[i,1],d[i,2]]])then
                                                begin
                                                        inc(j);
                                                        d[j,0]:=1-a[d[i,1],d[i,2]];
                                                        d[j,1]:=xx;
                                                        d[j,2]:=yy;
                                                        f[xx,yy,1-a[d[i,1],d[i,2]]]:=f[d[i,1],d[i,2],a[d[i,1],d[i,2]]]+3;
                                                end;
                                        end;
                               end
                               else
                               begin
                                        if a[d[i,1],d[i,2]]=a[xx,yy] then
                                        if (f[xx,yy,a[xx,yy]]=-1)or(f[xx,yy,a[xx,yy]]>f[d[i,1],d[i,2],a[xx,yy]])then
                                        begin
                                                inc(j);
                                                d[j,0]:=2;
                                                d[j,1]:=xx;d[j,2]:=yy;
                                                f[xx,yy,a[xx,yy]]:=f[d[i,1],d[i,2],a[xx,yy]];
                                        end;
                                        if a[d[i,1],d[i,2]]<>a[xx,yy] then
                                          if (f[xx,yy,a[xx,yy]]=-1)or(f[xx,yy,a[xx,yy]]>f[d[i,1],d[i,2],a[d[i,1],d[i,2]]]+1)then
                                        begin
                                                inc(j);
                                                d[j,0]:=2;
                                                d[j,1]:=xx;d[j,2]:=yy;
                                                f[xx,yy,a[xx,yy]]:=f[d[i,1],d[i,2],a[d[i,1],d[i,2]]]+1;
                                        end;
                               end;
                        end;
                end;
                if d[i,0]<>2 then a[d[i,1],d[i,2]]:=2;
        end;
        writeln(max(f[m,m,0],f[m,m,1]));
        close(input);close(output);

end.
