const
        u=99999999;
var
        a:array[1..100,1..100] of longint;
        f:array[1..100,1..100,0..1] of longint;
        w:array[1..4,1..2] of longint=((1,0),(0,1),(-1,0),(0,-1));
        x,y,z,i,j,m,n:longint;
        bz:boolean;
procedure dg(x,y,s,c,o:longint);
var
        p,q,l,k:longint;
begin
        if (x=n) and (y=n) then exit;
        for l:=1 to 4 do
        begin
                p:=x+w[l,1];
                q:=y+w[l,2];
                if (p<1) or (p>n) or (q<1) or (q>n) then continue;
                if a[p,q]=0 then
                begin
                        if (o=1) and (s+2<f[p,q,0]) then
                        begin
                                f[p,q,0]:=s+2;
                                dg(p,q,s+2,c,0);
                        end;
                end
                else begin
                        if a[p,q]=-c then k:=s+1 else k:=s;
                        if k<f[p,q,0] then f[p,q,0]:=k;
                        if k<f[p,q,1] then
                        begin
                                f[p,q,1]:=k;
                                dg(p,q,k,a[p,q],1);
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in'); reset(input);
        assign(output,'chess.out'); rewrite(output);
        readln(n,m);
        fillchar(a,sizeof(a),0);
        for i:=1 to n do
                for j:=1 to n do
                begin
                        f[i,j,1]:=u;
                        f[i,j,0]:=u;
                end;
        for i:=1 to m do
        begin
                readln(x,y,z);
                if z=0 then a[x,y]:=-1 else a[x,y]:=1;
        end;
        f[1,1,1]:=0;
        dg(1,1,0,a[1,1],1);
        if f[n,n,1]=u then
        begin
                if f[n,n,0]=u then writeln(-1) else writeln(f[n,n,0]);
        end
        else if f[n,n,0]=u then writeln(f[n,n,1])
        else if f[n,n,1]<f[n,n,0] then writeln(f[n,n,1]) else writeln(f[n,n,0]);
        close(input);
        close(output);
end.
