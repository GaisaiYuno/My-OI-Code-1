//http://119.29.55.79/contest/88/problem/2
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500
#define maxv 4000
using namespace std;
int T,n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int esz=0;
int head[maxn+5];
void add_edge(int u,int v){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz; 
}

int totsz,root;
bool vis[maxn+5];
int sz[maxn+5];
int maxsz[maxn+5];
void get_root(int x,int fa){
	sz[x]=1;
	maxsz[x]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			get_root(y,x);
			sz[x]+=sz[y];
			maxsz[x]=max(maxsz[x],sz[y]);
		}
	}
	maxsz[x]=max(maxsz[x],totsz-maxsz[x]);
	if(maxsz[x]<maxsz[root]) root=x;
}
int tim;
int dfn[maxn+5],hash_dfn[maxn+5];
int nex[maxn+5];
void get_dfn(int x,int fa){
	dfn[x]=tim++;
	hash_dfn[dfn[x]]=x;
	sz[x]=1; 
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			get_dfn(y,x);
			sz[x]+=sz[y];
		}
	}
	nex[x]=tim;
}

struct node{
	int id;
	int val;
	node(){
		
	}
	node(int _id,int _val){
		id=_id;
		val=_val;
	}
}q[maxv+5];
int w[maxn+5],c[maxn+5],d[maxn+5];
int dp[maxn+5][maxv+5];
int ans=0;
void solve(int rt){
	vis[rt]=1;
	tim=0;
	get_dfn(rt,0);
	//一定要选根节点 
	//倒序循环，这样dp[0]就存储了选rt的答案 
	for(int i=0;i<=tim;i++){
		for(int j=0;j<=m;j++) dp[i][j]=0;
	}
	for(int i=tim-1;i>=0;i--){
		int x=hash_dfn[i];
		for(int j=0;j<=m;j++) dp[i][j]=max(dp[i][j],dp[nex[x]][j]);//不选 
		for(int b=0;b<c[x];b++){//选，多重背包单调队列优化 
			int head=1,tail=0;
			for(int a=0;a*c[x]+b<=m;a++){
				
				while(head<=tail&&a-q[head].id>d[x]) head++;
				if(head<=tail) dp[i][a*c[x]+b]=max(dp[i][a*c[x]+b],q[head].val+a*w[x]);  
				int now=dp[i+1][a*c[x]+b]-a*w[x];
				while(head<=tail&&now>=q[tail].val) tail--;
				q[++tail]=node(a,now);
			}
		}
	}
	ans=max(ans,dp[0][m]);
	for(int i=head[rt];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			root=0;
			maxsz[root]=sz[y];
			totsz=sz[y];
			get_root(y,rt);
			solve(root);
		}
	}
}
void ini(){
	esz=0;
	memset(head,0,sizeof(head));
	ans=0;
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	memset(sz,0,sizeof(sz));
	memset(maxsz,0,sizeof(maxsz));
	memset(dfn,0,sizeof(dfn));
	memset(hash_dfn,0,sizeof(hash_dfn)); 
	memset(nex,0,sizeof(nex));
	memset(q,0,sizeof(q));
}
int main(){
//	freopen("1.in","r",stdin); 
	int u,v;
	scanf("%d",&T);
	while(T--){
		ini();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		for(int i=1;i<=n;i++) scanf("%d",&d[i]); 
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		root=0;
		maxsz[root]=n;
		totsz=n;
		get_root(1,0);
		solve(root);
		printf("%d\n",ans);
	}

}
/*
2 
3 2
1 2 3
1 1 1
1 2 1
1 2
1 3
3 2
1 2 3
1 1 1
1 2 1
1 2
1 3
*/ 
