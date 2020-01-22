var     n,q,i,j,t,sum,min,tmp:longint;
        a:array[1..1000] of string;
        s:string;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,q);
        for i:=1 to n do readln(a[i]);
        for i:=1 to q do
        begin
                readln(tmp,s);
                min:=-1;
                delete(s,1,1);
                for j:=1 to n do
                 if copy(a[j],length(a[j])-tmp+1,tmp)=s then
                 begin
                        val(a[j],sum);
                        if (min=-1)or(sum<min)then min:=sum;
                 end;
                writeln(min);
        end;
        close(input);
        close(output);
end.