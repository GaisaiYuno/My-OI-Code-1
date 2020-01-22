#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int m,n,x,y,c;
int a[505][505];
int ans;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
bool exist[505][505];

void dfs(int x,int y,int money,int to){
	if(money>=ans) return;
	if(x==m && y==m){
		ans=min(ans,money);
		return;
	}
	for(int i=1;i<=4;++i){
		int tx=x+dx[i],ty=y+dy[i];
		if(1<=tx && tx<=m && 1<=ty && ty<=m){
			if((!exist[tx][ty]) && 
			a[tx][ty]!=-1 && ((a[x][y]==a[tx][ty])||(to!=-2&&to==a[tx][ty]))){
				exist[tx][ty]=1;
				dfs(tx,ty,money,-2);
				exist[tx][ty]=0;
			}
			if((!exist[tx][ty]) && 
			a[tx][ty]!=-1 && ((a[x][y]!=a[tx][ty] &&a[x][y]!=-1)||(to!=-2&&to!=a[tx][ty]))){
				exist[tx][ty]=1;
				dfs(tx,ty,money+1,-2);
				exist[tx][ty]=0;
			}
			if((!exist[tx][ty]) && 
			a[tx][ty]==-1 && a[x][y]!=-1 && to==-2){
				exist[tx][ty]=1;
				dfs(tx,ty,money+2,a[x][y]);
				exist[tx][ty]=0;
			}
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	const int inf=9999999;ans=inf;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j){
			a[i][j]=-1;
		}
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
	dfs(1,1,0,-2);
	if(ans==inf)
		puts("-1");
	else
		printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
