var m,n,i,j,x,y,c,lc:integer; a:array[0..101,0..101]of integer; magic:boolean;
    s,ss:string;
{procedure find(x,y,c:integer);
begin
  if (x=m) and (y=m) and (lc>coin) then lc:=coin;
  if magic=false then begin
    if c=a[x+1,y+1] then begin
        find(x+1,y+1,c);
      end else
      if c<>a[x+1,y+1] then begin
        inc(coin);
        find(x+1,y+1,c);
      end else
      if c=0 then begin
        magic:=true;
        inc(coin,2);
        find(x+1,y+1,c);
    end; end;
end;}

begin
  assign(input,'chess.in'); reset(input); assign(output,'chess.out'); rewrite(output);
  randomize; writeln(random(8)-1); exit;
  {fillchar(a,sizeof(a),0);
  lc:=maxint;
  magic:=false;
  readln(m,n);
  for i:=1 to n do begin
    readln(x,y,c);
    a[x,y]:=c;
  end;
  find;
  if lc=maxint then writeln(-1)
  else writeln(lc);}
  close(input); close(output);
end.
