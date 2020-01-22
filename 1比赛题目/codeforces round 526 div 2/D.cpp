//dp[x]表示以i结尾的路径的最大值
//分两种情况讨论 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 300005
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
	long long len;
}E[maxn<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v,long long w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
} 

long long ans;
long long add[maxn];
long long dp[maxn];
void dfs(int x,int fa){ 
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to; 
		if(y!=fa){
			dfs(y,x);
			long long tmp=dp[y]-E[i].len;
			ans=max(ans,tmp+dp[x]+add[x]);
			dp[x]=max(dp[x],tmp);
		}
	} 
	dp[x]+=add[x];
	ans=max(ans,dp[x]);
}

int main(){
	int u,v;
	long long w;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&add[i]);
	for(int i=1;i<n;i++){
		scanf("%d %d %I64d",&u,&v,&w); 
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
}
