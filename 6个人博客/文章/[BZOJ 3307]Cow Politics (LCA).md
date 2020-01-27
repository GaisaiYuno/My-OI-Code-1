### [BZOJ 3307]Cow Politics (LCA)

###　题面

给出一棵N个点的树，树上每个节点都有颜色。对于每种颜色，求该颜色距离最远的两个点之间的距离。N≤200000

### 分析

显然对于每种颜色建立一棵虚树是可行的。但是有编码复杂度更低的方法。显然某种颜色距离最远的两个点中，一个肯定是这种颜色的点中深度最深的（贪心考虑，如果还有更深的，那么选更深的一定更优）。那么我们只要找出每种颜色深度最深的点，然后向该种颜色的每一个点暴力求距离即可。

由于所有颜色的点的个数加起来为n，总时间复杂度$O(n\log n)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 200000
#define maxlogn 25
using namespace std;
int n,k,root;
int a[maxn+5];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

vector<int>node[maxn+5];
int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
int maxd[maxn+5];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=maxlogn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=maxlogn;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=maxlogn;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
int dist(int x,int y){
	return deep[x]+deep[y]-2*deep[lca(x,y)];
}

int main(){
	int p;
	int cnt=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&p);
		if(p!=0){
			add_edge(p,i);
			add_edge(i,p);
		} 
		else root=i;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(deep[i]>deep[maxd[a[i]]]) maxd[a[i]]=i;
		node[a[i]].push_back(i);
	}
	for(int i=1;i<=k;i++){
		int ans=0;
		for(int j=0;j<node[i].size();j++){
			ans=max(ans,dist(maxd[i],node[i][j]));
		}
		printf("%d\n",ans);
	}
} 
```



