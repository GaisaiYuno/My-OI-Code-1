#include <bits/stdc++.h>
//#define color mapp[nowx][nowy]
using namespace std;
int m,n,x,y,e,i,j,ans=INT_MAX,mapp[102][102];
bool b[102][102];
void dfs(int nowx,int nowy,bool magic,int cost){
	if(nowx==m&&nowy==m) ans=min(ans,cost);
		if(mapp[nowx-1][nowy]==mapp[nowx][nowy]&&mapp[nowx-1][nowy]!=2&&b[nowx-1][nowy]==1){
			b[nowx-1][nowy]=false;
			dfs(nowx-1,nowy,1,cost);
			b[nowx-1][nowy]=true;
		}
		if(mapp[nowx+1][nowy]==mapp[nowx][nowy]&&mapp[nowx+1][nowy]!=2&&b[nowx+1][nowy]==1){
			b[nowx+1][nowy]=false;
			dfs(nowx+1,nowy,1,cost);
			b[nowx+1][nowy]=true;
		}
		if(mapp[nowx][nowy-1]==mapp[nowx][nowy]&&mapp[nowx][nowy-1]!=2&&b[nowx][nowy-1]==1){
			b[nowx][nowy-1]=false;
			dfs(nowx,nowy-1,1,cost);
			b[nowx][nowy-1]=true;
		}
		if(mapp[nowx][nowy+1]==mapp[nowx][nowy]&&mapp[nowx][nowy+1]!=2&&b[nowx][nowy+1]==1){
			b[nowx][nowy+1]=false;
			dfs(nowx,nowy+1,1,cost);
			b[nowx][nowy+1]=true;
		}
		if(magic==1){
			if(mapp[nowx-1][nowy]==2&&b[nowx-1][nowy]==1){
				b[nowx-1][nowy]=0;
				mapp[nowx-1][nowy]=0;
				dfs(nowx-1,nowy,0,cost+2);
				mapp[nowx-1][nowy]=1;
				dfs(nowx-1,nowy,0,cost+2);
				mapp[nowx-1][nowy]=2;
				b[nowx-1][nowy]=1;
			}
			if(mapp[nowx+1][nowy]==2&&b[nowx+1][nowy]==1){
				b[nowx+1][nowy]=0;
				mapp[nowx+1][nowy]=0;
				dfs(nowx+1,nowy,0,cost+2);
				mapp[nowx+1][nowy]=1;
				dfs(nowx+1,nowy,0,cost+2);
				mapp[nowx+1][nowy]=2;
				b[nowx+1][nowy]=1;
			}
			if(mapp[nowx][nowy-1]==2&&b[nowx][nowy-1]==1){
				b[nowx][nowy-1]=0;
				mapp[nowx][nowy-1]=0;
				dfs(nowx,nowy-1,0,cost+2);
				mapp[nowx][nowy-1]=1;
				dfs(nowx,nowy-1,0,cost+2);
				mapp[nowx][nowy-1]=2;
				b[nowx][nowy-1]=1;
			}
			if(mapp[nowx][nowy+1]==2&&b[nowx][nowy+1]==1){
				b[nowx][nowy+1]=0;
				mapp[nowx][nowy+1]=0;
				dfs(nowx,nowy+1,0,cost+2);
				mapp[nowx][nowy+1]=1;
				dfs(nowx,nowy+1,0,cost+2);
				mapp[nowx][nowy+1]=2;
				b[nowx][nowy+1]=1;
			}
		}
		if((mapp[nowx][nowy]==0||mapp[nowx][nowy]==1)&&(mapp[nowx-1][nowy]==0||mapp[nowx-1][nowy]==1)&&mapp[nowx][nowy]!=mapp[nowx-1][nowy]&&b[nowx-1][nowy]==1){
			b[nowx-1][nowy]=0;
			dfs(nowx-1,nowy,1,cost+1);
			b[nowx-1][nowy]=1;
		}
		if((mapp[nowx][nowy]==0||mapp[nowx][nowy]==1)&&(mapp[nowx+1][nowy]==0||mapp[nowx+1][nowy]==1)&&mapp[nowx][nowy]!=mapp[nowx+1][nowy]&&b[nowx+1][nowy]==1){
			b[nowx+1][nowy]=0;
			dfs(nowx+1,nowy,1,cost+1);
			b[nowx+1][nowy]=1;
		}
		if((mapp[nowx][nowy]==0||mapp[nowx][nowy]==1)&&(mapp[nowx][nowy-1]==0||mapp[nowx][nowy-1]==1)&&mapp[nowx][nowy]!=mapp[nowx][nowy-1]&&b[nowx][nowy-1]==1){
			b[nowx][nowy-1]=0;
			dfs(nowx,nowy-1,1,cost+1);
			b[nowx][nowy-1]=1;
		}
		if((mapp[nowx][nowy]==0||mapp[nowx][nowy]==1)&&(mapp[nowx][nowy+1]==0||mapp[nowx][nowy+1]==1)&&mapp[nowx][nowy]!=mapp[nowx][nowy+1]&&b[nowx][nowy+1]==1){
			b[nowx][nowy+1]=0;
			dfs(nowx,nowy+1,1,cost+1);
			b[nowx][nowy+1]=1;
		}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++) mapp[i][j]=2,b[i][j]=true;
	}
	for(i=0;i<=m+1;i++) mapp[0][i]=-1;
	for(i=1;i<=m+1;i++) mapp[i][101]=-1;
	for(i=1;i<=m+1;i++) mapp[101][i]=-1;
	for(i=1;i<=m+1;i++) mapp[i][0]=-1;
	b[1][1]=false;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&e);
		mapp[x][y]=e;
	}
	dfs(1,1,1,0);
	if(ans==INT_MAX) printf("-1");
	else printf("%d",ans);
	return 0;
}
