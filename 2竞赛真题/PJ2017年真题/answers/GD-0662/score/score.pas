var
n,m,i,j,k,t,p:longint;
x,y,z:longint;
ans:int64;

begin

        assign(input,'score.in');
        assign(output,'score.out');
        reset(input);
        rewrite(output);

        readln(x,y,z);
        x:=x div 5;
        y:=(y*3) div 10;
        z:=z div 2;


        ans:=x+y+z;

        writeln(ans);

        close(input);
        close(output);
end.