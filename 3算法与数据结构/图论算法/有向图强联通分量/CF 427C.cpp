#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#define maxn 100005
#define maxm 300005
#define mod 1000000007
#define INF 0x7fffffff
using namespace std;
int n,m;
int cost[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
} 

stack<int>s;
vector<int>scc[maxn]; 
int ins[maxn];
int dfn[maxn];
int low[maxn];
int num=0;
int scc_cnt=0;
void tarjan(int x){
	ins[x]=1;
	s.push(x);
	dfn[x]=low[x]=++num;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		scc_cnt++;
		int y;
		do{
			y=s.top();
			s.pop();
			ins[y]=0;
			scc[scc_cnt].push_back(y);
		}while(x!=y); 
	}
}

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	long long ways=1;
	long long sum=0;
	int minv=INF,mincnt=0;
	int scc_sz;
	for(int i=1;i<=scc_cnt;i++){
		scc_sz=scc[i].size();
		minv=INF;
		mincnt=0;
//		printf("scc %d :",i);
		for(int j=0;j<scc_sz;j++){
//			printf("%d ",scc[i][j]);
			minv=min(minv,cost[scc[i][j]]);
		}
//		printf("\n");
		for(int j=0;j<scc_sz;j++){
			if(cost[scc[i][j]]==minv) mincnt++;
		}
		ways=ways*mincnt%mod;
		sum+=minv;
	}
	printf("%I64d %I64d\n",sum,ways);
}
