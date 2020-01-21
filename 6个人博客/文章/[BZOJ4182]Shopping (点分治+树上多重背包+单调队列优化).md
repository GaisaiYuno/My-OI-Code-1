### [BZOJ4182]Shopping (点分治+树上多重背包+单调队列优化)

###　题面

马上就是小苗的生日了，为了给小苗准备礼物，小葱兴冲冲地来到了商店街。商店街有n个商店，并且它们之间的道路构成了一颗树的形状。

第i个商店只卖第i种物品，小苗对于这种物品的喜爱度是wi，物品的价格为ci，物品的库存是di。但是商店街有一项奇怪的规定：如果在商店u,v买了东西，并且有一个商店w在u到v的路径上，那么必须要在商店w买东西。小葱身上有m元钱，他想要尽量让小苗开心，所以他希望最大化小苗对买到物品的喜爱度之和。这种小问题对于小葱来说当然不在话下，但是他的身边没有电脑，于是他打电话给同为OI选手的你，你能帮帮他吗？

### 分析

由题意，如果在u,v买了东西，那u到v的路径上的所有点一定都得买。因此最后购买东西的点一定是一个联通块。显然这个联通块一定包含某个子树的重心，所以可以点分治。

当我们点分治到某个重心rt的时候，我们考虑对这个重心分治出来子树计算背包。显然子树中的一个节点被选，它的父亲也一定被选。那么我们就把问题转化成了一般的树形背包问题，注意结点x必须选。

那么就可以列出模板的dp方程。设$dp[i][j]$表示当前处理到dfs序为i的节点x,当前背包内物品价格不大于j，能得到的最大喜爱度。设x子树的下一个子树dfs序的开始位置为nex[x].x为dfs序i对应的节点

则$dp[i][j]=max(dp[nex[x]][j])$(不选子树x)

$dp[i][j]=max(dp[i+1][j-k \times w[x]]+k*c[x])$(在x号节点买东西，买k个)

我们倒序dp是因为这样$dp[0][m]$存储的就是包含重心rt，且价格不大于m的最大喜爱度。可以直接用来更新答案

第二个方程显然可以按照多重背包的方法单调队列优化，这里不再赘述

总时间复杂度$O(nm\log n)$

### 代码

```cpp
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
	maxsz[x]=max(maxsz[x],totsz-sz[x]);
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

int q[maxv+5];
int w[maxn+5],c[maxn+5],d[maxn+5];
int dp[maxn+5][maxv+5];
int ans=0;

void solve(int rt){
	vis[rt]=1;
	tim=0;
	get_dfn(rt,0);
	//一定要选根节点 
	//倒序循环，这样dp[0]就存储了选rt的答案 
	memset(dp[tim],0,sizeof(dp[tim]));
	for(int i=tim-1;i>=0;i--){
		int x=hash_dfn[i];
		for(int j=0;j<=m;j++) dp[i][j]=dp[nex[x]][j];//不选 
		for(int b=0;b<c[x];b++){//选，多重背包单调队列优化 
			int head=1,tail=0;
			for(int a=0;a*c[x]+b<=m;a++){
				
				while(head<=tail&&a-q[head]>d[x]) head++;
				if(head<=tail) dp[i][a*c[x]+b]=max(dp[i][a*c[x]+b],dp[i+1][q[head]*c[x]+b]+(a-q[head])*w[x]);  
				int now=dp[i+1][a*c[x]+b]-a*w[x];
				while(head<=tail&&now>=dp[i+1][q[tail]*c[x]+b]-q[tail]*w[x]) tail--;
				q[++tail]=a;
			}
		}
	}
	for(int i=1;i<=m;i++) ans=max(ans,dp[0][i]);
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
```



