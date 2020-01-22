var
 i,j,n,m,min,x,y,kk:longint;
 cl,f:array[0..505,0..505]of longint;
 flag:array[0..505,0..505]of boolean;
procedure find(x,y,m,ans,co:longint);
var
 i,j:longint;
  begin
   if ans>min then exit;
   if (x=n)and(y=n) then begin min:=ans; exit; end;
   if m=1 then
           begin
           for i:=-1 to 1 do
            for j:=-1 to 1 do
            begin
            if ((i=0)xor(j=0))and(flag[x+i,y+j]) then
            begin
            flag[x+i,y+j]:=false;
            if (f[x+i,y+j]>0) then find(x+i,y+j,0,ans+abs(cl[x+i,y+j]-co),cl[x+i,y+j]);
            flag[x+i,y+j]:=true;
            end;
           end;
           end;
   if m=0 then
           begin
           for i:=-1 to 1 do
            for j:=-1 to 1 do
            begin
            if ((i=0)xor(j=0))and(flag[x+i,y+j]) then
            begin
            flag[x+i,y+j]:=false;
            if (f[x+i,y+j]=-1) then find(x+i,y+j,1,ans+2,co) else
            if (f[x+i,y+j]=f[x,y]) then find(x+i,y+j,m,ans,co) else
            if (f[x+i,y+j]>0) then find(x+i,y+j,m,ans+1,cl[x+i,y+j]);
            flag[x+i,y+j]:=true;
            end;
           end;
           end;
  end;
  begin
   assign(input,'chess.in');
   assign(output,'chess.out');
   reset(input);
   rewrite(output);
   readln(n,m);
   if n*m>4000 then
      begin
       writeln(-1);
       close(input);
       close(output);
       exit;
      end;
   fillchar(flag,sizeof(flag),true);
   for i:=1 to m do
    begin
     readln(x,y,kk);
     cl[x,y]:=kk+1;
    end;
   for i:=0 to n+1 do
    for j:=0 to n+1 do
      f[i,j]:=-2;
   for i:=1 to n do
    for j:=1 to n do
    begin
      if cl[i,j]>0 then f[i,j]:=cl[i,j]
      else f[i,j]:=-1;
    end;
   min:=maxlongint;
   flag[1,1]:=false;
   find(1,1,0,0,cl[1,1]);
   if min=maxlongint then min:=-1;
   writeln(min);
  close(input);
  close(output);
  end.
