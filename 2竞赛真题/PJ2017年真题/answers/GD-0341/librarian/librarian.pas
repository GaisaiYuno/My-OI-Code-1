var
        a,c:array[1..100000] of string;
        b,a1,w:array[0..10000] of longint;
        i,j,n,q,t:longint;
        s1,s2,o,min,u:string;
        bj:boolean;
begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);
readln(n,q);
for i:=1 to n do
        readln(a[i]);

for i:=1 to q do
begin
        readln(b[i],c[i]);
        delete(c[i],1,1);
end;
for i:=1 to q do
begin
        str(maxlongint,o);
        min:=o;
        t:=0;
        for j:=1 to n do
        if {(w[j]=0)and}(c[i]=copy(a[j],length(a[j])-b[i]+1,b[i]))and(length(a[j])<length(min))then
        begin
                min:=a[j];
                t:=j;
        end
        else
        if {(w[j]=0)and}(c[i]=copy(a[j],length(a[j])-b[i]+1,b[i]))and(length(a[j])=length(min))then
        begin
                u:=a[j];
                if u[1]<min[1] then begin
                        min:=a[j];
                        t:=j;
                end;
        end;
        w[t]:=1;
        if t<>0 then writeln(min)
                else writeln(-1);
end;
close(input);
close(output);
end.
