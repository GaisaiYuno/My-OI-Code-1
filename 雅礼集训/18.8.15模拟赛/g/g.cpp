#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 2005
#define maxm 2005
#define mod 998244353
using namespace std;
int n,m,L;
struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
int size=0;
int head[maxn];
int in[maxn],out[maxn];
int w[maxn];
long long dp[maxn][maxn];
void add_edge(int u,int v){
	size++;
	E[size].to=v;
	E[size].from=u;
	E[size].next=head[u];
	head[u]=size;
}
queue<int>q;
int main(){
//	freopen("g0.in","r",stdin);
	int u,v;
	scanf("%d %d %d",&n,&m,&L);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		in[v]++;
		out[u]++;
	}
//	for(int i=1;i<=n;i++){
//		if(in[i]==0){
//			q.push(i);
//			dp[i][0]=1;
//			dp[i][w[i]]=1;
//		}
//	}
	q.push(1);
	dp[1][0]=1;
	dp[1][w[1]]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
//		printf("%d\n",x);
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
//			printf("%d\n",y);
			for(int j=0;j<=L;j++){
				dp[y][j]+=dp[x][j];
				dp[y][j]%=mod;
				if(j+w[y]<=L) dp[y][j+w[y]]+=dp[x][j];
				dp[y][j+w[y]]%=mod;
			}
			in[y]--;
			if(in[y]==0) q.push(y);
		}
	}
	long long ans=0;
	for(int i=0;i<=L;i++){
		ans+=dp[n][i]%mod;
		ans%=mod;
	}
	printf("%lld",ans);
}
