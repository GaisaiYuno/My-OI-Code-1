//http://codevs.cn/problem/2236/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#define maxn 305
#define maxv 10005
#define maxe 500005
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-14
using namespace std;
int n,k;
struct edge{
    int from;
    int to;
    int next;
    double flow;
    double cost;
}E[maxe<<1];
int head[maxv];
int sz=1;
void add_edge(int u,int v,double w,double c){
	c=-log(c);
#ifdef DEBUG
	printf("%d->%d vol=%.2f cost=%.2f\n",u,v,w,c);
#endif
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

double dist[maxv];
double minf[maxv];
int pre[maxv];
int inq[maxv]; 
bool spfa(int s,int t){
    for(int i=s;i<=t;i++) dist[i]=INF;
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
            if(fabs(E[i].flow)>eps){
                if(dist[y]>dist[x]+E[i].cost&&fabs(dist[y]-dist[x]-E[i].cost)>eps){
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
//    	printf("%d ",x);
        int i=pre[x];
        E[i].flow-=minf[t];
        E[i^1].flow+=minf[t];
        x=E[i^1].to;
    }
}

double mcmf(int s,int t){
    for(int i=s;i<=t;i++) minf[i]=INF;
    double mincost=0;
    while(spfa(s,t)){
//    	printf("working %lf\n",minf[t]);
        update(s,t);
        mincost+=dist[t]*minf[t];
    }
    return exp(-mincost);
}
 
int ans[30];
double as[maxn];
double am[maxn];
void myprint(double x,double sigd){
	int sz=0;
	int i=0;
	ans[0]=0;
	while(1){
		x*=10;
		int z=int(x);
		x-=int(x);
		ans[++sz]=z;
		if(z!=0||i!=0) i++; //从最左边的0开始数 
		if(i>=sigd+1) break;//四舍五入，保留多一位 
	}
	if(ans[sz]>=5){
		ans[sz-1]++;
	}
	for(int j=sz-1;j>0&&ans[j]>=10;j--){
		ans[j-1]+=ans[j]/10;
		ans[j]%=10;
		j--;
	}
	printf("%d.",ans[0]);
	for(int i=1;i<=sz-1;i++) printf("%d",ans[i]);
	printf("\n");
}
int main(){
#ifdef FILE_IO
	freopen("3.in","r",stdin);
#endif
	int xx,u,v;
	double suv,muv;
	scanf("%d %d",&n,&k);
	int s0=0,s=n+1,t=n+2;
	add_edge(s0,s,k,1);
	for(int i=1;i<=n;i++){
		scanf("%lf",&as[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lf",&am[i]);
		if(am[i]>0){
			add_edge(s,i,am[i],as[i]);
		} 
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&xx);
		if(xx) add_edge(i,t,k,1);
	}
	while(scanf("%d %d",&u,&v)!=EOF){
		if(u==-1&&v==-1) break;
		scanf("%lf %lf",&suv,&muv);
		add_edge(u,v,muv,suv);
		add_edge(v,u,muv,suv);
	}
	myprint(mcmf(s0,t),5);
	//保留5位有效数字	
}
	
