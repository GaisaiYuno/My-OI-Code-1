 type new=record
		 x,y,last:longint;
		 magic:boolean;
	 end;

const way:array[1..4,1..2] of longint=((0,1),(0,-1),(1,0),(-1,0));

var dis,color:array[0..100,0..100] of longint;
	p:array[0..100,0..100] of boolean;
	f:array[1..100000] of new;
	px,py,nx,ny,m,n,i,j,k,l,ll,head,tail,ch:longint;

function min(x,y:longint):longint;
begin
	if x<y then exit(x) else exit(y);
end;

procedure def;
begin
	fillchar(f,sizeof(f),0);
	fillchar(p,sizeof(p),true);
	fillchar(dis,sizeof(dis),$7f);
	fillchar(color,sizeof(color),0);
end;

procedure init;
begin
	readln(m,n);
	for k:=1 to n do begin
		readln(i,j,l);
		color[i][j]:=l+1;
	end;
end;

procedure solve;
begin
	dis[1][1]:=0;
	f[1].x:=1;
	f[1].y:=1;
	p[1][1]:=false;
	head:=1;
	tail:=1;
	while head<=tail do begin
		ch:=tail;
		for i:=head to tail do begin
			for l:=1 to 4 do begin
				nx:=f[i].x+way[l][1];
				ny:=f[i].y+way[l][2];
				if (nx>=1) and (nx<=m) and (ny>=1) and (ny<=m) then begin
					if (color[nx][ny]<>0) then begin
						if (p[nx][ny]) then begin
							inc(tail);
							f[tail].x:=nx;
							f[tail].y:=ny;
							p[nx][ny]:=false;
							f[tail].magic:=false;
						end;
						k:=dis[f[i].x][f[i].y];
						if (f[i].magic=true) then begin
							px:=f[i].x-way[f[i].last][1];
							py:=f[i].y-way[f[i].last][2];
							if (color[px][py]<>color[nx][ny]) then begin
								inc(k);
							end;
						end else if (color[f[i].x][f[i].y]<>color[nx][ny]) then inc(k);
						if k<dis[nx][ny] then begin
							dis[nx][ny]:=k;
							p[nx][ny]:=true;
						end;
					end
					else
					if (f[i].magic=false) then begin
						if (p[nx][ny]) then begin
							inc(tail);
							f[tail].x:=nx;
							f[tail].y:=ny;
							f[tail].last:=l;
							f[tail].magic:=true;
							p[nx][ny]:=false;
						end;
						k:=dis[f[i].x][f[i].y]+2;
						if k<dis[nx][ny] then begin
							dis[nx][ny]:=k;
							p[nx][ny]:=true;
						end;
					end;
				end;
			end;
		end;
		head:=ch+1;
	end;
end;

begin
	assign(input,'chess.in');reset(input);
	assign(output,'chess.out');rewrite(output);
	def;
	init;
	solve;
	if (dis[m][m]<>2139062143) then writeln(dis[m][m]) else writeln('-1');
	close(input);
	close(output);
end.


