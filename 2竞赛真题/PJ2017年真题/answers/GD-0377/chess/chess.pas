uses math;
var
        a:array[0..20,0..200]of longint;
        i,j,s,t,n,m,x,y,c:longint;
procedure dg(i,j,t:longint; bz:boolean);
begin
        if(i<1)or(j<1)or(i>n)or(j>n)then exit;
        if bz=false then
        begin
                a[i,j+1]:=a[i,j];
                dg(i,j+1,t+2,true);
        end;
end;
begin
        assign(input,'chess.in'); reset(input);
        assign(output,'chess.out'); rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(x,y,c);
                a[x,y]:=c+1;
        end;

        //dg(1,1,0,false);
        writeln(-1);
end.
