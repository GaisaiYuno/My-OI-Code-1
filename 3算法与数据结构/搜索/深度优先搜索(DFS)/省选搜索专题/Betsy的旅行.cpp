//http://111.230.183.91:8080/problem/2
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10
using namespace std;
int n;
int vis[maxn][maxn];
int link[maxn][maxn];
const int dirx[4]= {1,-1,0,0};
const int diry[4]= {0,0,1,-1};
int ans=0;
void dfs(int x,int y,int t) {
//	printf("(%d,%d) t=%d\n",x,y,t);
	int xx,yy;
	if(x==n&&y==1) {
		if(t==n*n) ans++;
//		if(t==n*n) printf("ok\n");
//		printf("\n");
		return;
	}
	if(!vis[x-1][y]&&!vis[x+1][y]&&vis[x][y-1]&&vis[x][y+1]) return;
	if(!vis[x][y-1]&&!vis[x][y+1]&&vis[x+1][y]&&vis[x-1][y]) return;//·ÀÖ¹×ß½øËÀºúÍ¬
	vis[x][y]=1;
	for(int i=0; i<4; i++) {
		link[x+dirx[i]][y+diry[i]]--;
	}
	for(int i=0; i<4; i++) {
		xx=x+dirx[i];
		yy=y+diry[i];
		if(xx<1||yy<1||xx>n||yy>n||vis[xx][yy]||link[xx][yy]<1) continue;
		dfs(xx,yy,t+1);
	}
	vis[x][y]=0;
	for(int i=0; i<4; i++) {
		link[x+dirx[i]][y+diry[i]]++;
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			for(int k=0;k<4;k++)
				if(i+dirx[k]>=0&&i+dirx[k]<=n+1&&j+diry[k]>=0&&j+diry[k]<=n+1)
					link[i+dirx[k]][j+diry[k]]++;

		}
	}
	dfs(1,1,1);
	printf("%d\n",ans);
}
