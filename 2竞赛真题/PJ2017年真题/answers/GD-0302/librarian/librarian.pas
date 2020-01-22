type new=record
     g:string;
     ll:longint;
     end;
var nums,goal:array[1..1000] of longint;
    num:array[1..1000] of string;
    reader:array[1..1000] of new;
    n,m,a,b,c,d,e:longint;
    q,w:string;

procedure kp(i,j:longint);
var k,l,mid,nn:longint;
    q1:string;
begin
  k:=i;l:=j;
  mid:=nums[(i+j) div 2];
    repeat
      while nums[k]<mid do inc(k);
      while nums[l]>mid do dec(l);
      if k<=l then begin
      nn:=nums[k];
      nums[k]:=nums[l];
      nums[l]:=nn;
      q1:=num[k];
      num[k]:=num[l];
      num[l]:=q1;
      inc(k);
      dec(l);
      end;
    until k>l;
    if k<j then kp(k,j);
    if l>i then kp(i,l);
end;

begin
  assign (input,'librarian.in'); reset (input);
  assign(output,'librarian.out');rewrite(output);
  readln (n,m);
    for a:=1 to n do begin
    readln (num[a]);
    val(num[a],nums[a]);
    end;
    for a:=1 to m do begin
    readln (q);
    c:=pos(' ',q)-1;
    w:=copy(q,1,c);
    delete(q,1,c+1);
    val(w,reader[a].ll);
    reader[a].g:=q;
    end;
  kp(1,n);
  c:=0;
    for a:=1 to m do
      for b:=1 to n do begin
      c:=pos(reader[a].g,num[b]);
      d:=length(num[b])+1;
      e:=reader[a].ll;
        if c>0 then if c<>d-e then continue
        else begin
        goal[a]:=nums[b];
        break;
        end;
      end;
    for a:=1 to m do if goal[a]=0 then writeln (-1) else writeln (goal[a]);
  close (input);
  close(output);
end.