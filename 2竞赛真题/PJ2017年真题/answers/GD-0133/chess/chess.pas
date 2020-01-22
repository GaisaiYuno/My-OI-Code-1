var
 n,m,j,k,i,l,x,y,z,max:longint;
 map,ans:array[0..101,0..101]of longint;
 f:array[0..101,0..101]of boolean;
procedure tt(a,b:longint);
begin
 if map[x+1,y]<>1 then map[x+1,y]:=2;
 if map[x-1,y]<>1 then map[x-1,y]:=2;
 if map[x,y+1]<>1 then map[x,y+1]:=2;
 if map[x,y-1]<>1 then map[x,y-1]:=2;
 map[x,y]:=1;
end;

function check(q,p:longint):boolean;
begin
 if (q>n)or(q<1)or(p>n)or(p<1) then exit(false);
 exit(true);
end;

function find(var q,p:longint):longint;
begin
 if q=2 then begin
              q:=p;
              exit(2);
             end;
 if (p=0) and (q=0) then exit(0);
 if (p=0) and (q=1) then exit(1);
 if (p=1) and (q=0) then exit(1);
 if (p=1) and (q=1) then exit(0);
end;

procedure dfs(dep,a,b,rp:longint);
 var
  k,rrp:longint;
begin
 if (a=n) and (b=n) then begin
                          if max>rp then max:=rp;
                          exit;
                         end;
 if (map[a+1,b]=1) and (f[a+1,b]) and check(a+1,b) then
     begin
      f[a+1,b]:=false;
      k:=ans[a+1,b];
      rrp:=rp;
      dfs(1,a+1,b,rp+find(ans[a+1,b],ans[a,b]));
      rp:=rrp;
      ans[a+1,b]:=k;
      f[a+1,b]:=true;
     end;
 if (map[a+1,b]=2) and (dep=1) and (f[a+1,b]) and check(a+1,b) then
     begin
      f[a+1,b]:=false;
      k:=ans[a+1,b];
      rrp:=rp;
      dfs(2,a+1,b,rp+find(ans[a+1,b],ans[a,b]));
      rp:=rrp;
      ans[a+1,b]:=k;
      f[a+1,b]:=true;
     end;
 if (map[a-1,b]=1) and (f[a-1,b]) and check(a-1,b) then
     begin
      f[a-1,b]:=false;
      k:=ans[a-1,b];
      rrp:=rp;
      dfs(1,a-1,b,rp+find(ans[a-1,b],ans[a,b]));
      rp:=rrp;
      ans[a-1,b]:=k;
      f[a-1,b]:=true;
     end;
 if (map[a-1,b]=2) and (dep=1) and (f[a-1,b]) and check(a-1,b) then
     begin
      f[a-1,b]:=false;
      k:=ans[a-1,b];
      rrp:=rp;
      dfs(2,a-1,b,rp+find(ans[a-1,b],ans[a,b]));
      rp:=rrp;
      ans[a-1,b]:=k;
      f[a-1,b]:=true;
     end;
 if (map[a,b+1]=1) and (f[a,b+1]) and check(a,b+1) then
     begin
      f[a,b+1]:=false;
      k:=ans[a,b+1];
      rrp:=rp;
      dfs(1,a,b+1,rp+find(ans[a,b+1],ans[a,b]));
      rp:=rrp;
      ans[a,b+1]:=k;
      f[a,b+1]:=true;
     end;
 if (map[a,b+1]=2) and (dep=1) and (f[a,b+1]) and check(a,b+1) then
     begin
      f[a,b+1]:=false;
      k:=ans[a,b+1];
      rrp:=rp;
      dfs(2,a,b+1,rp+find(ans[a,b+1],ans[a,b]));
      rp:=rrp;
      ans[a,b+1]:=k;
      f[a,b+1]:=true;
     end;
 if (map[a,b-1]=1) and (f[a,b-1]) and check(a,b-1) then
     begin
      f[a,b-1]:=false;
      k:=ans[a,b-1];
      rrp:=rp;
      dfs(1,a,b-1,rp+find(ans[a,b-1],ans[a,b]));
      rp:=rrp;
      ans[a,b-1]:=k;
      f[a,b-1]:=true;
     end;
 if (map[a,b-1]=2) and (dep=1) and (f[a,b-1]) and check(a,b-1) then
     begin
      f[a,b-1]:=false;
      k:=ans[a,b-1];
      rrp:=rp;
      dfs(2,a,b-1,rp+find(ans[a,b-1],ans[a,b]));
      rp:=rrp;
      ans[a,b-1]:=k;
      f[a,b-1]:=true;
     end;
end;
begin
 assign(input,'chess.in');reset(input);
 assign(output,'chess.out');rewrite(output);
 readln(n,m);
 max:=maxlongint;
 fillchar(f,sizeof(f),true);
 f[1,1]:=false;
 for i:=1 to n do
  for j:=1 to n do
   ans[i,j]:=2;
 for i:=1 to m do
  begin
   readln(x,y,z);
   ans[x,y]:=z;
   tt(x,y);
  end;
 dfs(1,1,1,0);
 if max<>2147483647 then writeln(max)
                    else writeln('-1');
 close(input);
 close(output);
end.
