program score;
var     i,j,k,long,n,m,bo,bo2:longint;
        nu:array[0..100001]of longint;
        s:array[0..100001]of string;
        q:string;
procedure kp(l,r:longint);
var     i,j,m:longint;
begin
        i:=l;
        j:=r;
        m:=nu[(l+r)div 2];
        repeat
                while nu[i]<m do
                        i:=i+1;
                while nu[j]>m do
                        j:=j-1;
                if i<=j then
                begin
                        nu[0]:=nu[i];
                        nu[i]:=nu[j];
                        nu[j]:=nu[0];
                        i:=i+1;
                        j:=j-1;
                end;
        until i>j;
        if i<r then kp(i,r);
        if j>l then kp(l,j);
end;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        readln(n,m);
        for i:=1 to n do
                readln(nu[i]);
        kp(1,n);
        for i:=1 to n do
        begin
                str(nu[i],s[i]);
                nu[i]:=length(s[i]);
        end;
        for i:=1 to m do
        begin
                readln(long,q);
                delete(q,1,1);
                bo2:=0;
                for j:=1 to n do
                begin
                        if nu[j]>=long then
                        begin
                                bo:=0;
                                for k:=1 to long do
                                        if (q[k]<>s[j][nu[j]-long+k])then
                                        begin
                                                bo:=1;
                                                break;
                                        end;
                                if bo=0 then
                                begin
                                        writeln(s[j]);
                                        bo2:=1;
                                        break;
                                end;
                        end;
                end;
                if bo2=0 then
                        writeln(-1);
        end;
        close(input);
        close(output);
end.
