var
        n,q,j,i,a,b,ans,e:longint;
        s:array[1..1000]of longint;
        y:array[1..8]of longint;
        k,l,p:string;
procedure kp(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;
        j:=r;
        mid:=s[(i+j) div 2];
        repeat
                while (s[i]<mid) do inc(i);
                while (s[j]>mid) do dec(j);
                if (i<=j) then
                begin
                        t:=s[i];
                        s[i]:=s[j];
                        s[j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if (i<r) then kp(i,r);
        if (l<j) then kp(l,j);
end;
function f(b:longint):longint;
var
        s:longint;
begin
        if (b<1) then exit(1);
        if (b=1) then exit(10) else
        begin
                s:=b div 2;
                if (b mod 2=1) then exit(f(s)*f(s)*a) else exit(f(s)*f(s));
        end;
end;
begin
        //assign(input,'librarian.in');reset(input);
        //assign(output,'librarian.out'); rewrite(output);
        readln(n,q);
        for i:=1 to n do
                readln(s[i]);
        kp(1,n);
        for i:=1 to q do
        begin
                readln(a,b);
                e:=f(a-1);
                ans:=-1;
                for j:=n downto 1 do
                begin
                        if (s[j] div e=0) then break;
                        str(s[j],k);
                        str(b,l);
                        p:=copy(k,length(k)-a+1,length(k));
                        if (p=l) then ans:=s[j];
                end;
                writeln(ans);
        end;
        close(input); close(output);
end.
