#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 250 
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m,q;
ll c[maxn+5];
ll g[maxn+5][maxn+5];
ll dist[maxn+5][maxn+5];
ll dist2[maxn+5][maxn+5];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ll p=0;
				p=max(p,max(dist2[i][k],dist2[k][j]));
				if(dist[i][k]==INF||dist[k][j]==INF||p==INF) continue;
				if(dist[i][k]+dist[k][j]+p<=dist[i][j]+dist2[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					dist2[i][j]=p;
				}
			}
		}
	}
}
int main(){
	int u,v;
	ll w;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) g[i][j]=INF;
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dist2[i][j]=INF;
	}
	for(int i=1;i<=n;i++) dist2[i][i]=c[i];
	
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
		dist2[u][v]=max(c[u],c[v]);
		dist2[v][u]=max(c[u],c[v]);
	}
	memcpy(dist,g,sizeof(g)); 
	
	

	floyd();
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		printf("%lld\n",dist[u][v]+dist2[u][v]);
	}
}
/*
5 7 100
2 
5 
3 
3 
4 
1 2 3 
1 3 2 
2 5 3 
5 3 1 
5 4 1 
2 4 3 
3 4 4 
*/
