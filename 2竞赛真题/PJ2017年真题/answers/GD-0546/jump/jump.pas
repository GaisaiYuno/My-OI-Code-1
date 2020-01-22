var
a : array[0..20000000] of longint;
k,lei,d,n,i,j,o,maxlen : longint;
b : boolean;
function max(a,b : longint):longint;
begin
        if a>b then exit(a)
        else exit(b);
end;
procedure dg(jv,m,l : longint);
var
i : longint;
        begin
                if (l>=k) then begin b:=true;exit;end;
                if (m>=maxlen) then exit;
                for i := max(d-jv+1,1) to d+jv do
                if ((m+i)<=maxlen) then
                begin
                        dg(jv,m+i,l+a[m+i]);
                        if b then exit;
                end;
        end;

begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);
readln(n,d,k);
for i := 1 to n do
begin
read(j,o);
if j >maxlen then maxlen := j;
a[j] :=o;
lei := lei+o;;
end;
if lei<k then begin write(-1);close(input); close(output);exit;end;
for i := 0 to maxlen do
begin
        b := false;
        dg(i,0,0);
        if b then
        begin
                write(i);
                close(input); close(output);
                exit;
        end;
end;
write(-1);
close(input);close(output);
end.
