#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 10000
#define maxm 200000
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x){
    x=0;
    int sign=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x=x*sign;
}

struct edge{
	int from;
	int to;
	int next;
	int flow;
	int cost;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w,int c){
//	printf("%d->%d flow=%d cost=%d\n",u,v,w,c);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	E[sz].cost=c; 
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	E[sz].cost=-c; 
	head[v]=sz;
}


int d[maxn+5];
bool inq[maxn+5];
void spfa(int s,int t){
	queue<int>q;
	for(int i=s;i<=t;i++){
		d[i]=-INF;
		inq[i]=0;
	}
	d[t]=0;
	q.push(t);//倒着跑最短路 
	inq[t]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i^1].flow&&d[y]<d[x]+E[i^1].cost){
				d[y]=d[x]+E[i^1].cost;
				if(!inq[y]){
					 q.push(y);
					 inq[y]=1;
				}
			}
		}
	}
}

bool vis[maxn+5];
int aug(int x,int s,int t,int minf,int &flow,int &cost){
	vis[x]=1;
	if(x==t){
		flow+=minf;
		cost+=minf*d[s];//因为最短路是倒着跑的,不会爆掉 
		return minf;
	}
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]&&E[i].flow&&d[x]==d[y]+E[i].cost){
			k=aug(y,s,t,min(rest,E[i].flow),flow,cost);
			E[i].flow-=k;
			E[i^1].flow+=k;
			rest-=k;
//			if(k==0) d[y]=INF; 一般的多路增广里的这句话会影响zkw的重标号，所有不能写 
			if(rest==0) break;
		}
	}
	return minf-rest;
} 
bool modify(int s,int t){
	if(vis[t]) return 1;
	int delta=-INF;
	for(int i=2;i<=sz;i++){
		int x=E[i].from;
		int y=E[i].to;
		if(E[i].flow&&vis[x]&&!vis[y]) delta=max(delta,d[y]+E[i].cost-d[x]);
	}
	if(delta==-INF) return 0;
	for(int i=s;i<=t;i++){
		if(vis[i]) d[i]+=delta;
	}
	return 1;
}


int mcmf(int s,int t){
	int flow=0,cost=0;
//	for(int i=s;i<=t;i++) d[i]=0;
	spfa(s,t);
	do{
		for(int i=s;i<=t;i++) vis[i]=0;
		aug(s,s,t,INF,flow,cost);
	}while(modify(s,t));
	return cost;
}

int n,m;
int a[maxn+5];
int main(){
	int u,v,w;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);		
	}
	for(int i=1;i<=m;i++){
		qread(u);
		qread(v);
		qread(w);
		add_edge(u,v+1,INF,w); 
	}
	int s=0,t=n+2;
	for(int i=1;i<=n+1;i++){
		int c=a[i]-a[i-1];
		if(c>=0){
			add_edge(s,i,c,0);
		}else{
			add_edge(i,t,-c,0);
		}
	}
	for(int i=1;i<=n;i++) add_edge(i,i+1,INF,0);
	printf("%d\n",mcmf(s,t));
}
