#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1005
#define maxm 90005
#define INF 99999999
using namespace std;
int dis[maxn][maxn];
int n,m;
void floyd() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}

}
int start[maxm];
int end[maxm];
int main() {
	freopen("testdata (13).in","r",stdin);
	int u,v,w;
	int s;
	scanf("%d %d",&n,&s);
	for(int i=0; i<=1000; i++) {
		for(int j=0; j<=1000; j++) {
			if(i==j) dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(int i=1; i<=n-1; i++) {
		scanf("%d %d %d",&u,&v,&w);
		dis[u][v]=dis[v][u]=w;
	}
	floyd();
	int cnt=0;
	int ans=INF,ecc=0;
	int len=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
//			printf("%d ",dis[i][j]);
			if(dis[i][j]!=INF){
//				len=max(len,dis[i][j]);
				if(len<dis[i][j]) len=dis[i][j];
			}
		}
	}
	printf("%d\n",len); 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(dis[i][j]==len) {
				start[++cnt]=i;
				end[cnt]=j;
//				printf("%d %d\n",i,j);
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			ecc=0; 
			for(int u=1; u<=cnt; u++) {
				if(dis[start[u]][i]+dis[i][j]+dis[j][end[u]]==len&&dis[i][j]<=s&&dis[i][j]!=INF) {
					for(int k=1; k<=n; k++) {
						if(k!=i&&k!=j) ecc=max(ecc,(dis[k][i]+dis[k][j]-dis[i][j])/2);
//						printf("%d\n",ecc);
					}
					ans=min(ans,ecc);
				}
			}
		}
	}

	printf("%d\n",ans);
//	printf("%d\n",tmp2.t);

}
