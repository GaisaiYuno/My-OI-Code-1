var
        c:array[0..101,0..101]of longint;
        d:array[0..101,0..101]of longint;
        t:array[1..4,1..2]of longint;
        n,m,i,j,a1,b1,ans:longint;
function bb(aaa,bbb:longint):longint;
begin
        if aaa<bbb then
                bb:=aaa
        else
                bb:=bbb;

end;
procedure dg(x,y,k:longint;bz:boolean);
var
        l,a,b,df,qb,gv:longint;
begin
        for l:=1 to 4 do
                begin
                        a:=x+t[l,1];
                        b:=y+t[l,2];
                        if (a>=1)and(a<=m)and(b>=1)and(b<=m)then
                                if (c[a,b]<>0)or(bz=true)then
                                        begin
                                                if c[a,b]<>0 then
                                                        begin
                                                                df:=k+abs(c[a,b]-c[x,y]);
                                                                qb:=c[x,y];
                                                                if (df<d[a,b])then
                                                                        begin
                                                                                if  bz=false then
                                                                                        c[x,y]:=0;
                                                                                d[a,b]:=df;
                                                                                dg(a,b,df,true);
                                                                                if bz=false then
                                                                                        c[x,y]:=qb;
                                                                        end;
                                                        end
                                                else
                                                        begin
                                                                df:=k+2;
                                                                if df<d[a,b]then
                                                                        begin
                                                                                d[a,b]:=df;
                                                                                c[a,b]:=c[x,y];
                                                                                dg(a,b,df,false);
                                                                        end;
                                                        end;
                                        end;
                end;
        if bz=false then
                c[x,y]:=0;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        read(m,n);
        for i:=1 to 4 do
                begin
                        t[i,1]:=0;
                        t[i,2]:=0;
                end;
        t[1,1]:=-1;
        t[2,2]:=1;
        t[3,1]:=1;
        t[4,2]:=-1;
        for i:=1 to m do
                for j:=1 to m do
                        begin
                                d[i,j]:=maxlongint;
                                c[i,j]:=0;
                        end;
        for i:=1 to n do
                begin
                        read(a1,b1);
                        read(c[a1,b1]);
                        inc(c[a1,b1]);
                end;
        dg(1,1,0,true);
        ans:=d[m,m];
        if ans=maxlongint then
                writeln('-1')
        else
                writeln(ans);
        close(input);
        close(output);
end.
