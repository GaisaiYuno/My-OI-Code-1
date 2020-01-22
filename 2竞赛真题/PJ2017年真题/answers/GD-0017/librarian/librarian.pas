var
   f,n,i,j,p,s,mid:longint;
   k:array[1..1000]of longint;
   k1:array[1..1000]of string;
   p1,sb:string;
   g:boolean;
procedure kp(l,r:longint);
var i,j,mid,t:longint;
begin
    i:=l;
    j:=r;
    mid:=k[(l+r)div 2];
    while i<=j do
    begin
        while k[i]<mid do inc(i);
        while k[j]>mid do dec(j);
        if i<=j then
        begin
            t:=k[i]; k[i]:=k[j]; k[j]:=t;
            inc(i); dec(j);
        end;
    end;
    if i<r then kp(i,r);
    if j>l then kp(l,j);
end;

begin
assign(input,'librarian.in');   reset(input);
assign(output,'librarian.out'); rewrite(output);
    readln(n,p);
    for i:=1 to n do readln(k[i]);
    kp(1,n);
    for i:=1 to n do
    begin
        str(k[i],k1[i]);
    end;
    for i:=1 to p do
    begin
        readln(s,p);
        str(p,p1);
        g:=false;
        for j:=1 to n do
        begin
            sb:=copy(k1[j],length(k1[j])-s+1,s);
            if sb=p1 then
            begin
                writeln(k1[j]);
                g:=true;
                break;
            end;
        end;
        if g=false then writeln(-1);
    end;
    close(input);
    close(output);

end.
