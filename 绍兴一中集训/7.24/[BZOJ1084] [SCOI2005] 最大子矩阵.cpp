#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
#define maxk 10
using namespace std;
typedef long long ll;
int n,m,k;
int a[3][maxn+5];
ll sum[3][maxn+5];
ll f[maxk+5][maxn+5];//m=1 
//f[x][i] 表示选x个矩阵，最后一个矩阵的右端在i处 
ll g[maxk+5][maxn+5][maxn+5];//m=2
//g[x][i][j] 选x个矩阵，第2行选到i处，第2行选到j处 
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[j][i]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	if(m==1){
		for(int x=1;x<=k;x++){
			for(int i=1;i<=n;i++){
				f[x][i]=f[x][i-1];//可以不选 
				for(int j=0;j<i;j++){
					f[x][i]=max(f[x][i],f[x-1][j]+sum[1][i]-sum[1][j]);
				}
			}
		}
		printf("%lld\n",f[k][n]);
	}else{
		for(int x=1;x<=k;x++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[x][i][j]=max(g[x][i-1][j],g[x][i][j-1]);
					for(int u=0;u<i;u++) g[x][i][j]=max(g[x][i][j],g[x-1][u][j]+sum[1][i]-sum[1][u]);
					for(int u=0;u<j;u++) g[x][i][j]=max(g[x][i][j],g[x-1][i][u]+sum[2][j]-sum[2][u]);
					if(i==j){
						for(int u=0;u<i;u++){
							g[x][i][j]=max(g[x][i][j],g[x-1][u][u]+sum[1][i]-sum[1][u]+sum[2][j]-sum[2][u]);
						}
					}
				}
			}
		}
		printf("%lld\n",g[k][n][n]);
	}
}
