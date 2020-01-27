/*
For my love Selina
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 45
using namespace std;
int n,m,q;
int a[maxn][maxn];
int sum[maxn][maxn];
int f[maxn][maxn][maxn][maxn];
int g[maxn][maxn][maxn][maxn];
void ini(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]; 
		}
	}
}

int query(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

void debug(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				for(int u=1;u<=m;u++){
					printf("(%d,%d,%d,%d)",&f[i][j][k][u]);
				}
			}
		}
	}
}
int main(){
	int _a,b,c,d;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	ini();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int u=i;u<=n;u++){
				for(int v=j;v<=m;v++){
					if(query(i,j,u,v)==0) f[i][j][u][v]=f[i][j][u][v-1]+f[i][j][u-1][v]-f[i][j][u-1][v-1]+1;
					else f[i][j][u][v]=f[i][j][u][v-1]+f[i][j][u-1][v]-f[i][j][u-1][v-1];
				}
			}
		}
	} 
//	debug();
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			for(int u=i;u<=n;u++){
				for(int v=j;v<=m;v++){
					g[i][j][u][v]=g[i+1][j][u][v]+g[i][j+1][u][v]-g[i+1][j+1][u][v]+f[i][j][u][v];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d %d %d",&_a,&b,&c,&d);
		printf("%d\n",g[_a][b][c][d]);
	}
}
