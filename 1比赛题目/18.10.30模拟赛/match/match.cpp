#include<iostream>
#include<cstdio>
#define maxn 10
using namespace std;
int n;
int a[maxn][maxn];
int mark[maxn][maxn];
int rowsum[maxn];
int f[maxn][maxn][maxn];
int score[3]= {3,1,0};
int rev[3]= {0,1,3};
int ans=0;
void dfs(register int x,register int y) {
	if(mark[x][y]||x==y) {
		if(rowsum[x]<0) return;
		if(rowsum[y]<0) return;
		if(y==n&&(rowsum[x]==2||rowsum[x]>3)) return;
		if(x==n&&y==n) {
			if(rowsum[x]==0) {
				ans++;
//				debug();
				return;
			} else return;
		} else if(y==n) {
			if(rowsum[x]==0) dfs(x+1,1);
			else return;
		} else {
			dfs(x,y+1);
		}
	} else {
		if(rowsum[x]<0) return;
		if(y==n&&(rowsum[x]==2||rowsum[x]>3)) return;
		for(register int i=0; i<3; i++) {
			a[x][y]=score[i];
			a[y][x]=rev[i];
			mark[x][y]=mark[y][x]=1;
			rowsum[x]-=score[i];
			rowsum[y]-=rev[i];
			if(rowsum[y]<0) {
				a[x][y]=a[y][x]=0;
				mark[x][y]=mark[y][x]=0;
				rowsum[x]+=score[i];
				rowsum[y]+=rev[i];
				continue;
			}
			if(x==n&&y==n) {
				if(rowsum[x]==0) {
					ans++;
//					debug();
					a[x][y]=a[y][x]=0;
					mark[x][y]=mark[y][x]=0;
					rowsum[x]+=score[i];
					rowsum[y]+=rev[i];
					return;
				}
			} else if(y==n) {
				if(rowsum[x]==0) {
					dfs(x+1,1);
					a[x][y]=a[y][x]=0;
					mark[x][y]=mark[y][x]=0;
					rowsum[x]+=score[i];
					rowsum[y]+=rev[i];
					return;
				}
			} else {
				dfs(x,y+1);
			}
			a[x][y]=a[y][x]=0;
			mark[x][y]=mark[y][x]=0;
			rowsum[x]+=score[i];
			rowsum[y]+=rev[i];
		}
	}
}
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&rowsum[i]);
	}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}


