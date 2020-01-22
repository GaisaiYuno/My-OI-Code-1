uses math;

var
n,m,i,j,k,t,p,ans,d,maxn:longint;
f,x,s:array[0..1000] of longint;

b:array[0..1000] of boolean;
begin


        assign(input,'jump.in');
        assign(output,'jump.out');
        reset(input);
        rewrite(output);

        fillchar(b,sizeof(b),false);

        readln(n,d,k) ;
        for i:=1 to n do
          begin
           readln(x[i],s[i]);
          end;

        for i:=1 to n do
         begin
          if ans+s[i]>ans then begin ans:=ans+s[i]; b[i]:=true; end;

         end;

        if ans<k then begin writeln(-1); close(input); close(output); halt; end;
        t:=0;
        for i:=1 to n do
         begin
           if b[i]=true then maxn:=max(maxn,i-t);
           t:=i;
         end;

       writeln(maxn);

       close(input);
       close(output);
end.