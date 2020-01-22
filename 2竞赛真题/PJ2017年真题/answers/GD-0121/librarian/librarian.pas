var n,m,i,j,k:longint;
    z:array[0..1000]of int64;
    x:array[1..10,0..1000] of longint;
procedure ss(l:longint;r:longint);
var i,j,k,a:int64;
begin
        i:=l;
        j:=r;
        k:=z[(l+r) div 2];
        while(i<j) do begin
                while(z[i]<k) do inc(i);
                while(z[j]>k) do dec(j);
                if(i<=j) then begin
                        a:=z[i];
                        z[i]:=z[j];
                        z[j]:=a;
                        inc(i);
                        dec(j);
                end;
        end;
        if(i<r) then ss(i,r);
        if(j>l) then ss(l,j);
end;

procedure make(l:longint);
var i,k:int64;
begin
        k:=z[l];
        i:=0;
        while(k<>0) do begin
                inc(i);
                x[i,l]:=k mod 10;
                k:=k div 10
        end;
end;

function judge():int64;
var i,j:longint;
    p:boolean;
begin
        for i:=1 to n do begin
                p:=true;
                for j:=1 to k do
                        if(x[j,0]<>x[j,i]) then begin
                                p:=false;
                                break;
                        end;
                if(p)
                        then exit(z[i]);
        end;
        exit(-1);
end;

begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out') ;rewrite(output);
        readln(n,m);
        for i:=1 to n do
                readln(z[i]);
        ss(1,n);
        for i:=1 to n do
                make(i);
        for i:=1 to m do begin
                readln(k,z[0]);
                make(0);
                writeln(judge);
        end;
        close(input);
        close(output);
end.


