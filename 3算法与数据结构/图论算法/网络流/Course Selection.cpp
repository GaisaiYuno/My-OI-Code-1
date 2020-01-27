/*
Problem:Course Selection
Source:https://vjudge.net/problem/CodeChef-RIN
Description:
最大化课程分数之和
得分最大->扣分最小，可以假设满分为100分，最小化扣分之和
用y[i][j]表示课程i在学期j的扣分，x[i][j]=-1时y[i][j]=INF
 对于每个学科i建m个点
 S向(i,1)链INF.(i,j)向(i,j+1)连y[i][j]，(i,m)向t连一条边，容量INF 
 为了让每个学科的扣分只需选择一个，每门学科自己应当是一条链（串联）；
 不同学科的扣分累加，那么不同学科应该是若干条链（并联）。
 这样割边就是扣掉那节课对应的分数，表示选择了在那时上那门课。
 求最小割
 
 考虑 前置课程要求
 若a是b前置课程，则a的割边在b前面
 从S向(b,1)连INF，对于2<=j<=m，从（a,j-1)向（b,j)连一条INF
 这样如果a的割边在b后面，这样图割不断，因为还有那条INF的边 

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 105
#define maxn 200005
#define maxm 200005
#define INF 0x7fffffff
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
int n,m,k;
int xx[maxc][maxc];

struct edge{
    int from;
    int to;
    int next;
}E[maxm<<1];
long long flow[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
//	if(u<v) printf("%d %d %d\n",u,v,w);
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].next=head[u];
    flow[sz]=w;
    head[u]=sz;
    
    sz++;
    E[sz].from=v;
    E[sz].to=u;
    E[sz].next=head[v];
    flow[sz]=0;
    head[v]=sz;
}


int deep[maxn];
queue<int>q;
int bfs(int s,int t){
    while(!q.empty()) q.pop();
    q.push(s);
    memset(deep,0,sizeof(deep));
    deep[s]=1;
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
    long long maxflow=0,nowflow=0;
    while(bfs(s,t)){
        while(nowflow=dfs(s,t,INF)) maxflow+=nowflow; 
    }
    return maxflow;
}

int get_id(int x,int y){
	return (x-1)*m+y;
}

int get_y(int x){
	if(x==-1) return INF;
	else return 100-x;
} 
int main(){
	int a,b;
	qread(n);
	qread(m);
	qread(k); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			qread(xx[i][j]);
		} 
	}
	int s=0,t=n*m+1;
	for(int i=1;i<=n;i++){
		add_edge(s,get_id(i,1),get_y(xx[i][1]));
//		add_edge(get_id(i,1),s,0);
		for(int j=2;j<=m;j++){
			add_edge(get_id(i,j-1),get_id(i,j),get_y(xx[i][j]));
//			add_edge(get_id(i,j),get_id(i,j-1),0);
		}
		add_edge(get_id(i,m),t,INF);
//		add_edge(t,get_id(i,m),0);
	}
	for(int i=1;i<=k;i++){
		qread(a);
		qread(b);
		add_edge(s,get_id(b,1),INF);
//		add_edge(get_id(b,1),s,0);
		for(int j=2;j<=m;j++){
			add_edge(get_id(a,j-1),get_id(b,j),INF);
//			add_edge(get_id(b,j),get_id(a,j-1),0);
		}
	}
	printf("%.2lf\n",(double)(100*n-dinic(s,t))/n);
}

