#include<iostream>
#include<cstdio>
#define maxn 20
using namespace std;
int n,m;
int ans;
int used[maxn][maxn];
int mem[maxn][maxn];
/*void print() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			printf("%d ",used[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}*/
void dfs(int x,int y,int cnt) {
	if(mem[x][y]>cnt) return;
	if(ans<cnt) {
		ans=cnt;
		//print();
	}
	if(n*m-cnt*2<=1||x<1||y<1||x>n||y>m) {
		return;
	}
	mem[x][y]=cnt;
	for(int i=x; i<=n; i++) {
		for(int j=y; j<=m; j++) {
			if(used[i][j]==1) continue;
			else {
				if(used[i+1][j]==0&&i+1<=n) {
					used[i][j]=used[i+1][j]=1;
					dfs(i+2,j,cnt+1);
					dfs(i+1,j,cnt+1);
					used[i][j]=used[i+1][j]=0;
				}
				if(used[i][j+1]==0&&j+1<=m) {
					used[i][j]=used[i][j+1]=1;
					dfs(i,j+2,cnt+1);
					dfs(i,j+1,cnt+1);
					used[i][j]=used[i][j+1]=0;
				}
				if(used[i-1][j]==0&&i-1>=1) {
					used[i][j]=used[i-1][j]=1;
					dfs(i-2,j,cnt+1);
					dfs(i-1,j,cnt+1);
					used[i][j]=used[i-1][j]=0;
				}
				if(used[i][j-1]==0&&j-1>=1) {
					used[i][j]=used[i][j-1]=1;
					dfs(i,j-2,cnt+1);
					dfs(i,j-1,cnt+1);
					used[i][j]=used[i][j-1]=0;
				}
			}
		}
	}
}
int main() {
	freopen("dengshan.in","r",stdin);
	freopen("dengshan.out","w",stdout);
	scanf("%d %d",&n,&m);
	dfs(1,1,0);
	if(ans==(n*m)/2)printf("%d\n",ans);
	else printf("%d\n",(n*m)/2);

}
