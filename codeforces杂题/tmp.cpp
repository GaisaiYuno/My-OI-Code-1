#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define maxn 50005
#define maxm 500005
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

int n,m;
struct edge {
    int from;
    int to;
    int next;
    int flow;
    int cost;
} E[maxm<<1];
int sz=1;
int head[maxn];
int pre[maxn];
int minf[maxn];
int dist[maxn];
int inq[maxn];
void adde(int u,int v,int w,int c) {
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].flow=w;
    E[sz].cost=c;
    E[sz].next=head[u];
    head[u]=sz;
}
void add_edge(int u,int v,int w,int c){
//	printf("%d->%d vol=%d cost=%d\n",u,v,w,c);
	adde(u,v,w,c);
	adde(v,u,0,-c);
}

int spfa(int s,int t){
    queue<int>q;
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(q));
    q.push(s);
    dist[s]=0;
    inq[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=0;
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(E[i].flow){
//            	printf("%d %d\n",x,y);
                if(dist[y]>dist[x]+E[i].cost){
                    dist[y]=dist[x]+E[i].cost;
                    minf[y]=min(minf[x],E[i].flow);
                    pre[y]=i;
                    if(!inq[y]){
                        inq[y]=1;
                        q.push(y);
                    }
                }
            }
        }
    }
    if(dist[t]==INF) return 0;
    else return 1;
}

void update(int s,int t){
    int x=t;
    while(x!=s){
        int i=pre[x];
        E[i].flow-=minf[t];
        E[i^1].flow+=minf[t];
        x=E[i^1].to;
    }
}

int mcmf(int s,int t){
	int maxcost=0,maxflow=0;
	memset(minf,0x3f,sizeof(minf));
	while(spfa(s,t)){
		update(s,t);
		maxcost+=minf[t]*dist[t];
		maxflow+=minf[t];
	}
	return maxcost;
}

int a[maxn];
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
