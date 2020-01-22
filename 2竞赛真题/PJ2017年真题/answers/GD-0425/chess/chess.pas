var
        a:array [0..101,0..101] of longint;
        b:array [0..101,0..101] of boolean;
        n,i,j,m,k,ans,tot,t,x,y,c:longint;
        pd:boolean;
procedure dg(i,j,s:longint;p:boolean);
        var
                f:longint;
        begin
                if (i=m) and (j=m) then
                begin
                        if s<ans then ans:=s;
                        pd:=true;
                        exit;
                end;
                if (s>=ans) and (pd=true) then exit;
                b[i,j]:=true;
                if (b[i+1,j]=false) then
                begin
                        if i+1<=m then
                        begin
                                if a[i+1,j]<>0 then
                                begin
                                        if a[i,j]=a[i+1,j] then dg(i+1,j,s,false)
                                        else dg(i+1,j,s+1,false);

                                end
                                else if p=false then
                                begin
                                        f:=a[i+1,j];
                                        a[i+1,j]:=1;
                                        if a[i,j]=1 then dg(i+1,j,s+2,true)
                                        else dg(i+1,j,s+3,true);
                                        a[i+1,j]:=2;
                                        if a[i,j]=2 then dg(i+1,j,s+2,true)
                                        else dg(i+1,j,s+3,true);
                                        a[i+1,j]:=f;
                                end;
                        end;
                end;
                if (b[i-1,j]=false) then
                begin
                        if i-1>=1 then
                        begin
                                if a[i-1,j]<>0 then
                                begin
                                        if a[i,j]=a[i-1,j] then dg(i-1,j,s,false)
                                        else dg(i-1,j,s+1,false);
                                end
                                else if p=false then
                                begin
                                        f:=a[i-1,j];
                                        a[i-1,j]:=1;
                                        if a[i,j]=1 then dg(i-1,j,s+2,true)
                                        else dg(i-1,j,s+3,true);
                                        a[i-1,j]:=2;
                                        if a[i,j]=2 then dg(i-1,j,s+2,true)
                                        else dg(i-1,j,s+3,true);
                                        a[i-1,j]:=f;
                                end;
                        end;
                end;
                if (b[i,j-1]=false) then
                begin
                        if j-1>=1 then
                        begin
                                if a[i,j-1]<>0 then
                                begin
                                        if a[i,j]=a[i,j-1] then dg(i,j-1,s,false)
                                        else dg(i,j-1,s+1,false);
                                end
                                else if p=false then
                                begin
                                        f:=a[i,j-1];
                                        a[i,j-1]:=1;
                                        if a[i,j]=1 then dg(i,j-1,s+2,true)
                                        else dg(i,j-1,s+3,true);
                                        a[i,j-1]:=2;
                                        if a[i,j]=2 then dg(i,j-1,s+2,true)
                                        else dg(i,j-1,s+3,true);
                                        a[i,j-1]:=f;
                                end;
                        end;
                end;
                if (b[i,j+1]=false) then
                begin
                        if j+1<=m then
                        begin
                                if a[i,j+1]<>0 then
                                begin
                                        if a[i,j]=a[i,j+1] then dg(i,j+1,s,false)
                                        else dg(i,j+1,s+1,false);
                                end
                                else if p=false then
                                begin
                                        f:=a[i,j+1];
                                        a[i,j+1]:=1;
                                        if a[i,j]<>1 then dg(i,j+1,s+3,true)
                                        else dg(i,j+1,s+2,true);
                                        a[i,j+1]:=2;
                                        if 2<>a[i,j] then dg(i,j+1,s+3,true)
                                        else dg(i,j+1,s+2,true);
                                        a[i,j+1]:=f;
                                end;
                        end;
                end;
                b[i,j]:=false;
        end;
begin
        assign(input,'chess.in'); reset(input);
        assign(output,'chess.out'); rewrite(output);


        readln(m,n);
        pd:=false;
        ans:=maxlongint;
        for i:=1 to n do
        begin
                readln(x,y,c);
                a[x,y]:=c+1;
        end;
        dg(1,1,0,false);
        if pd=true then writeln(ans)
        else writeln(-1);

        close(input); close(output);
end.
