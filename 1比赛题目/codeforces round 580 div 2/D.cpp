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
				//·ÀÖ¹¼Ó·¨Òç³ö 
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

