var
        a,b:array[0..1000] of string;
        l:array[0..10000] of longint;
        i,j,n,q,k:longint;
        bz,bz1:boolean;
function big(a,b:string):boolean;
var
        x,y:longint;
begin
        val(a,x);
        val(b,y);
        if x>y then exit(true) else exit(false);
end;
BEGIN
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,q);
        for i:=1 to n do readln(a[i]);
        for i:=1 to q do
        begin
                readln(l[i],b[i]);
                delete(b[i],1,1);
        end;
        for i:=1 to n-1 do
                for j:=i+1 to n do
                       if big(a[i],a[j]) then
                       begin
                                a[0]:=a[i];
                                a[i]:=a[j];
                                a[j]:=a[0];
                       end;
        for i:=1 to q do
        begin
                bz1:=false;
                for j:=1 to n do
                begin
                        bz:=true;
                        if length(a[j])>=l[i]then
                        begin
                                for k:=1 to l[i] do
                                begin
                                        if b[i,l[i]-k+1]<>a[j,length(a[j])-k+1] then
                                        begin
                                                bz:=false;
                                                break;
                                        end;
                                end;
                                if bz then
                                begin
                                        bz1:=true;
                                        writeln(a[j]);
                                        break;
                                end;
                        end;
                end;
                if bz1=false then writeln(-1);
        end;
        close(input);close(output);
END.
