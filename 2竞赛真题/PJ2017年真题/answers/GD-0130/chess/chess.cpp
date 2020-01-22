#include <iostream>
#include <cstdio>
using namespace std;
int m,n,i,j,c,ans=0x7fffffff,cost,a[101][101];
bool vis[101][101];
void dfs(int x,int y){
	vis[x][y]=true;
	if((x==m)&&(y==m)){
		ans=min(ans,cost);
		return;
	}else if((x==m-1)&&(y==m)&&(a[m][m]==0)){
		ans=min(ans,cost+2);
		return;
	}else if((x==m)&&(y==m-1)&&(a[m][m]==0)){
		ans=min(ans,cost+2);
		return;
	}
	if(((a[x+1][y]!=0)&&(vis[x+1][y]==false))||((a[x-1][y]!=0)&&(vis[x-1][y]==false))||
	((a[x][y+1]!=0)&&(vis[x][y+1]==false))||((a[x][y-1]!=0)&&(vis[x][y-1]==false))){
		if((x+1<=m)&&(a[x+1][y]!=0)&&(vis[x+1][y]==false)){
			if(a[x+1][y]!=a[x][y])++cost;
			dfs(x+1,y);
			if(a[x+1][y]!=a[x][y])--cost;
		}
		if((x-1>=1)&&(a[x-1][y]!=0)&&(vis[x-1][y]==false)){
			if(a[x-1][y]!=a[x][y])++cost;
			dfs(x-1,y);
			if(a[x-1][y]!=a[x][y])--cost;
		}
		if((y+1<=m)&&(a[x][y+1]!=0)&&(vis[x][y+1]==false)){
			if(a[x][y+1]!=a[x][y])++cost;
			dfs(x,y+1);
			if(a[x][y+1]!=a[x][y])--cost;
		}
		if((y-1>=1)&&(a[x][y-1]!=0)&&(vis[x][y-1]==false)){
			if(a[x][y-1]!=a[x][y])++cost;
			dfs(x,y-1);
			if(a[x][y-1]!=a[x][y])--cost;
		}
	}else{
		if((x+1<=m)&&(y+1<=m)&&(a[x+1][y+1]!=0)&&(vis[x+1][y+1]==false)){
			if(a[x+1][y+1]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x+1,y+1);
			if(a[x+1][y+1]!=a[x][y])cost-=3;
			else cost-=2;
		}
		if((x-1>=1)&&(y-1>=1)&&(a[x-1][y-1]!=0)&&(vis[x-1][y-1]==false)){
			if(a[x-1][y-1]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x-1,y-1);
			if(a[x-1][y-1]!=a[x][y])cost-=3;
			else cost-=2;
		}
		if((x+1<=m)&&(y-1>=1)&&(a[x+1][y-1]!=0)&&(vis[x+1][y-1]==false)){
			if(a[x+1][y-1]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x+1,y-1);
			if(a[x+1][y-1]!=a[x][y])cost-=3;
			else cost-=2;
		}
		if((x-1>=1)&&(y+1<=m)&&(a[x-1][y+1]!=0)&&(vis[x-1][y+1]==false)){
			if(a[x-1][y+1]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x-1,y+1);
			if(a[x-1][y+1]!=a[x][y])cost-=3;
			else cost-=2;
		}
		if((x+2<=m)&&(a[x+2][y]!=0)&&(vis[x+2][y]==false)){
			if(a[x+2][y]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x+2,y);
			if(a[x+2][y]!=a[x][y])cost-=3;
			else cost-=2;
		}
		if((x-2>=1)&&(a[x-2][y]!=0)&&(vis[x-2][y]==false)){
			if(a[x-2][y]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x-2,y);
			if(a[x-2][y]!=a[x][y])cost-=3;
			else cost-=2;
		}
		if((y+2<=m)&&(a[x][y+2]!=0)&&(vis[x][y+2]==false)){
			if(a[x][y+2]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x,y+2);
			if(a[x][y+2]!=a[x][y])cost-=3;
			else cost-=2;
		}
		if((y-2>=1)&&(a[x][y-2]!=0)&&(vis[x][y-2]==false)){
			if(a[x][y-2]!=a[x][y])cost+=3;
			else cost+=2;
			dfs(x,y-2);
			if(a[x][y-2]!=a[x][y])cost-=3;
			else cost-=2;
		}
	}
	vis[x][y]=false;
	return;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	while(n--){
		scanf("%d%d%d",&i,&j,&c);
		a[i][j]=c+1;
	}
	dfs(1,1);
	if(ans!=0x7fffffff)printf("%d",ans);
	else printf("-1");
	return 0;
}
