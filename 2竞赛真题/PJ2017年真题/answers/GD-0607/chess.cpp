#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n,x,y,c,a[105][105],cost[105][105],tmp[105][105];
bool vis[105][105];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&m,&n);
	for(int i=0;i<=m+1;i++)
		for(int j=0;j<=m+1;j++)
			cost[i][j]=10000000;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&x,&y,&c);
		c++;
		a[x][y]=c;
	}
	cost[1][1]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j+1]!=a[i][j]){
				if(a[i][j]==0){
					if(tmp[i][j]==a[i][j+1]){
						cost[i][j+1]=min(cost[i][j+1],cost[i][j]);
					}
					if(tmp[i][j]!=a[i][j+1]){
						cost[i][j+1]=min(cost[i][j+1],cost[i][j]+1);
					}
				}
				else if(a[i][j+1]==0){
					if(!vis[i][j])
						tmp[i][j+1]=a[i][j];
						cost[i][j+1]=min(cost[i][j+1],cost[i][j]+2);
					
					vis[i][j+1]=1;
				}
				else cost[i][j+1]=min(cost[i][j+1],cost[i][j]+1);
			}
			else if(a[i][j+1]!=0)
				 cost[i][j+1]=min(cost[i][j+1],cost[i][j]);
			
			if(a[i+1][j]!=a[i][j]){
				if(a[i][j]==0){
					if(tmp[i][j]==a[i+1][j]){
						cost[i+1][j]=min(cost[i+1][j],cost[i][j]);
					}
					if(tmp[i][j]!=a[i+1][j]){
						cost[i+1][j]=min(cost[i+1][j],cost[i][j]+1);
					}
				}
				else if(a[i+1][j]==0){
					if(!vis[i][j])
						tmp[i+1][j]=a[i][j];
						cost[i+1][j]=min(cost[i+1][j],cost[i][j]+2);
					
					vis[i+1][j]=1;
				}
				else cost[i+1][j]=min(cost[i+1][j],cost[i][j]+1);
			}
			else if(a[i+1][j]!=0)
				cost[i+1][j]=min(cost[i][j+1],cost[i][j]);
		}
	}
	if(cost[m][m]!=10000000)
		printf("%d",cost[m][m]);
	else printf("-1");
	return 0;
}
