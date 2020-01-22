////http://119.29.55.79/contest/94/problem/3  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 17
#define maxm 1000
using namespace std;
typedef long long ll;
int count_bit(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

int n,m;
int g1[maxn+5][maxn+5];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

bool is_del[maxn+5];
ll dp[maxn+5][maxn+5];
void dfs(int x,int fa){
	for(int i=1;i<=n;i++){
		if(is_del[i]) dp[x][i]=0;
		else dp[x][i]=1;
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			for(int j=1;j<=n;j++){
				if(is_del[j]) continue;
				ll sum=0;
				for(int k=1;k<=n;k++){
					if(g1[j][k]&&!is_del[k]) sum+=dp[y][k];
				}
				dp[x][j]*=sum;
			}
		}
	}
}

int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		g1[u][v]=g1[v][u]=1;
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	ll ans=0;	
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))) is_del[j]=1;
			else is_del[j]=0;
		}
		dfs(1,0);
		ll sum=0;
		for(int j=1;j<=n;j++) sum+=dp[1][j];
		if(count_bit(i)%2==1) ans-=sum;
		else ans+=sum;
	}
	printf("%lld\n",ans);
}
