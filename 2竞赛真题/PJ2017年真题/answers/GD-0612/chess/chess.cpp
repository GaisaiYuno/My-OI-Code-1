#include<cstdio>
#include<iostream>
int dis[1011][1011],n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool a[1011][1011],s[1011][1011];
struct node{
	int x,y,mo,col;
}h[1000101];
int bfs(){
	int x,y,i,nx,ny,f=1,r=2,v,mo,nv,col;
	h[1].x=1;h[1].y=1;h[1].mo=0;dis[1][1]=0;h[1].col=s[1][1];
	while(f<r){
		x=h[f].x;y=h[f].y;v=dis[x][y];mo=h[f].mo;col=h[f++].col;
		if(x==m&&y==m)return v;
		for(i=0;i<4;i++){
			nx=x+dx[i];ny=y+dy[i];nv=v;
			if((mo&&!a[nx][ny])||nx<1||nx>m||ny<1||ny>m)continue;
			if(a[nx][ny]){
				if(col!=s[nx][ny])nv++;
				if(nv<dis[nx][ny]){
					dis[nx][ny]=nv;
					h[r].x=nx;h[r].y=ny;h[r].mo=0;h[r++].col=s[nx][ny];
				}
			}
			else{
				nv+=2;
				if(nv<dis[nx][ny]){
					dis[nx][ny]=nv;
					h[r].x=nx;h[r].y=ny;h[r].mo=1;h[r++].col=s[x][y];
				}
			}
		}
	}
	return -1;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,x,y,col;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
		dis[i][j]=9000000;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&col);
		a[x][y]=1;s[x][y]=col;
	}
	printf("%d\n",bfs());
	fclose(stdin);fclose(stdout);
	return 0;
}
