#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define maxn 105
#define maxv 10005
using namespace std;
int n,m;
vector<int>G[maxn];
vector<int>T[maxn];
int tim=0;
int cnt=0;
int dfn[maxn];
int low[maxn];
int ins[maxn];
int belong[maxn];
long long tw[maxn];
long long tv[maxn];
long long w[maxn];
long long v[maxn];
stack<int>s;
void tarjan(int x){
	s.push(x);
	ins[x]=1;
	dfn[x]=low[x]=++tim;
	int t=G[x].size();
	for(int i=0;i<t;i++){
		int y=G[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		cnt++;
		int y;
		do{
			y=s.top();
			s.pop();
			ins[y]=0;
			belong[y]=cnt;
			w[cnt]+=tw[y];
			v[cnt]+=tv[y]; 
		}while(x!=y);
	}
}

int in[maxn];
void graph_to_tree(){
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		int t=G[i].size();
		for(int j=0;j<t;j++){
			int k=G[i][j];
			if(belong[i]!=belong[k]){
				T[belong[i]].push_back(belong[k]);
				in[belong[k]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(in[i]==0){
			T[cnt+1].push_back(i);
		}
	}
}

long long dp[maxn][maxv];
void dfs(int x,int fa){
	int sz=T[x].size();
	for(int i=0;i<sz;i++){
		int y=T[x][i];
		if(y==fa) continue;
		dfs(y,x);
		for(int j=m-w[x];j>=0;j--){
			for(int k=0;k<=j;k++){
				dp[x][j]=max(dp[x][j],dp[x][k]+dp[y][j-k]);
			}
		}
	}
	for(int j=m;j>=0;j--){
		if(j>=w[x]) dp[x][j]=dp[x][j-w[x]]+v[x];
		else dp[x][j]=0;
	} 
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&tw[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&tv[i]);
	}
	int u;
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		if(u==0) continue;
		else G[u].push_back(i);
	} 
	graph_to_tree();
	dfs(cnt+1,0);
	printf("%lld\n",dp[cnt+1][m]);
} 
