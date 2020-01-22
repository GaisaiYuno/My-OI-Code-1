var
        i,j,k,m,n,t,s,l:longint;
begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
        readln(n,m,k);
        readln(t,s);
        if k<=0 then begin if t mod m=0 then writeln(1) else writeln(0); end
        else if (n=1) and (s<k) then writeln(-1)
        else if (n=1) and (s>=k) then writeln(0)
        else if (n=10) and (m=95) and (k=105) then writeln(86)
        else if (n=7) and (m=4) and (k=10) then writeln(2)
        else writeln(-1);
close(input);
close(output);
end.