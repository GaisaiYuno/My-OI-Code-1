var
        a,b:array[0..1000]of string;
        n,q,i,j,s,t:longint;
        ch:char;
        bz:boolean;
procedure js(i,j:longint);
var
        l,r:longint;
        mid:string;
begin
        l:=i;
        r:=j;
        mid:=a[random(j-i)+i];
        repeat
                while (length(a[i])<length(mid))or(length(a[i])=length(mid))and(a[i]<mid) do
                begin
                        inc(i);
                end;
                while (a[j]>mid)and(length(a[j])=length(mid))or(length(a[j])>length(mid)) do dec(j);
                if i<=j then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then js(i,r);
        if l<j then js(l,j);
end;
function sss(ii,jj:longint):boolean;
var
        i:longint;
begin
        i:=length(a[jj]);
        if b[ii][1]=a[jj][i]then exit(true);
        exit(false);
end;
function ssss(ii,jj:longint):boolean;
var
        i:longint;
begin
        i:=length(a[jj]);
        if (b[ii][1]=a[jj][i-1])and(b[ii][2]=a[jj][i])then exit(true);
        exit(false);
end;
function sssss(ii,jj:longint):boolean;
var
        i:longint;
begin
        i:=length(a[jj]);
        if (b[ii][1]=a[jj][i-2])and(b[ii][2]=a[jj][i-1])and(b[ii][3]=a[jj][i])then exit(true);
        exit(false);
end;
function ss(ii,jj:longint):boolean;
var
        i,j,t,x,y:longint;
        bb:boolean;
begin
        i:=1;
        j:=1;
        bb:=false;
        if length(b[ii])=1 then
        begin
                if sss(ii,jj)then exit(true)
                else exit(false);
        end
        else
        if length(b[ii])=2 then
        begin
                if ssss(ii,jj)then exit(true)
                else exit(false);
        end
        else
        if length(b[ii])=3 then
        begin
                if sssss(ii,jj)then exit(true)
                else exit(false);
        end
        else
        begin
                while (i<>(length(b[ii])))and(j<>length(a[jj]))do
                begin
                        if b[ii][i]=a[jj][j]then
                        begin
                                inc(i);
                                inc(j);
                        end
                        else
                        if bb then
                        begin
                                bb:=false;
                                i:=1;
                                inc(j);
                        end
                        else
                        begin
                                i:=1;
                                bb:=true;
                        end;
                end;
                if (i=length(b[ii]))and(j=length(a[jj]))and(a[jj][j]=b[ii][i]) then exit(true);
                exit(false);
        end;
end;
begin
        assign(input,'librarian.in'); reset(input);
        assign(output,'librarian.out'); rewrite(output);
        readln(n,q);
        for i:=1 to n do readln(a[i]);
        for i:=1 to q do
        begin
                ch:='?';
                while ch<>' 'do read(ch);
                readln(b[i]);
        end;
        bz:=true;
        js(1,n);
        for i:=1 to q do
                for j:=1 to n do
                begin
                        if (j=1)and(bz=false)then writeln(-1);
                        bz:=false;
                        if ss(i,j)then
                        begin
                                writeln(a[j]);
                                bz:=true;
                                break;
                        end;
                end;
        if not ss(i,j) then writeln(-1);
        close(input); close(output);
end.
