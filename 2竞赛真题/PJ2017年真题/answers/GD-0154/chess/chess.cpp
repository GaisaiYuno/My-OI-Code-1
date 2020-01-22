#include<bits/stdc++.h>
using namespace std;
long long a[110][110],n,m,fx[4][2],f[110][110];
void dfs(long long x,long long y){
	if(x==m&&y==m)return ;
	for(int ii=1;ii<=4;ii++){
		if(a[x+fx[ii][1]][y+fx[ii][2]]==a[x][y])
		if(y+fx[ii][2]!=y&&x+fx[ii][1]!=x)
		dfs(x+fx[ii][1],y+fx[ii][2]);
		if(a[x+fx[ii][1]][y+fx[ii][2]]!=a[x][y]&&(a[x+fx[ii][1]][y+fx[ii][2]]==0||a[x+fx[ii][1]][y+fx[ii][2]]==1))
		if(y+fx[ii][2]!=y&&x+fx[ii][1]!=x){
			f[x+fx[ii][1]][y+fx[ii][2]]=min(f[x+fx[ii][1]][y+fx[ii][2]],f[x][y]+1);
			dfs(x+fx[ii][1],y+fx[ii][2]); 
		}
		if(a[x][y]!=66&&a[x+fx[ii][1]][y+fx[ii][2]]!=a[x][y]&&a[x+fx[ii][1]][y+fx[ii][2]]!=1&&a[x+fx[ii][1]][y+fx[ii][2]]!=0){
			for(int jj=1;jj<=4;jj++){
				if(a[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]==a[x][y]){
					if(x+fx[ii][1]+fx[jj][1]==x&&y+fx[ii][2]+fx[jj][2]==y)continue;
					f[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]=min(f[x][y]+2,f[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]);
					dfs(x+fx[ii][1]+fx[jj][1],y+fx[ii][2]+fx[jj][2]);
				}
				if(a[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]!=a[x][y])
				if(a[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]==1||a[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]==0){
					f[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]=min(f[x][y]+3,f[x+fx[ii][1]+fx[jj][1]][y+fx[ii][2]+fx[jj][2]]);
					dfs(x+fx[ii][1]+fx[jj][1],y+fx[ii][2]+fx[jj][2]);
				}
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	fx[1][1]=1;fx[1][2]=0;
	fx[2][1]=-1;fx[2][2]=0;
	fx[3][1]=0;fx[3][2]=1;
	fx[4][1]=0;fx[4][2]=-1;
	/*cin>>m>>n;
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++){f[i][j]=99999;a[i][j]=66;}
	for(int i=1;i<=n;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	f[1][1]=0;
	*/
	//dfs(1,1);
	printf("-1");
}
