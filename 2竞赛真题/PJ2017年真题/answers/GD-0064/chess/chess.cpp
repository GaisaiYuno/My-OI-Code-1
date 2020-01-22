#include<cstdio>
#include<algorithm>

using namespace std;
int m,n,a[110][110],f[110][110];

int d[4][2]={
	{1,0},{0,1},{-1,0},{0,-1}
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	#endif
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=0x7fffffff;
	for(int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
//	puts("");
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
//		puts("");
//	}
	f[1][1]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==0x7fffffff) continue;
			for(int k=0;k<4;k++){
				int x=i+d[k][0];
				int y=j+d[k][1];
				if(a[i][j]==a[x][y]&&a[i][j]) f[x][y]=min(f[x][y],f[i][j]);
				else if(a[i][j]&&a[x][y]) f[x][y]=min(f[x][y],f[i][j]+1);
				else if(a[i][j]&&f[i][j]+2<=f[x][y]){
					f[x][y]=f[i][j]+2;
					for(int h=0;h<4;h++){
						int dx=x+d[h][0];
						int dy=y+d[h][1];
						if(a[i][j]==a[dx][dy]&&a[i][j]) f[dx][dy]=min(f[dx][dy],f[x][y]);
						else if(a[i][j]&&a[dx][dy]) f[dx][dy]=min(f[dx][dy],f[x][y]+1);
					}
				}
			}
		}
	}
//	puts("");
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++) printf("%d ",f[i][j]);
//		puts("");
//	}
//	puts("");
	if(f[m][m]!=0x7fffffff) printf("%d\n",f[m][m]);
	else puts("-1");
	return 0;
}
