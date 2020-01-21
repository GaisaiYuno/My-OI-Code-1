//Ве№И SEARCH
#include<iostream>
#include<cstring>
#define maxr 50
#define maxn 1001 
using namespace std;
int r,c,n;
char a[maxr][maxr];
int walkx[4]={1,-1,0,0};
int walky[4]={0,0,-1,1};
bool used[maxr][maxr][maxr];
char d[maxn][5];
void dfs(int x,int y,int now){
		if(used[x][y][now]) return;
	used[x][y][now]=true;
//	if(now==n) return;
	if(now==n+1){
		a[x][y]='*';
		return;
	}
	if(x>=0&&y>=0&&x<r&&y<c&&a[x][y]!= 'X'){
		int t;
	    if(d[now][0]=='N') t=2;
	    if(d[now][0]=='S') t=3;
	    if(d[now][0]=='W') t=1;
		if(d[now][0]=='E') t=0;
		dfs(x+walkx[t],y+walky[t],now+1);
		dfs(x+walkx[t],y+walky[t],now);
	}
	return;
}
int main(){
	int sx,sy;
    cin>>r>>c;
	for(int i=0;i<r;i++){
	 	for(int j=0;j<c;j++) {
	 		cin>>a[i][j];
	 		if(a[i][j]=='*'){
	 			sx=i;
	 			sy=j;
			 }
		} 
	}
	cin>>n;
	for(int k=1;k<=n;k++) scanf("%s",d[k]);
	memset(used,false,sizeof(used));
	a[sx][sy]='.';
	//cout<<a[2][4]<<endl; 
	dfs(sx,sy,1);
	for(int u=0;u<r;u++){
		for(int v=0;v<c;v++) cout<<a[u][v];
		cout<<endl; 
	}
	return 0;           
} 
