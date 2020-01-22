Var
        n,q,i,j,k,min:longint;
        t,s:string;
        a:array[1..6000]of longint;

Function pd(x:longint; s:string):boolean;
Var
        i,k:longint;
        t,t1:string;
Begin
        str(a[x],t);
        if length(t)<length(s) then
                exit(false);
        if length(t)=length(s) then
                if t=s then
                        exit(true);
        k:=length(s);
        t1:=copy(t,length(t)-k+1,k);
        if s=t1 then
                exit(true);
        exit(false);
End;

Begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);

        readln(n,q);
        for i:=1 to n do
                readln(a[i]);

        writeln(q);
        for i:=1 to q do
        begin
                readln(t);
                for j:=1 to length(t) do
                        if t[j]=' ' then
                                break;
                s:='';
                k:=j+1;
                for j:=k to length(t) do
                        s:=s+t[j];

                min:=maxlongint;
                for j:=1 to n do
                        if pd(j,s) then
                                if min>a[j] then
                                        min:=a[j];
                if min=maxlongint then
                        writeln(-1)
                else
                        writeln(min);
        end;

        readln;

close(input);close(output);
End.
