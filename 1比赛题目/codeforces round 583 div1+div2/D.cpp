#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1000000
using namespace std;
int n,m;
char in[maxn+5];
vector<char>s[maxn+5];
struct node{
	int x;
	int y;
	node(){
		
	}
	node(int _x,int _y){
		x=_x;
		y=_y;
	}
};
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
vector<bool>vis[maxn+5];
vector<bool>mark[maxn+5];
bool dfs(int x,int y){
	if(x>n||y>m) return 0;
	if(x==n&&y==m) return 1;
	if(s[x][y]=='#'||vis[x][y]||mark[x][y]) return 0;
	vis[x][y]=1;
	bool flag=dfs(x+1,y);
	if(!flag) flag=dfs(x,y+1);
	if(flag) mark[x][y]=1;
	return flag;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",in+1);
		s[i].resize(m+1);
		for(int j=1;j<=m;j++) s[i][j]=in[j];
		vis[i].resize(m+1);
		mark[i].resize(m+1); 
	}
	bool flag=dfs(1,1);
	if(!flag) printf("0\n");
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) vis[i][j]=0;
		}
		mark[1][1]=mark[n][m]=0;
		flag=dfs(1,1);
		if(!flag) printf("1\n");
		else printf("2\n");
	}
		
}
/*
5 5
...#.
...#.
.....
.###.
.....
*/
