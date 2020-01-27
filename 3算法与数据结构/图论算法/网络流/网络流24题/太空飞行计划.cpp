/*
Problem:太空飞行计划「网络流 24 题」
Source:http://111.230.183.91/problem/159
Description: 
对于每一个实验，从源点到实验连一条流量为赞助商支付的钱的边；
对于每一个仪器，从仪器到汇点连一条流量为仪器花费的边。对于每一个实验所需要的仪器，
在实验与仪器之间连一条流量无穷大的边。在这张图上跑一边最大流，就可以得到最小的花费，再用总赞助商的支付钱减去这个花费即可。
为什么这样是对的呢？
从源点到实验的边保证了赞助商资助该实验不会超过赞助商的钱，而从仪器到汇点的边则保证了仪器最多只会花费掉这么多的钱
那么最后如何统计答案呢？
由于我们使用的是Dinic求最大流，那么我们可以直接借助层次图的depth数组来求解。
因为最后要选取的实验必须是盈利的，所以从源点到盈利的实验的边一定一不满流的，那么也就是说在最后一遍bfs中一定会分配深度，
那么我们只要找出depth不为0的实验即可。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 110
#define maxm 10005 
#define INF 0x7fffffff
using namespace std;
int n,m;
int p[maxn];
int c[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
long long flow[maxm];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
//	printf("%d->%d %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	flow[sz]=w;
}

int deep[maxn];
int bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(flow[i]&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
				if(y==t) return 1;
			} 
		}
	}
	return 0;
}

long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(flow[i]&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,flow[i]));
			if(k==0) deep[y]=0;
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
		}
	}
	return minf-rest;
}

long long dinic(int s,int t){
	long long maxflow,nowflow;
	maxflow=0;
	while(bfs(s,t)){
		while(nowflow=dfs(s,t,INF)){
			maxflow+=nowflow;
		}
	}
	return maxflow;
}

vector<int>ans;
int main(){
	int x;
	char ch;
	long long tot=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
		tot+=p[i];
		while(scanf("%d%c",&x,&ch)!=EOF){
			add_edge(i,x+m,INF);
			add_edge(x+m,i,0);
			if(ch=='\n'||ch=='\r') break;
		}
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=m;i++){
		add_edge(0,i,p[i]);
		add_edge(i,0,0);
	} 
	for(int i=1;i<=n;i++){
		add_edge(i+m,m+n+1,c[i]);
		add_edge(m+n+1,i+m,0);
	}
	long long res=tot-dinic(0,m+n+1);
	for(int i=1;i<=m;i++){
        if(deep[i]!=0){
        	ans.push_back(i);
		}
    }
    for(int i=0;i<ans.size();i++){
    	printf("%d",ans[i]);
    	if(i!=ans.size()-1) printf(" ");
    	else printf("\n");
	}
	ans.clear();
    for(int i=m+1;i<=m+n;i++){
        if(deep[i]!=0){
        	ans.push_back(i-m);
		}
    }
    for(int i=0;i<ans.size();i++){
    	printf("%d",ans[i]);
    	if(i!=ans.size()-1) printf(" ");
    	else printf("\n");
	}
	printf("%lld\n",res);
}

