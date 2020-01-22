const movex:array[1..4]of longint=(0,1,0,-1);
      movey:array[1..4]of longint=(1,0,-1,0);
var m,n,i,j,x,y,c,min:longint;
    flag:boolean;
    a:array[0..101,0..101]of longint;
    code:array[0..101,0..101]of boolean;
procedure dfs(x,y,c1,s:longint);
var i,j,r,c2,c3:longint;
begin
  if(x=m)and(y=m)then
    begin
      if s<min then min:=s;
    end
  else
    begin
      if c1=1 then begin c2:=0;c3:=2; end;
      if c1=0 then begin c2:=1;c3:=2; end;
      for r:=1 to 4 do
        begin
          i:=x+movex[r];
          j:=y+movey[r];
          if(a[i,j]=c1)and(code[i,j])then
            begin
              code[i,j]:=false;
              flag:=true;
              dfs(i,j,c1,s);
              code[i,j]:=true;
            end
          else
            if(a[i,j]=c2)and(code[i,j])then
              begin
                code[i,j]:=false;
                flag:=true;
                dfs(i,j,c2,s+1);
                code[i,j]:=true;
              end
          else
            if(a[i,j]=c3)and(code[i,j])and(flag)then
              begin
                code[i,j]:=false;
                flag:=false;
                dfs(i,j,c1,s+2);
                dfs(i,j,c2,s+2);
                flag:=true;
                code[i,j]:=true;
              end
        end;
    end;
end;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  readln(m,n);
  for i:=0 to m do
    for j:=0 to m do a[i,j]:=2;
  fillchar(code,sizeof(code),true);
  for i:=0 to m do
    begin
      code[0,i]:=false;
      code[i,0]:=false;
      code[m+1,i]:=false;
      code[i,m+1]:=false;
    end;
  for i:=1 to n do
    begin
      readln(x,y,c);
      a[x,y]:=c;
    end;
  min:=maxlongint;
  flag:=true;
  dfs(1,1,a[1,1],0);
  if min=maxlongint then writeln(-1)
                    else writeln(min+1);
  close(input);
  close(output);
end.