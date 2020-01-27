#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
#define maxv 1000005
#define INF 0x3f3f3f3f 
using namespace std;
int n,k;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxn<<1];
int head[maxn];
int ecnt=1;
void add_edge(int u,int v,int w){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].len=w;
	E[ecnt].next=head[u];
	head[u]=ecnt;
} 

int root,sum;
int vis[maxn];
int sz[maxn];
int f[maxn];
void get_root(int x,int fa){
	sz[x]=1;
	f[x]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			get_root(y,x);
			f[x]=max(f[x],sz[y]);
			sz[x]+=sz[y]; 
		}
	}
	f[x]=max(f[x],sum-sz[x]);
	if(f[x]<f[root]) root=x;
}

int ans;
int medge[maxv],deep[maxn],dist[maxn];
//medge[i]表示距离为i时的最大代价 
void update(int x,int fa){
	if(dist[x]<=k){
		medge[dist[x]]=min(medge[dist[x]],deep[x]);
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa&&!vis[y]){
				update(y,x); 
			}
		}
	}
} 
void del(int x,int fa){
	if(dist[x]<=k){
		medge[dist[x]]=INF;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa&&!vis[y]){
				del(y,x); 
			}
		}
	}
} 
void get_deep(int x,int fa){
	if(dist[x]>k) return;
	ans=min(ans,deep[x]+medge[k-dist[x]]);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			deep[y]=deep[x]+1;
			dist[y]=dist[x]+E[i].len;
			get_deep(y,x);
		}
	}
}
void cal(int x,int fa,int deep0,int dist0){
	deep[x]=deep0;
	dist[x]=dist0;
	get_deep(x,fa);
	update(x,fa);//计算完再更新t,防止重复 
}
void solve(int x){
	vis[x]=1;
	medge[0]=0; //注意设成0是为了处理一端在x,一端在子树里的情况，如果是INF这种情况就不会被更新了 
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			cal(y,x,1,E[i].len);
		}
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			del(y,x);//继续dfs之前要把数组恢复 
		}
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			root=0;
			sum=sz[y];
			get_root(y,0);
			solve(root); 
		}
	}
} 
int main(){
	int u,v,w;
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		u++;
		v++;
		add_edge(u,v,w);
		add_edge(v,u,w); 
	}
	memset(medge,0x3f,sizeof(medge)); 
	ans=INF;
	root=0;
	sum=n;
	f[root]=INF; 
	get_root(1,0);
	solve(root); 
	if(ans>n) ans=-1;
	printf("%d\n",ans); 
}

