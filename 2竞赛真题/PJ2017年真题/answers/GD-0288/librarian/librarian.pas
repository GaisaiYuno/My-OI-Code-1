var a,b,i,j,q,p,h,k,t,z:longint;
    s:array[0..1050] of longint;
    y,x:array[0..1050] of string;
    e,u,r:string;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
        readln(a,b);
        for i:=1 to a do
        begin
                readln(x[i]);
                if x[i]>r then if length(x[i])=length(r) then r:=x[i];
                if length(x[i])>length(r) then r:=x[i];
        end;
        for i:=1 to b do
        begin
                readln(e);
                j:=pos(' ',e);
                y[i]:=copy(e,1,j-1);
                val(y[i],z);
                y[i]:=copy(e,j+1,z);
        end;
        for i:=1 to b do
        begin
                q:=0;u:=r;p:=0;
                for j:=1 to a do
                begin

                if copy(x[j],length(x[j])-length(y[i])+1,length(y[i]))=y[i] then if pos(y[i],x[j])<>0 then begin
                                          p:=1;
                                          if length(u)=length(x[j]) then begin if u>=x[j] then u:=x[j];end
                                                                                    else if length(u)>=length(x[j]) then u:=x[j];
                                          end;
                end;
                if p=0 then writeln('-1') else
                                          begin
                                          writeln(u);
                                          end;

        end;
close(input);
close(output);
end.

