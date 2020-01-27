#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 305
using namespace std;
int n,m;
long long dist[maxn][maxn];
int main() {
	int u,v;
	long long w;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%I64d",&dist[i][j]);
		}
	}
	scanf("%d",&m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %I64d",&u,&v,&w);
		long long sum=0;
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				dist[j][k]=min(dist[j][k],min(dist[j][v]+dist[u][k]+w,dist[j][u]+dist[v][k]+w));
			}
		}
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				sum+=dist[j][k];
			}
		}
		printf("%I64d ",sum/2);
	}
}
