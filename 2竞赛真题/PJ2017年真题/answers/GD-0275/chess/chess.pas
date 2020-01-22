var
        a:array[0..1001,0..1001]of longint;
        bj:array[0..1001,0..1001]of boolean;
        min:array[0..1001,0..1001]of longint;
        k,m,n,y,c,ans,x1,k1:longint;
{procedure dg(i,j,x:longint;bz:boolean);
var
        z:longint;
begin
        if (i>m)and (j>m) then
        begin
                if x<min[m,m] then min[m,m]:=x;
                exit;
        end;
        bj[i,j]:=true;
        if i-1>=1 then
        begin
                if not((a[i-1,j]=0) and bz) and bj[i-1,j]=false then
                begin
                        if a[i-1,j]=0 then dg(i-1,j,x+2,true)
                        else if a[i-1,j]<>a[i,j] then dg(i-1,j,x+1,false)
                        else dg(i-1,j,x,false);
                        bj[i-1,j]:=true;
                end;
        end;
        if i+1<=m then
        begin
                if not((a[i+1,j]=0) and bz)and bj[i+1,j]=false then
                begin
                        if a[i+1,j]=0 then dg(i+1,j,x+2,true)
                        else if a[i+1,j]<>a[i,j] then dg(i+1,j,x+1,false)
                        else dg(i+1,j,x,false);
                        bj[i+1,j]:=true;
                end;
        end;
        if j-1>=1 then
        begin
                if not((a[i,j-1]=0) and bz)and bj[i,j-1]=false then
                begin
                        if a[i,j-1]=0 then dg(i,j-1,x+2,true)
                        else if a[i,j-1]<>a[i,j] then dg(i,j-1,x+1,false)
                        else dg(i,j-1,x,false);
                        bj[i,j-1]:=true;
                end;
        end;
        if j+1<=m then
        begin
                if not((a[i,j+1]=0) and bz)and bj[i,j+1]=false then
                begin
                        if a[i,j+1]=0 then dg(i,j+1,x+2,true)
                        else if a[i,j+1]<>a[i,j] then dg(i,j+1,x+1,false)
                        else dg(i,j+1,x,false);
                        bj[i,j+1]:=true;
                end;
        end;
end;}
begin
        assign(input,'chess.in');assign(output,'chess.out');
        reset(input);rewrite(output);
        readln(m,n);
        for k:=1 to m do
                for k1:=1 to n do
                begin
                        bj[k,k1]:=false;
                        min[k,k1]:=maxlongint;
                end;

        for k:=1 to n do
        begin
                readln(x1,y,c);
                a[x1,y]:=c;
        end;
        bj[1,1]:=true;
        //dg(1,1,0,false);
        writeln('-1');
end.
