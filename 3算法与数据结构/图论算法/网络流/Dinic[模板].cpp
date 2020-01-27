#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 105
#define maxm 10005
#define INF 0x7ffffffff
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,m,s,t;
long long flow[maxm];
int d[maxn];

struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	flow[sz]=w;
}

queue<int>q;
int bfs(int s,int t){
	while(!q.empty()) q.pop();
	memset(d,0,sizeof(d));
	d[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(!d[y]&&flow[i]){
				d[y]=d[x]+1;
				q.push(y);
				if(y==t) return 1;
			}
		}
	}
	return 0;
}

long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long rest=minf;//dinicͬʱ�Ҷ�������·��Ҫ������ͬʱ��ȥ 
	long long k;
	for(int i=head[x];i&&rest;i=E[i].next){
		int y=E[i].to;
		if(d[y]==d[x]+1&&flow[i]){
			k=dfs(y,t,min(rest,flow[i]));
			//Ҫ��restȡmin��������minf����Ϊ����һ������·���Ҫ��С��rest���ü�¼�˼�С���minf 
			if(!k) d[y]=0;//��֦����Ϊk=0˵��y�Ѿ��������ٱ����� 
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
		}
	}
	return minf-rest;//�仯����Ϊ���ӵ����� 
} 

long long dinic(int s,int t){
	long long maxflow=0;
	long long flow=0;
	while(bfs(s,t)){
		while(flow=dfs(s,t,INF)) maxflow+=flow;
	} 
	return maxflow;
} 
int main(){
	int u,v,w;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		w=qread();
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	printf("%lld\n",dinic(s,t));
}
