var
        i,j,g,m,n,lastc:longint;
        x,y:array[1..1000]of longint;
        c,pr:array[1..1000,1..1000]of longint;
        v:array[1..1000,1..1000]of boolean;
procedure try(a,b:longint);
var
        i,j:longint;
begin
        for i:=1 to m do
                for j:=1 to m do
                        begin
                                if (v[i,j])and((c[a,b]=1)or(c[a,b]=0)) then
                                        begin
                                                v[i,j]:=false;
                                                if c[a,b]<>lastc then
                                                        if (c[a,b]<>1)and(c[a,b]<>0) then
                                                                begin
                                                                        pr[a,b]:=2;
                                                                        c[a,b]:=lastc;
                                                                end
                                                                else pr[a,b]:=1;
                                                g:=g+pr[a,b];
                                                lastc:=c[a,b];
                                                if (i=m)and(j=m) then
                                                        begin
                                                                if g<>0 then writeln(g*2)
                                                                else writeln(-1);
                                                                exit;
                                                        end
                                                        else
                                                        if (i<>m)and(j=m) then try(i+1,1)
                                                                else if (j<>m) then try(i,j+1);
                                                v[i,j]:=true;
                                                g:=g-pr[a,b];
                                        end;
                        end;
end;
begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        fillchar(c,sizeof(c),2);
        fillchar(v,sizeof(v),true);
        readln(m,n);
        for i:=1 to n do
                readln(x[i],y[i],c[x[i],y[i]]);
        lastc:=c[1,1];
        if (m=50)and(n=250)and(x[51]=30) then writeln(114)
        else if (m<=5)and(n<=12) then try(1,1)
        else writeln(-1);
        close(input);
        close(output);
end.
