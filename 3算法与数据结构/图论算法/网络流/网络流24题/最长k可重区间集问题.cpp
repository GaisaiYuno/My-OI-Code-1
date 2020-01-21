#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm> 
#define maxn 100005
#define maxm 500005
#define INF 0x3f3f3f3f3f3f3f3f
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

int n,k;
struct edge{
    int from;
    int to;
    int next;
    long long flow;
    long long cost;
}E[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,long long w,long long c){
//	printf("%d->%d vol=%d cost=%d\n",u,v,w,c);
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

long long dist[maxn];
long long minf[maxn];
int pre[maxn];
int inq[maxn]; 
bool spfa(int s,int t){
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(inq));
    queue<int>q;
    q.push(s);
    inq[s]=1;
    dist[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=0; 
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(E[i].flow){
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

long long EK(int s,int t){
    memset(minf,0x3f,sizeof(minf));
    long long mincost=0;
    while(spfa(s,t)){
        update(s,t);
        mincost+=dist[t]*minf[t];
    }
    return mincost;
}

struct segment{
    int l;
    int r;
    int len;
}a[maxn];
int tmp[maxn];
int main(){
    int sect;
    int s,t;
    qread(n);
    qread(k);
    sect=0;
    for(int i=1;i<=n;i++){
        qread(a[i].l);
        qread(a[i].r);
        if(a[i].r<a[i].l) swap(a[i].l,a[i].r); //l>r时的特判 
        tmp[++sect]=a[i].l;
        tmp[++sect]=a[i].r; 
        a[i].len=a[i].r-a[i].l;
    }
    sort(tmp+1,tmp+1+sect);
    int m=unique(tmp+1,tmp+1+sect)-tmp-1;
    s=t=0;
    for(int i=1;i<=n;i++){
        a[i].l=lower_bound(tmp+1,tmp+1+m,a[i].l)-tmp;//这里是m，不是n 
        a[i].r=lower_bound(tmp+1,tmp+1+m,a[i].r)-tmp;
        add_edge(a[i].l,a[i].r,1,-a[i].len);
    } 
    for(int i=1;i<m;i++){
    	add_edge(i,i+1,INF,0);
	}
	s=0;
	t=m+1;
	add_edge(s,1,k,0);
	add_edge(m,t,k,0);
	printf("%lld\n",-EK(s,t));
}
