#include<cstdio>
#include<cstring>
#include<windows.h>
using namespace std;
#define min(a,b) a<b?a:b 
int ans=2147483647;
int a[110][110],n,m;
bool vis[110][110];
void dfs(int x,int y,bool can,int money){
	vis[x][y]=1;
//	printf("x=%d y=%d money=%d\n",x,y,money);
//	Sleep(10);
	if(x==m&&y==m){
		vis[x][y]=0;
		ans=min(ans,money);
		return;
	}
	if(x-1>=1&&!vis[x-1][y]){
		if(a[x][y]&&a[x-1][y]&&a[x][y]==a[x-1][y]){
			if(!can)dfs(x-1,y,(!can),money);
			else dfs(x-1,y,can,money);
		}
		else if(a[x][y]&&a[x-1][y]&&a[x][y]!=a[x-1][y]){
			if(!can)dfs(x-1,y,(!can),money+1);
			else dfs(x-1,y,can,money+1);
		}
		else if(a[x][y]&&(!a[x-1][y])&&can)a[x-1][y]=a[x][y],dfs(x-1,y,(!can),money+2),a[x-1][y]=0;
	}
	if(x+1<=m&&!vis[x+1][y]){
		if(a[x][y]&&a[x+1][y]&&a[x][y]==a[x+1][y]){
			if(!can)dfs(x+1,y,(!can),money);
			else dfs(x+1,y,can,money);
		}
		else if(a[x][y]&&a[x+1][y]&&a[x][y]!=a[x+1][y]){
			if(!can)dfs(x+1,y,(!can),money+1);
			else dfs(x+1,y,can,money+1);
		}
		else if(a[x][y]&&(!a[x+1][y])&&can)a[x+1][y]=a[x][y],dfs(x+1,y,(!can),money+2),a[x+1][y]=0;
	}
	if(y-1>=1&&!vis[x][y-1]){
		if(a[x][y]&&a[x][y-1]&&a[x][y]==a[x][y-1]){
			if(!can)dfs(x,y-1,(!can),money);
			else dfs(x,y-1,can,money);
		}
		else if(a[x][y]&&a[x][y-1]&&a[x][y]!=a[x][y-1]){
			if(!can)dfs(x,y-1,(!can),money+1);
			else dfs(x,y-1,can,money+1);
		}
		else if(a[x][y]&&(!a[x][y-1])&&can)a[x][y-1]=a[x][y],dfs(x,y-1,(!can),money+2),a[x][y-1]=0;
	}
	if(y+1<=m&&!vis[x][y+1]){
		if(a[x][y]&&a[x][y+1]&&a[x][y]==a[x][y+1]){
			if(!can)dfs(x,y+1,(!can),money);
			else dfs(x,y+1,can,money);
		}
		else if(a[x][y]&&a[x][y+1]&&a[x][y]!=a[x][y+1]){
			if(!can)dfs(x,y+1,(!can),money+1);
			else dfs(x,y+1,can,money+1);
		}
		else if(a[x][y]&&(!a[x][y+1])&&can)a[x][y+1]=a[x][y],dfs(x,y+1,(!can),money+2),a[x][y+1]=0;
	}
	vis[x][y]=0;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int cas=0;cas<n;cas++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if(c==0)a[x][y]=1;
		if(c==1)a[x][y]=2;
	}
	dfs(1,1,1,0);
	if(ans==2147483647)puts("-1");
	else printf("%d\n",ans);
	return 0; 
}
