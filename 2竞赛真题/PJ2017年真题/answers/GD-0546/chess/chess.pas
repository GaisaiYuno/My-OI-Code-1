var
a,f : array[0..1001,0..1001] of longint;  //hong 1 huang 2
b,d : array[0..1001,0..1001] of boolean;
fang : array[1..4,1..2] of integer;
n,m,i,j,x,y,k : longint;
function min(a,b : longint):longint;
begin
        if a>b then exit(b)
        else exit(a);
end;
procedure dg(x,y : longint);
var
i,k : longint;
begin
        d[x,y] :=true;
        for k := 1 to 4 do
        if (a[x+fang[k,1],y+fang[k,2]]<>0)and(d[x+fang[k,1],y+fang[k,2]]=false)  then
        begin
                i :=0;
                if a[x+fang[k,1],y+fang[k,2]]<>a[x,y] then i :=1;
                f[x+fang[k,1],y+fang[k,2]] := min(f[x+fang[k,1],y+fang[k,2]],f[x,y]+i);
                dg(x+fang[k,1],y+fang[k,2]);
        end;
end;
begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
fang[1,1] :=-1;fang[2,1]:=1;
fang[3,2]:=-1;fang[4,2]:=1;
readln(m,n);
for i:= 1 to n do
begin
        readln(x,y,k);
        a[x,y] := k+1;
        b[x,y] :=true;
end;
for i := 1 to m do
for j := 1 to m do
f[i,j] := maxlongint;
f[1,1] :=0;
dg(1,1);
for i := 1 to m do
for j := 1 to m do
begin
        if a[i,j]=0 then
        begin
                for k := 1 to 4 do
                if (a[i+fang[k,1],j+fang[k,2]]<>0) and (f[i+fang[k,1],j+fang[k,2]]<>maxlongint) and (f[i+fang[k,1],j+fang[k,2]]+2<f[i,j]) and b[i+fang[k,1],j+fang[k,2]] then
                begin
                        f[i,j] := f[i+fang[k,1],j+fang[k,2]]+2;
                        a[i,j] := a[i+fang[k,1],j+fang[k,2]];
                        b[i,j] := false;
                end;

        end else if f[i,j]=maxlongint then begin
                for k := 1 to 4 do
                if (a[i+fang[k,1],j+fang[k,2]]<>0) and (f[i+fang[k,1],j+fang[k,2]]<>maxlongint) then
                begin
                        if (a[i+fang[k,1],j+fang[k,2]]<>a[i,j]) then
                        f[i,j] := min(f[i,j],f[i+fang[k,1],j+fang[k,2]]+1)
                        else f[i,j] := min(f[i,j],f[i+fang[k,1],j+fang[k,2]]);
                end;
                end;

end;

if f[m,m]=maxlongint then write(-1)
else write(f[m,m]);
close(input);close(output);
end.
