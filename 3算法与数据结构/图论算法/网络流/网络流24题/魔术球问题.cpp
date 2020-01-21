/*
Problem:魔术球问题 
Source:https://www.luogu.org/problemnew/show/P2765
Description：
每个球向可以组成的完全平方数连边，会连出一个有向无环图
柱子上的球对应图上的路径
相当于最小路径点覆盖
求出拆点二分图，再用n-最大匹配数即可 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define maxn 100000
#define maxm 100000
#define INF 0x7fffffff
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxm*4+5];
long long flow[maxm*4+5];
int head[maxn*2+5];
int sz=1;
void add_edge(int u,int v,int w){
//	if(u<v)printf("%d->%d %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	flow[sz]=w;
}

int deep[maxn*2+5];
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

int pre[maxn];
long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(flow[i]&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,flow[i]));
			if(k==0){
				deep[y]=0;
				continue; 
			}
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
			pre[x/2]=y/2;
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

int is_sqr(int x){
	if(sqrt(x)==(double)x) return 1;
	else return 0; 
}


int tmp[maxn*2+5];
int vis[maxn*2+5];
int s=0,t=maxn+1;
void print_ans(int x){
	for(int i=x;i!=0&&i!=t/2;i=pre[i]){
		vis[i]=1;
		printf("%d ",i);
	}
	printf("\n");
}
int main(){
	scanf("%d",&n);
	int pil=0,ball=0;

	while(pil<=n){
		ball++;
		add_edge(s,ball*2,1);
		add_edge(ball*2+1,s,0);
		add_edge(ball*2+1,t,1);
		add_edge(t,ball*2+1,0);
		for(int i=sqrt(ball)+1;i*i<(ball*2);i++){
			add_edge((i*i-ball)*2,ball*2+1,1);
			add_edge(ball*2+1,(i*i-ball)*2,0);
		}
		int ans=dinic(s,t);
		if(!ans){
			tmp[++pil]=ball;
		}
	} 
	printf("%d\n",ball-1);
	for(int i=1;i<=n;i++){
		print_ans(tmp[i]);
	}
	
}

