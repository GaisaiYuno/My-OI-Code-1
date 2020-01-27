#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cassert>
#define MAXN 255
using namespace std;
int vis[MAXN],dis[MAXN];
int G[MAXN][MAXN];
inline int read(){
	char ch=getchar();
	int x=0,f=1;
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int n;
inline void spafather(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	vis[s]=true;
	queue<int>Q;
	while (Q.size()) Q.pop();
	Q.push(s);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		vis[v]=false;
		for (int i=1;i<=n;++i){
			int u=i;
			int len=G[v][i];
			if (len==0) continue;
			if (dis[u]>dis[v]+len){
				dis[u]=dis[v]+len;
				if (!vis[u]){
					vis[u]=true;
					Q.push(u);
				}
			}
		}
	}
}
int main(){
	freopen("roadblock.in","r",stdin);
	freopen("roadblock.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	while (m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=G[v][u]=w;
	}
	spafather(1);
	int org=dis[n];
	int ans=-0x3f3f3f3f;
	for (register int i=1;i<=n-1;++i){
		for (register int j=i+1;j<=n;++j){
			int u=i,v=j;
			if (G[u][v]){
				G[u][v]*=2;
				G[v][u]*=2;
				spafather(1);
				ans=max(ans,dis[n]);
				G[u][v]/=2;
				G[v][u]/=2;
			}
		}
	}
	printf("%d\n",ans-org);
}
//in on under in front of behind next to between
