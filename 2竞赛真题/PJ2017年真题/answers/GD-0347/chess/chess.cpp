#include<bits/stdc++.h>
using namespace std;
int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int chi,i,j,m,n,mini=0x9ffffff,a[101][101];
bool flag,b[101][101];
int dfs(int x,int y,int c,int cost,bool gai){
	if(x==m&&y==m){
		mini=min(mini,cost);
		return 0;
	}
	b[x][y]=true;
	for(int i=0;i<4;i++) {
		int xx=x+fx[i][0],yy=y+fx[i][1];
		if(xx>0&&xx<=m&&yy>0&&yy<=m&&b[xx][yy]==false){
			if(gai!=true){
				if(a[xx][yy]==0) {
					a[xx][yy]=a[x][y];
					dfs(xx,yy,a[xx][yy],cost+2,true);
					a[xx][yy]=0;
				}
				else {
					if(a[x][y]!=a[xx][yy]) dfs(xx,yy,a[xx][yy],cost+1,false);
					else dfs(xx,yy,a[xx][yy],cost,false);
				}
			}
			else if(a[xx][yy]!=0){
				if(a[x][y]!=a[xx][yy]) dfs(xx,yy,a[xx][yy],cost+1,false);
				else dfs(xx,yy,a[xx][yy],cost,false);
			}
		}
	}
	b[x][y]=false;
	return 0;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	int x,y,c;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		if(c==1) a[x][y]=1;
		else a[x][y]=2;
	}
	for(i=m;i>=1;i--) {
		if(chi==2) {
			printf("-1");
			return 0;
		}
		for(j=i;j<=m;j++) if(a[i][j]!=0||a[j][i]!=0) {
			flag=true;
			break;
		}
		if(flag==true) {
			chi=0;
			flag=false;
		}
		else chi++;
	}
	dfs(1,1,a[1][1],0,false);
	if(mini!=0x9ffffff) printf("%d",mini);
	else printf("-1");
	return 0;
}
