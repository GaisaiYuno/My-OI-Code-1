//Âå¹È ºþ¼ÆÊý 
#include<iostream>
#include<cstdio>
#define maxn 105
using namespace std;
int map[maxn][maxn];
int xx[8]={0,0,1,-1,1,1,-1,-1},yy[8]={1,-1,0,0,-1,1,1,-1};
int m,n,ans;
void dfs(int x,int y){
	int nx,ny;
	map[x][y]=0;
	for(int i=0;i<8;i++){
		nx=x+xx[i];
		ny=y+yy[i];
		if(nx>0&&ny>0&&nx<=n&&ny<=m&&map[nx][ny]==1){
		    dfs(nx,ny); 
	    }
	}
}
int main() {
	char t;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
		   cin>>t;
		   if(t=='W') map[i][j]=1;
		} 
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) { 
			if(map[i][j]==1){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0; 
}

