var
n,q,i,j,ans,x,y,mode:longint;
a:array[0..2000]of string;
b,c:array[0..2000]of longint;
zfc:string;
begin
    assign(input,'librarian.in');
    reset(input);
    assign(output,'librarian.out');
    rewrite(output);
    readln(n,q);
    for i:=1 to n do
    readln(a[i]);
    for i:=1 to q do
    readln(b[i],c[i]);
    for i:=1 to q do
    begin
        ans:=maxlongint;
        for j:=1 to n do
        begin
            zfc:=copy(a[j],length(a[j])-b[i]+1,b[i]);
            val(a[j],y,mode);
            val(zfc,x,mode);
            if x=c[i] then
            if y<ans then ans:=y;
        end;
        if ans<>maxlongint then writeln(ans) else writeln(-1);
    end;
    close(input);
    close(output);
end.