var
        a:array[0..500000,1..2] of longint;
        n,d,k,i,j,max,temp:longint;
function zh(x:longint):longint;
begin
        if x<k then exit(d-x)
        else exit(1);
end;
function pd(x,h,t,s:longint):boolean;
var
        i,j:longint;
begin
        if s>=k then exit(true);
        for i:=x+1 to n do
                if (a[i,1]-a[x,1]>=h) and (a[i,1]-a[x,1]<=t) then
                begin
                        if pd(i,h,t,s+a[i,2]) then exit(true);
                end else if (a[i,1]-a[x,1]>t) then exit(false);
        exit(false);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        max:=0;
        a[0,1]:=0;
        a[0,2]:=0;
        for i:=1 to n do
        begin
                read(a[i,1],a[i,2]);
                if a[i,2]>0 then max:=max+a[i,2];
        end;
        if max<k then
        begin
                writeln(-1);
                close(input);
                close(output);
                exit;
        end;
        i:=abs(a[1,1]-d);
        while pd(0,zh(i),i+d,0)=false do i:=i+10000;
        for j:=i-10000 to i do
                if pd(0,zh(j),j+d,0) then break;
        writeln(j);
        close(input);
        close(output);
end.
