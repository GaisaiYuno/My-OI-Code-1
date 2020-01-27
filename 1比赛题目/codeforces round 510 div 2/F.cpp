#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x7f7f7f7f
#define maxn 1000005
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int deg[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int dp[maxn];
int k;
int ans=0;
void dfs(int x,int fa){
	if(deg[x]==1) dp[x]=1;
	else dp[x]=-INF;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			if(dp[x]+dp[y]+1>k){
				ans++;
				dp[x]=min(dp[x],dp[y]+1);
			}
			else dp[x]=max(dp[x],dp[y]+1);
		}
	} 
}

int main(){
	int u,v;
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]!=1){
			dfs(i,0);
			break;
		} 
	}
	printf("%d\n",ans);
} 
