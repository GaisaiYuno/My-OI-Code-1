var
 a,b,f:array[0..200,0..200]of longint;
 x,y,z,i,m,n,j:longint;
procedure dg(x,y,sum:longint);
begin
 if(y<n)then begin
  if b[x,y+1]<>-1 then begin
  if((b[x,y]=b[x,y+1])or(b[x,y]=b[x,y+1]*11))then begin
   if((f[x,y+1]=-1)or(sum<f[x,y+1]))then begin
    dg(x,y+1,sum);
    f[x,y+1]:=sum;
   end;
  end else begin
   if(f[x,y+1]=-1)or(sum+1<f[x,y+1])then begin
    dg(x,y+1,sum+1);
    f[x,y+1]:=sum+1;
   end;
  end;
  end else begin
  if(b[x,y]<3)and((f[x,y+1]=-1)or(sum+2<f[x,y+1]))then begin
   b[x,y+1]:=b[x,y]*11;
   dg(x,y+1,sum+2);
   f[x,y+1]:=sum+2;
   b[x,y+1]:=-1;
  end;
  end;
 end;
 if(x<n)then begin
  if(b[x+1,y]<>-1)then begin
  if((b[x,y]=b[x+1,y])or(b[x,y]=b[x+1,y]*11))then begin
   if ((f[x+1,y]=-1)or(sum<f[x+1,y]))then begin
    dg(x+1,y,sum);
    f[x+1,y]:=sum;
   end;
  end else begin
   if(f[x+1,y]=-1)or(sum+1<f[x+1,y])then begin
    dg(x+1,y,sum+1);
    f[x+1,y]:=sum+1;
   end;
  end;
  end else begin
  if(b[x,y]<3)and((f[x+1,y]=-1)or(sum+2<f[x+1,y]))then begin
   b[x+1,y]:=b[x,y]*11;
   dg(x+1,y,sum+2);
   f[x+1,y]:=sum+2;
   b[x+1,y]:=-1;
  end;
  end;
 end;
end;
begin
 assign(input,'chess.in');reset(input);
 assign(output,'chess.out');rewrite(output);
 read(n,m);
 for i:=1 to n do for j:=1 to n do begin
  f[i,j]:=-1;
  a[i,j]:=-1;
 end;
 for i:=1 to m do begin
  read(x,y,z);
  a[x,y]:=z+1;
 end;
 f[1,1]:=0;
 b:=a;
 dg(1,1,0);
 write(f[n,n]);
end.