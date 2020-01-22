var n,q,i,j,len1,len2,ans,aa,o:longint;
    v:array [0..1010] of string;
    s,cx:string;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,q);
  for i:=1 to n do readln(v[i]);
  for i:=1 to q do begin
    readln(len1,aa);
    str(aa,cx);
    ans:=maxlongint;
    for j:=1 to n do begin
      val(v[j],o);
      len2:=length(v[j]);
      s:=copy(v[j],len2-len1+1,len1);
      if(s=cx) and (o<ans) then ans:=o;
    end;
    if(ans=maxlongint) then writeln(-1) else writeln(ans);
  end;
  close(input);
  close(output);
end.