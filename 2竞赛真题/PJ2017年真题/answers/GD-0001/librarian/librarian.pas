program librarian;
var s,t,u:array[1..1000] of string;
    a:array[1..1000] of longint; b:boolean;
    v:string; i,j,k,l,m,n:longint;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input); rewrite(output);
  readln(n,m);
  for k:=1 to n do
      readln(s[k]);
  for k:=1 to m do
      readln(a[k],t[k]);
  for k:=1 to n do
      for j:=k+1 to n do
         if length(s[k])>length(s[j])
           then begin
                v:=s[k];
                s[k]:=s[j];
                s[j]:=v;
                end
           else if length(s[k])=length(s[j])
              then if s[k]>s[j]
                then begin
                v:=s[k]; s[k]:=s[j];
                s[j]:=v;
                end;
  for i:=1 to m do
      delete(t[i],1,1);
  for i:=1 to m do
      begin
      b:=false;
      for j:=1 to n do
         if pos(t[i],s[j])=length(s[j])-a[i]+1
         then if pos(t[i],s[j])>0
            then begin
            writeln(s[j]);
            s[j]:=''; b:=true; break;
            end;
      if not(b) then writeln(-1);
      end;
  close(input); close(output);
end.