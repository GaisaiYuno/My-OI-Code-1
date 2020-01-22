//hdu 1876
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int t,n,m;
int max_no;
int map[maxn][maxn];
int E[maxn];
int used[maxn][maxn];
int xx[2]= {1,0},yy[2]= {0,1};
int read() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void dfs(int x,int y,int e,int no) {
	int dx,dy;
	used[x][y]=1;
	if(e==0) {
		no++;
		e=map[x][y];
	}
	if(x==n&&y==m) {
		if(no>max_no)max_no=no;
		if(no==max_no) E[no]++;
		return;
	}
	for(int i=0; i<2; i++) {
		dx=x+xx[i];
		dy=y+yy[i];
		if(dx>0&&dx<=n&&dy>0&&dy<=m&&used[dx][dy]==0) {
			dfs(dx,dy,e-1,no);
			used[dx][dy]=0;
		}
	}
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				map[i][j]=read();
			}
		}
		memset(E,0,sizeof(E));
		memset(used,0,sizeof(used));
		dfs(1,1,map[1][1],0);
		printf("%d %d\n",max_no,E[max_no]);
		//for(int i=1;i<=max_no;i++) cout<<E[i]<<' ';//debug
	}
	return 0;
}
