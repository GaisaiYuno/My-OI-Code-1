#include <bits/stdc++.h>
using namespace std;
int fx[4][2]={{0,1},{-1,0},{0,-1},{1,0}},cb[110][110],tmp[110][110];
bool ff=1,vis[110][110];
long long f[110][110];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,x,y,z,i,j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		cb[x][y]=z+1,tmp[x][y]=z+1;
	}
	memset(f,0x7f,sizeof(f));
	f[1][1]=0,vis[1][1]=1;
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++){
			if(i!=1 || j!=1){
				if(!cb[i][j]){
					if(cb[i-1][j]){
						if(f[i-1][j]+2<f[i][j]){
							f[i][j]=f[i-1][j]+2,tmp[i][j]=cb[i-1][j],vis[i][j]=1;
						}
					}
					if(cb[i][j-1]){
						if(f[i][j-1]+2<f[i][j]){
							f[i][j]=f[i][j-1]+2,tmp[i][j]=cb[i][j-1],vis[i][j]=1;
						}
					}
				}
				else{
					if(vis[i-1][j]){
						f[i][j]=min(f[i-1][j]+abs(tmp[i][j]-tmp[i-1][j]),f[i][j]);
					}
					if(vis[i][j-1]){
						f[i][j]=min(f[i][j-1]+abs(tmp[i][j]-tmp[i][j-1]),f[i][j]);
						vis[i][j]=1;
					}					
				}
			}
		}
	if(vis[m][m]) cout<<f[m][m];
	else cout<<"-1";	
}
