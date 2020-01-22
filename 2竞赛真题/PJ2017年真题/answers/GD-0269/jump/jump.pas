var
        n,k,d,i,sum,max:longint;
        x,s:array[0..500000]of longint;
        bz:boolean;
procedure qsort(l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=x[(l+r)div 2];
        repeat
                while x[i]<mid do
                        inc(i);
                while x[j]>mid do
                        dec(j);
                if i<=j then
                begin
                        x[0]:=x[i];
                        x[i]:=x[j];
                        x[j]:=x[0];
                        s[0]:=s[i];
                        s[i]:=s[j];
                        s[j]:=s[0];
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then
                qsort(l,j);
        if i<r then
                qsort(i,r);
end;
function dg(g,h,l:longint):boolean;
var
        i,j:longint;
begin
        if h>=k then
        begin
                bz:=true;
                exit;
        end;
        if l>=max then
                exit;
        if g<d then
        begin
                for i:=d-g to d+g do
                begin
                        for j:=1 to n do
                        begin
                                if x[j]=l+i then
                                begin
                                        dg(g,h+s[j],x[j]);
                                        if bz then
                                                exit;
                                        break;
                                end;
                                if x[j]>l+i then
                                        break;
                        end;
                end;
        end
        else
        begin
                for i:=1 to d+g do
                begin
                        for j:=1 to n do
                        begin
                                if x[j]=l+i then
                                begin
                                        dg(g,h+s[j],x[j]);
                                        if bz then
                                                exit;
                                        break;
                                end;
                                if x[j]>l+i then
                                        break;
                        end;
                end;
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        max:=-maxlongint;
        for i:=1 to n do
        begin
                readln(x[i],s[i]);
                if s[i]>0 then
                        sum:=sum+s[i];
                if max<x[i] then
                        max:=x[i];
        end;
        if sum<k then
                writeln('-1')
        else
        begin
                qsort(1,n);
                for i:=1 to max-1-d do
                begin
                        bz:=false;
                        dg(i,0,0);
                        if bz then
                        begin
                                writeln(i);
                                close(input);close(output);
                                halt;
                        end;
                end;
        end;
        close(input);close(output);
end.