#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
#define maxn 20005
#define maxm 100005
#define INF 0x7fffffff
using namespace std;
int n,m;
struct match{
	int x;
	int y;
}a[maxn];

struct edge{
	int from;
	int to;
	int next;
	int flow;
}E[maxm<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	head[v]=sz;
}

int deep[maxn];
bool bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	q.push(s);
	deep[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
				if(y==t) return 1;
			}
		} 
	} 
	return 0;
}

int dfs(int x,int t,int minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].flow&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,E[i].flow));
			E[i].flow-=k;
			E[i^1].flow+=k;
			rest-=k;
			if(rest==0) break;
		}
	}
	return minf-rest;
}

int dinic(int s,int t){
	int ans,now;
	ans=0;
	while(bfs(s,t)){
		while(now=dfs(s,t,INF)) ans+=now;
	} 
	return ans;
}

int check(int mid){
	int s=0,t=n+m+1; 
	sz=1;
	memset(head,0,sizeof(head));
	memset(E,0,sizeof(E));
	for(int i=1;i<=n;i++){
		add_edge(s,i,mid);
	}
	for(int i=1;i<=m;i++){
		add_edge(a[i].x,n+i,1);
		add_edge(a[i].y,n+i,1);
		add_edge(n+i,t,1);
	}
	if(dinic(s,t)==m) return 1;
	else return 0;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	int l=0,r=m,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1; 
		}else l=mid+1;
	}
	printf("%d\n",ans);
}

