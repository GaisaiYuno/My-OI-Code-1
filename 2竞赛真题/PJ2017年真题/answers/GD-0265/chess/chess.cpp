#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int dx[]={0,-1,0,1};
const int dy[]={-1,0,1,0};
int map[105][105];
int n,m,x,y,c,f[105][105];

void dfs(int x,int y,bool k,bool c){
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>m||nx<1||ny>m||ny<1)continue;
		if(~map[nx][ny]){
			if((k?c:map[x][y])==map[nx][ny])
				if(f[nx][ny]>f[x][y])
					f[nx][ny]=f[x][y],dfs(nx,ny,0,0);else;
			else
				if(f[nx][ny]>f[x][y]+1)
					f[nx][ny]=f[x][y]+1,dfs(nx,ny,0,0);
		}else{
			if(k)continue;
			if(f[nx][ny]>=f[x][y]+2)
				f[nx][ny]=f[x][y]+2,dfs(nx,ny,1,map[x][y]);
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(map,-1,sizeof(map));
	memset(f,0x7f,sizeof(f));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c;
	}
	f[1][1]=0,dfs(1,1,0,0);
	printf("%d",f[m][m]!=0x7f7f7f7f?f[m][m]:-1);
	return 0;
}
