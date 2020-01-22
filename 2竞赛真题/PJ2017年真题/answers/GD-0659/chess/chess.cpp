#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[110][110],fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}},mon[110][110],vis[110][110];
/*void dy(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) cout<<mapp[i][j]<<" ";
		cout<<"\n";
	}
	getchar();system("cls");
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(mon[i][j]==2139062143) cout<<"0 ";
			else cout<<mon[i][j]<<" ";
		}
		cout<<"\n";
	}
	getchar();system("cls");
}*/
void bj(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+fx[i][0],yy=y+fx[i][1];
		if(mapp[xx][yy]==0) vis[xx][yy]=1;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		mapp[x][y]=z+1;
	}
	memset(mon,0x7f,sizeof(mon));
	mon[1][1]=0;
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) if(!vis[i][j]){
		if(!mapp[i][j]&&(!vis[i-1][j]&&!vis[i][j-1])) continue;
		vis[i][j]=1;
		if(i>1){
			mon[i][j]=mon[i-1][j]+abs(mapp[i-1][j]-mapp[i][j]);
			if(mapp[i][j]==0){
				mapp[i][j]=mapp[i-1][j],vis[i][j]=0;bj(i,j);
				if(mapp[i-1][j]==1) mon[i][j]++;
			}
		}
		if(j>1&&mon[i][j]>mon[i][j-1]+abs(mapp[i][j-1]-mapp[i][j])){
			mon[i][j]=mon[i][j-1]+abs(mapp[i][j-1]-mapp[i][j]);
			if(mapp[i][j]==0){
				mapp[i][j]=mapp[i][j-1],vis[i][j]=0;bj(i,j);
				if(mapp[i][j-1]==1) mon[i][j]++;
			}
		}
//		dy();
	}
	if(mon[m][m]!=2139062144) cout<<mon[m][m];
	else cout<<"-1";
}
