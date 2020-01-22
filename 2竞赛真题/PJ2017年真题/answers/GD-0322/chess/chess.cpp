#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,cl[110][110],vis[110][110],ans=0x7fffffff;
int a[4]={0,0,-1,1};
int b[4]={1,-1,0,0};
void dfs(int x,int y,int ck,int c,int sum){
	if (x==n&&y==n){
		ans=min(ans,sum);
		return;
	}
	for (int i=0;i<4;++i){
		int nx=x+a[i];
		int ny=y+b[i];
		if (nx<=n&&ny>=1&&nx>=1&&ny<=n){
			if (ck&&cl[nx][ny]){
				if (cl[nx][ny]==c){
					if (vis[nx][ny]>sum){
						vis[nx][ny]=sum;
						dfs(nx,ny,0,cl[nx][ny],sum);
					}
				}
				if (cl[nx][ny]!=c){
					if (vis[nx][ny]>sum+1){
						vis[nx][ny]=sum+1;
						dfs(nx,ny,0,cl[nx][ny],sum+1);
					}
				}
			}
			if (ck==0){
				if (cl[nx][ny]){
					if (c==cl[nx][ny]){
						if (vis[nx][ny]>sum){
							vis[nx][ny]=sum;
							dfs(nx,ny,0,cl[nx][ny],sum);
						}
					}
					if (c!=cl[nx][ny]){
						if (vis[nx][ny]>sum+1){
							vis[nx][ny]=sum+1;
							dfs(nx,ny,0,cl[nx][ny],sum+1);
						}
					}
				}
				if (!cl[nx][ny]){
					if (vis[nx][ny]>sum+2){
						vis[nx][ny]=sum+2;
						dfs(nx,ny,1,c,sum+2);
					}
				}
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			vis[i][j]=0x7fffffff;
		}
	}
	for (int i=1;i<=m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		cl[x][y]=z+1;
	}
	dfs(1,1,0,cl[1][1],0);
	if (ans==0x7fffffff){
		printf("-1");
		return 0;
	}
	printf("%d",ans);
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1 
5 5 0

5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0

5 10
1 1 0
1 2 0
1 3 0
1 5 1
2 2 1
2 4 1
4 2 0
4 4 1
5 3 0
5 5 0
*/
