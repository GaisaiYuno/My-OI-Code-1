## [Codeforces 1205B]Shortest Cycle(最小环)

### 题面

给出n个正整数$a_i$,若$a_i \& a_j \neq 0$，则连边$(i,j)$（注意i->j的边和j->i的边看作一条。问连边完图的最小环长度

$n \leq 10^5,0 \leq a_i \leq 10^{18}$

### 分析

我们按位考虑.显然满足第i位为1的所有数两两之间都有边，构成一个完全图.

统计第i位为1的数，如果第i位为1的数超过2个，就直接输出3（这3个构成一个最小环)。如果有2个，就连一条边.注意点的编号要离散化，因为前面可能有很多0，导致满足条件的(i,j)编号很大。

因为要建图的时候，每一位最多建一条边，边数<64,点数<128,floyd求最小环$O(n^3)$可以卡过

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define maxv 1000
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
ll a[maxn+5];
vector<int>vis[70];
int cnt=0;
int tp[maxn+5];
ll ans=0;
ll edge[maxv+5][maxv+5];
ll dist[maxv+5][maxv+5];
void floyd(){
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				if(dist[i][j]==INF||edge[i][k]==INF||edge[k][j]==INF) continue;
				//防止加法溢出 
				if(dist[i][j]+edge[i][k]+edge[k][j]<ans){
					ans=dist[i][j]+edge[i][k]+edge[k][j];
				}
			} 
		}
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(ll i=0;i<64;i++){
		for(int j=1;j<=n;j++){
			if(a[j]&(1ll<<i)) vis[i].push_back(j);
		}
	}
	for(int i=0;i<64;i++){
		if(vis[i].size()>2){
			printf("3\n");
			return 0;
		}
	}
	for(int i=0;i<64;i++){
		if(vis[i].size()==2){
			tp[++cnt]=vis[i][0];
			tp[++cnt]=vis[i][1];
		}
	}
	sort(tp+1,tp+1+cnt);
	cnt=unique(tp+1,tp+1+cnt)-tp-1;
	memset(edge,0x3f,sizeof(edge));
	memset(dist,0x3f,sizeof(dist));
	ans=INF;
	for(int i=0;i<64;i++){
		if(vis[i].size()==2){
			int u=lower_bound(tp+1,tp+1+cnt,vis[i][0])-tp;
			int v=lower_bound(tp+1,tp+1+cnt,vis[i][1])-tp;
//						printf("%d %d\n",u,v);
			edge[u][v]=edge[v][u]=1;
		}
	}
	memcpy(dist,edge,sizeof(edge));
	floyd();
	if(ans==INF) printf("-1\n");
	else printf("%d\n",ans); 
}

```



