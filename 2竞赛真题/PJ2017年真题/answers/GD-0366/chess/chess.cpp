#include<bits/stdc++.h>
using namespace std;
int m,n,i,x,y,c,ch[110][110],fx[2]={1,0},fy[2]={0,1},ans=2147483647,xx,yy,f[110][110];
void dfs(int x,int y,int cost){
	if(x==m&&y==m) ans=min(ans,cost);
	else{
		for(i=0;i<2;i++){
			yy=x+fx[i];
			xx=y+fy[i];
			if(xx>0&&xx<=m&&yy>0&&yy<=m){
				if(ch[xx][yy]==-1){
					if(f[x][y]==0) return;
					ch[xx][yy]=ch[x][y];
					dfs(xx,yy,cost+2);
					ch[xx][yy]=-1;
				}
				else if(ch[x][y]!=ch[xx][yy]) dfs(xx,yy,cost+1);
				else dfs(xx,yy,cost);
			}
		}
	}
}
int main(){
	freopen("chess.in","read",stdin);
	freopen("chess.out","write",stdout);
	memset(ch,-1,sizeof(ch));
	cin>>m>>n;
	for(i=1;i<=n;i++){
		cin>>x>>y>>c;
		ch[x][y]=c;
		f[110][110]=1;
	}
	dfs(1,1,0);
	if(ans==2147483647) ans=-1;
	cout<<ans;
}
