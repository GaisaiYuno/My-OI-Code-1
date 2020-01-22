#include<bits/stdc++.h>
using namespace std;
	const int fx[5]={0,1,-1,0,0},fy[5]={0,0,0,1,-1};
	int m,n,f[110][110],dis[110][110]; bool pl=true;
bool pan(int p,int q){
	if(p<=0||q<=0)return false;
	if(p>m||q>m)return false;
	return true;
}
void dfs(int x,int y,int sum,bool bo){
	if(x==m&&y==m){
		dis[m][m]=min(sum,dis[m][m]); pl=false; return ;
	}
	else {
		for(int i=1;i<=4;i++)if(pan(x+fx[i],y+fy[i])){
			int st=dis[x+fx[i]][y+fy[i]];
			if(f[x][y]==0){
				if(f[x+fx[i]][y+fy[i]]==0&&sum<dis[x+fx[i]][y+fy[i]]){
					dis[x+fx[i]][y+fy[i]]=sum;
					dfs(x+fx[i],y+fy[i],sum,false);
				}
				else if(f[x+fx[i]][y+fy[i]]==1&&sum+1<dis[x+fx[i]][y+fy[i]]){
					dis[x+fx[i]][y+fy[i]]=sum+1;
					dfs(x+fx[i],y+fy[i],sum+1,false);
				}
				else if(f[x+fx[i]][y+fy[i]]==2&&bo==false){
					dis[x+fx[i]][y+fy[i]]=sum+2; f[x+fx[i]][y+fy[i]]=0;
					dfs(x+fx[i],y+fy[i],sum+2,true);
					dis[x+fx[i]][y+fy[i]]=sum+3; f[x+fx[i]][y+fy[i]]=1;
					dfs(x+fx[i],y+fy[i],sum+3,true);
					dis[x+fx[i]][y+fy[i]]=st; f[x+fx[i]][y+fy[i]]=2;
				}
			}
			if(f[x][y]==1){
				if(f[x+fx[i]][y+fy[i]]==1&&sum<dis[x+fx[i]][y+fy[i]]){
					dis[x+fx[i]][y+fy[i]]=sum;
					dfs(x+fx[i],y+fy[i],sum,false);
				}
				else if(f[x+fx[i]][y+fy[i]]==0&&sum+1<dis[x+fx[i]][y+fy[i]]){
					dis[x+fx[i]][y+fy[i]]=sum+1;
					dfs(x+fx[i],y+fy[i],sum+1,false);
				}
				else if(f[x+fx[i]][y+fy[i]]==2&&bo==false){
					dis[x+fx[i]][y+fy[i]]=sum+2; f[x+fx[i]][y+fy[i]]=1;
					dfs(x+fx[i],y+fy[i],sum+2,true);
					dis[x+fx[i]][y+fy[i]]=sum+3; f[x+fx[i]][y+fy[i]]=0;
					dfs(x+fx[i],y+fy[i],sum+3,true);
					dis[x+fx[i]][y+fy[i]]=st; f[x+fx[i]][y+fy[i]]=2;
				}
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n); memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)f[i][j]=2;
	for(int i=1;i<=n;i++){
		int x,y,co;
		scanf("%d%d%d",&x,&y,&co);
		f[x][y]=co;
	}
	dis[1][1]=0;
	dfs(1,1,0,false);
	if(pl)printf("-1"); else printf("%d",dis[m][m]);
}
