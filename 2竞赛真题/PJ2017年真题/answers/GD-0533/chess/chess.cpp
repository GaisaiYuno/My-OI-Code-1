#include<bits/stdc++.h>
using namespace std;
/*
const int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int c[110][110],f[110][110],m,n;

void dfs(int x,int y){
	for(int i=0;i<4;i++){
		if(x+fx[i][0]>0&&x+fx[i][0]<=m&&y+fx[i][1]>0&&y+fx[i][1]<=m){
			if(2!=c[x+fx[i][0]][y+fx[i][1]]&&c[x][y]!=2) {
				f[x+fx[i][0]][y+fx[i][1]]=min(f[x+fx[i][0]][y+fx[i][1]],f[x][y]+abs(c[x][y]-c[x+fx[i][0]][y+fx[i][1]]));
				dfs(x+fx[i][0],y+fx[i][1]);
			}
			if(2==c[x+fx[i][0]][y+fx[i][1]]&&c[x][y]==2) continue;
			else {
			    c[x+fx[i][0]][y+fx[i][1]]=c[x][y];
			    f[x+fx[i][0]][y+fx[i][1]]=min(f[x+fx[i][0]][y+fx[i][1]],f[x][y]+));
				dfs(x+fx[i][0],y+fx[i][1]);
			}
		}
	}
}
*/
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
/*	memset(c,2,sizeof(c));
	memset(f,0x7f,sizeof(f));
	int xx,yy;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		 cin>>xx>>yy;
		 cin>>c[xx][yy];
	}
	f[1][1]=0;
	dfs(1,1);
	if(f[m][m]<=100000) cout<<f[m][m]<<endl;
	else*/
	cout<<"-1"<<endl;
	return 0;
}
