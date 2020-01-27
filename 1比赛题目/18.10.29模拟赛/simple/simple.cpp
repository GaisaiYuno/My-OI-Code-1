#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15
using namespace std;
int n,m;
bool flag=false;
int ans=0;
int a[maxn][maxn];
int res[maxn][maxn];
int rowsum[maxn];
int colsum[maxn];
int vis_row[maxn][maxn];
int vis_col[maxn][maxn];
void init() {
	memset(a,0,sizeof(a));
	memset(rowsum,0,sizeof(rowsum));
	memset(colsum,0,sizeof(colsum));
	memset(res,0,sizeof(res));
	memset(vis_row,0,sizeof(vis_row));
	memset(vis_col,0,sizeof(vis_col));
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&rowsum[i]);
	for(int i=1; i<=m; i++) scanf("%d",&colsum[i]);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0) {
				vis_row[i][a[i][j]]=1;
				vis_col[j][a[i][j]]=1;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]) {
				rowsum[i]-=a[i][j];
				colsum[j]-=a[i][j];
			}
		}
	}
	ans=0;
	flag=false;
}

void debug(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
} 
void dfs(int x,int y) {
//	debug();
	if(a[x][y]) {
		if(x==n&&y==m) {
			if(rowsum[x]==0&&colsum[y]==0) {
				ans++;
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						res[i][j]=a[i][j];
					}
				}
				if(ans>=2) {
					flag=true;
				}
			}
		} else if(y==m) {
			if(rowsum[x]==0) {
				dfs(x+1,1);
				if(flag) return;
			}
		} else if(x==n) {
			if(colsum[y]==0) {
				dfs(x,y+1);
				if(flag) return;
			}
		} else {
			dfs(x,y+1);
			if(flag) return;
		}
	} else {
		if(rowsum[x]>9*(m-y+1)) return;
		for(int i=1; i<=9; i++) {
			if(vis_row[x][i]||vis_col[y][i]) continue;
			a[x][y]=i;
			vis_row[x][i]=1;
			vis_col[y][i]=1;
			rowsum[x]-=i;
			colsum[y]-=i;
			if(x==n&&y==m) {
				if(rowsum[x]==0&&colsum[y]==0) {
					ans++;
					for(int i=1; i<=n; i++) {
						for(int j=1; j<=m; j++) {
							res[i][j]=a[i][j];
						}
					}
					if(ans>=2) {
						flag=true;
					}
				}
			} else if(y==m) {
				if(rowsum[x]==0) {
					dfs(x+1,1);
					if(flag) return;
				}
			} else if(x==n) {
				if(colsum[y]==0) {
					dfs(x,y+1);
					if(flag) return;
				}
			} else {
				dfs(x,y+1);
				if(flag) return;
			}
			a[x][y]=0;
			vis_row[x][i]=0;
			vis_col[y][i]=0;
			rowsum[x]+=i;
			colsum[y]+=i;
		}
	}
}
int main() {
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		init();
		dfs(1,1);
		if(ans>=2) {
			printf("Not unique.\n");
		} else if(ans==1) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					printf("%d ",res[i][j]);
				}
				printf("\n");
			}
		} else {
			printf("No answer.\n");
		}
	}
	return 0;
}
