var
        a,b,c,d,i,ans:longint;
        v:array[0..500000,1..2]of longint;
        r,r1:array[0..500000]of longint;
function max(a,b:longint):longint;
begin
        if a>b then
                exit(a)
        else
                exit(b);
end;
function pd(s:longint):boolean;
var
        l,r2,ans,ans1,answ:int64;
        i,j:longint;
        p:boolean;
begin
        l:=max(b-s,0);
        r2:=b+s;
        i:=0;
        ans:=0;
        ans1:=-maxlongint;
        while ans<c do
        begin
                j:=i;
                if j=a then
                        exit(false);
                p:=false;
                while true do
                begin
                        if (r[j]=j)or(r[j]=0) then
                                break;
                        j:=r[j];
                        if (v[j,1]-v[i,1]>r2)then
                                break;
                        if (v[j,1]-v[i,1]<=r2)and(v[j,1]-v[i,1]>=l) then
                        begin
                                p:=true;
                                break;
                        end;
                        if (j=a) then
                                break;
                end;
                if p=true then
                begin
                        i:=j;
                        ans:=ans+v[i,2];
                        continue;
                end;
                j:=i;
                p:=false;
                while true do
                begin
                        if (r1[j]=j)or(r1[j]=0) then
                                break;
                        j:=r1[j];
                        if (v[j,1]-v[i,1]>r2)then
                                break;
                        if (v[j,1]-v[i,1]<=r2)and(v[j,1]-v[i,1]>=l) then
                        begin
                                ans1:=max(ans1,v[j,2]);
                                answ:=j;
                                p:=true;
                        end;
                        if (j=a)then
                                break;
                end;
                if p=true then
                begin
                        i:=answ;
                        ans:=ans+ans1;
                end
                        else
                exit(false);
        end;
        exit(true);
end;
procedure ss(l,r:longint);
var
        mid:longint;
begin
        if (l=r) then
        begin
                writeln(l);
                close(input);
                close(output);
                halt;
        end;
        mid:=(l+r)div 2;
        if pd(mid)=true then
                ss(l,mid)
        else
                ss(mid+1,r);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(a,b,c);
        for d:=1 to a do
                readln(v[d,1],v[d,2]);
        for d:=1 to a do
                if v[d,2]>0 then
                begin
                        r[d-1]:=d;
                        ans:=ans+v[d,2];
                end
                        else
                r1[d-1]:=d;
        if ans<c then
        begin
                writeln(-1);
                close(input);
                close(output);
                halt;
        end;
        for i:=a-1 downto 0 do
        begin
                if r[i]=0 then
                        r[i]:=r[i+1];
                if r1[i]=0 then
                        r1[i]:=r1[i+1];
        end;
        ss(0,1000000000);
        close(input);
        close(output);
end.
