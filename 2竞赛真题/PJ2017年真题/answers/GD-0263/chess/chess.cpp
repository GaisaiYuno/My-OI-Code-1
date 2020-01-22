#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100+5;
const int INF=2e9;
const int zl[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int m,n;
int g[maxn][maxn];
int f[maxn][maxn];
bool onNocolor=false;
bool inSide(int x,int y){
	if(x>0&&x<=m&&y>0&&y<=m) return true;
	return false;
}
bool Around(int x,int y){
	for(int i=0;i<4;i++)
	if(g[x+zl[i][0]][y+zl[i][1]]!=0) return false;
	return true;
}
void init(){
	memset(g,0,sizeof(g));
	for(int i=0;i<maxn;i++)
	for(int j=0;j<maxn;j++) f[i][j]=INF;
	int a,b,c;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(c==0) g[a][b]=1;
		if(c==1) g[a][b]=2;
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++) 
	if(g[i][j]==0&&Around(i,j)) f[i][j]=-1;
	f[1][1]=0;
}
void dfs(int x,int y){
	if(onNocolor){
		for(int i=0;i<4;i++){
			int ax=x+zl[i][0],ay=y+zl[i][1];
			if(inSide(ax,ay)&&f[ax][ay]>f[x][y]){
				f[ax][ay]=f[x][y]; onNocolor=false; dfs(ax,ay);
			}
		}
	}
	else{
		for(int i=0;i<4;i++){
			int ax=x+zl[i][0],ay=y+zl[i][1];
			if(inSide(ax,ay)&&f[ax][ay]>f[x][y]&&g[ax][ay]==g[x][y]){
				f[ax][ay]=f[x][y]; dfs(ax,ay);
			} 
			if(inSide(ax,ay)&&f[ax][ay]>(f[x][y]+1)&&g[ax][ay]!=g[x][y]&&g[ax][ay]!=0){
				f[ax][ay]=f[x][y]+1; dfs(ax,ay);
			}
			if(inSide(ax,ay)&&f[ax][ay]>(f[x][y]+2)&&g[ax][ay]==0){
				onNocolor=true; f[ax][ay]=f[x][y]+2; dfs(ax,ay);
			}
		}
	}
}
void solve(){
	dfs(1,1);
	if(f[m][m]==INF) printf("-1\n");
	else printf("%d\n",f[m][m]);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	init();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
