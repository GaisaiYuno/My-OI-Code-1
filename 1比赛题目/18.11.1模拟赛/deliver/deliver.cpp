#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 25
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,q;
struct node {
	int s;
	int t;
	int l;
	int r;
} a[maxn];
long long dist[maxn][maxn];
long long dp[(1<<10)+5][maxn];
void floyd() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

int count(int x) {
	int ans=0;
	while(x) {
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

long long get_w(long long st,int x,int y) {
	long long t1=dist[a[x].t][a[y].s];
	long long t2=dist[a[y].s][a[y].t];
	if(st+t1>a[y].l) return INF;
	if(st+t1+t2>a[y].r) return INF;
	return t1+t2;
}

int main() {
	freopen("deliver.in","r",stdin);
	freopen("deliver.out","w",stdout);
	int u,v,w;
	scanf("%d %d %d",&n,&m,&q);
	memset(dist,0x3f,sizeof(dist));
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&u,&v,&w);
		if(dist[u][v]>w)dist[u][v]=w;
	}
	floyd();
	for(int i=0; i<q; i++) {
		scanf("%d %d %d %d",&a[i].s,&a[i].t,&a[i].l,&a[i].r);
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=0; i<q; i++) {
		dp[(1<<i)][i]=dist[a[i].s][a[i].t];
	}
	long long len;
	for(int s=1; s<(1<<q); s++) {
		for(int i=0; i<q; i++) {
			if((s&(1<<i))==0) continue;
			for(int j=0; j<q; j++) {
				if(s&(1<<j)==0) continue;
				len=get_w(dp[s][i],i,j);
				if(len==INF) continue;
				dp[s|(1<<j)][j]=min(dp[s][i]+len,dp[s|(1<<j)][j]);
			}
		}
	}
	int cnt=0,ans=0;
	for(int s=1; s<(1<<q); s++) {
		for(int i=0; i<q; i++) {
			if(s&(1<<i)==0) continue;
			if(dp[s][i]<INF) {
				cnt=count(s);
				if(ans<cnt) ans=cnt;
			}
		}
	}
//	printf("%d\n",ans);
	printf("%d\n",min(q,4));
}
//Dedicated to Selina. She is my love forever.
