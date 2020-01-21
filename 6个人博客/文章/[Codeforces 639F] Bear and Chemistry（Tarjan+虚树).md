## [Codeforces 639F] Bear and Chemistry（Tarjan+虚树)

### 题面

给出一个n个点,m条边的无向图（不保证连通，可能有自环和重边）,有q次询问，每次询问给出p个点和q条边，判断加上q条边后,这p个点中的任意一个点对(x,y)是否都满足:能从x走到y，再从y走到x，不经过重复的边。询问强制在线。

$(1 ≤ n, q*≤ 300 000, 0 ≤ m ≤ 300 000,\sum p \leq 300\ 000,\sum q \leq 300\ 000)$

### 分析

我们发现，判断条件等价于：加上q条边后，这p个点在同一个边-双联通分量(e-dcc)中。那么问题就变为如何求出新图的边-双连通分量。直接tarjan时间复杂度为$O(nq)$显然是不行的。

首先，原图中处在同一个e-dcc中的点，加完边后肯定也在同一个e-dcc中。因此我们将原图中的e-dcc缩成一个点，那么原图就变成了一个树（或森林）。然后考虑询问，显然只有跟询问有关的点才有意义，因此我们求出p个询问点，还有q条边的端点的e-dcc编号，然后再建立虚树或虚森林（ ~~好像没有这个名词~~）。最后把q条边加进森林，对这个新图求e-dcc。然后就可以直接判断这p个点是否在新图的同一个e-dcc中了。

思路很简单，但代码实现比较复杂，这里讲几个易错的细节：

1.强制在线的时候是把u变成(u+rcnt)%n,其中rcnt是之前询问中答案为YES的**询问编号之和（不是YES个数！）**，并且**rcnt可能会爆int**，注意对rcnt先取模

2.建立虚树的时候。输入的节点可能不在同一棵树上。我们按dfs序排序后，其实每棵树的节点都在一个连续的区间内，只要用尺取法找出连续的区间，然后对该区间内的点建立虚树就可以了。

3.**遍历图的每个节点的时候，不要从1~n枚举**，这样会被卡成$O(nq)$。对于每个图维护一个数组记录节点序列，只要遍历这个数组就可以了

4.多次调用tarjan和建虚树的函数，一定要注意初始化

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#define maxn 500000
#define maxm 500000
#define maxlogn 25
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(long long x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}


int n,m,q;

struct graph {//封装图 
	struct edge {
		int from;
		int to;
		int next;
	} E[maxm*2+5];
	int nodes[maxn+5];
	//存储节点编号，这样可以节约遍历图中节点的时间，不用从1~n遍历（会被卡成O(n^2)),只需要遍历nodes中节点 
	int head[maxn+5];
	int esz;
	int vsz;
	void add_node(int x) {
		vsz++;
		nodes[vsz]=x;
	}
	void unique_node() {
		sort(nodes+1,nodes+1+vsz);
		vsz=unique(nodes+1,nodes+1+vsz)-nodes-1;
	}
	void add_edge(int u,int v) {
		esz++;
		E[esz].from=u;
		E[esz].to=v;
		E[esz].next=head[u];
		head[u]=esz;
	}
	graph() {
		esz=1;
	}
	void clear() { //使用后清空
		esz=1;
		for(int i=1; i<=vsz; i++) head[nodes[i]]=0;
		vsz=0;
	}
	void debug() {
		printf("node=%d edge=%d\n",vsz,esz);
		for(int i=2; i<=esz; i+=2) {
			printf("debug:%d %d\n",E[i].from,E[i].to);
		}
	}
} G1,G2,G3;



namespace e_dcc {//边-双联通分量相关
	int tim,cnt;
	int dfn[maxn+5];
	int low[maxn+5];
	bool bridge[maxm*2+5];
	int bel[maxn+5];//存储属于第几个e-dcc
	bool vis[maxn+5];

	void tarjan(int x,int last,graph& G) {
		dfn[x]=++tim;
		low[x]=dfn[x];
		for(int i=G.head[x]; i; i=G.E[i].next) {
			int y=G.E[i].to;
			if(!dfn[y]) {
				tarjan(y,i,G);
				low[x]=min(low[x],low[y]);
				if(dfn[x]<low[y]) {
					bridge[i]=bridge[i^1]=1;
				}
			} else if(i!=(last^1)) low[x]=min(low[x],dfn[y]);
		}
	}

	void dfs_mark(int x,int col,graph& G) {//不走桥边，就能求出e-dcc 
		bel[x]=col;
		vis[x]=1;
		for(int i=G.head[x]; i; i=G.E[i].next) {
			int y=G.E[i].to;
			if(!vis[y]&&!bridge[i]) {
				dfs_mark(y,col,G);
			}
		}
	}

	int get_bel(graph &G) {//求出v-dcc,不缩点,返回v-dcc数量
		for(int i=1; i<=G.vsz; i++) {
			int u=G.nodes[i];
			low[u]=dfn[u]=bel[u]=vis[u]=0;
		}
		for(int i=1; i<=G.esz; i++) bridge[i]=0;
		tim=0;
		for(int i=1; i<=G.vsz; i++) {
			if(!dfn[G.nodes[i]]) {
				tarjan(G.nodes[i],0,G);
			}
		}

		cnt=0;
		for(int i=1; i<=G.vsz; i++) {
			if(!vis[G.nodes[i]]) {
				cnt++;
				dfs_mark(G.nodes[i],cnt,G);
			}
		}
		return cnt;
	}


	void graph_to_tree(graph &in,graph &out) {//缩点
		get_bel(in);
		for(int i=2; i<=in.esz; i++) {
			if(bel[in.E[i].from]!=bel[in.E[i].to]) {
				out.add_edge(bel[in.E[i].from],bel[in.E[i].to]);
			}
		}
		out.vsz=cnt;
	}
}

vector<int>nodes;//虚树上的点
namespace virtual_tree {//虚树相关
	int log2n;
	int tim=0;
	int dfn[maxn+5];
	int deep[maxn+5];
	int rt[maxn+5];
	int anc[maxn+5][maxlogn+5];
	void dfs(int x,int fa,int root,graph &T1) {
		dfn[x]=++tim;
		rt[x]=root;
		deep[x]=deep[fa]+1;
		anc[x][0]=fa;
		for(int i=1; i<=log2n; i++)anc[x][i]=anc[anc[x][i-1]][i-1];
		for(int i=T1.head[x]; i; i=T1.E[i].next) {
			int y=T1.E[i].to;
			if(y!=fa) {
				dfs(y,x,root,T1);
			}
		}
	}
	int lca(int x,int y) {
		if(deep[x]<deep[y]) swap(x,y);
		for(int i=log2n; i>=0; i--) {
			if(deep[anc[x][i]]>=deep[y]) {
				x=anc[x][i];
			}
		}
		if(x==y) return x;
		for(int i=log2n; i>=0; i--) {
			if(anc[x][i]!=anc[y][i]) {
				x=anc[x][i];
				y=anc[y][i];
			}
		}
		return anc[x][0];
	}


	int top=0;
	int s[maxn];
	int in[maxn];
	int cmp(int x,int y) {
		return dfn[x]<dfn[y];
	}


	void insert(int x,graph &T2) {//虚树插入模板 
		if(top<1) {
			s[++top]=x;
			return;
		}
		int lc=lca(x,s[top]);
		if(lc==s[top]) {
			s[++top]=x;
			return;
		}
		while(top>1&&deep[s[top-1]]>=deep[lc]) {
			T2.add_edge(s[top-1],s[top]);
			T2.add_edge(s[top],s[top-1]);
			T2.add_node(s[top]);
			T2.add_node(s[top-1]);
			top--;
		}
		if(s[top]!=lc) {
			T2.add_edge(lc,s[top]);
			T2.add_edge(s[top],lc);
			T2.add_node(lc);
			T2.add_node(s[top]);
		}
		s[top]=lc;
		s[++top]=x;
	}

	void ini_tree(graph &in) { //初始化原来的森林
		log2n=log2(in.vsz)+1;
		for(int i=1; i<=in.vsz; i++) {
			if(!deep[i]) dfs(i,0,i,in);
		}
	}

	void get_vir_tree(int *in,int k,graph &out) { //对于每个询问,建出虚树
		sort(in+1,in+1+k,cmp);
		int r;
		for(int l=1; l<=k; l=r+1) {
			//注意不一定只有一棵虚树，按dfn排序后
			//rt[i]为点i在虚树里的编号 
			//[l,r]对应虚树中属于同一棵树的区间 
			r=l;
			while(r<k&&rt[in[r]]==rt[in[r+1]]) r++;//找出在一棵树里的点
			top=0;
			for(int i=l; i<=r; i++) {
				insert(in[i],out);
			}
			while(top>1) {
				out.add_edge(s[top-1],s[top]);
				out.add_edge(s[top],s[top-1]);
				out.add_node(s[top-1]);
				out.add_node(s[top]);
				top--;
			}
			if(l==r) out.add_node(in[l]); //只有一个点的特判 
		}


	}
}

int org_bel[maxn+5];//点x在原图G1中的e-dcc编号,由于namespace里的不断在变，要保存一下

int org_point[maxn+5]; //询问的点 
int point[maxn+5];//用来建虚树的点 
bool check(int tn){//检查询问的点是否在同一个e-dcc中 
	for(int i=2;i<=tn;i++){
		if(e_dcc::bel[org_point[i]]!=e_dcc::bel[org_point[1]]) return 0;
	}
	return 1;
}
int main() {
	int u,v;
	qread(n);
	qread(m);
	qread(q);
	for(int i=1; i<=n; i++) G1.add_node(i);
	for(int i=1; i<=m; i++) {
		qread(u);
		qread(v);
		G1.add_edge(u,v);
		G1.add_edge(v,u);
	}

	e_dcc::graph_to_tree(G1,G2);
	for(int i=1; i<=n; i++) {
		org_bel[i]=e_dcc::bel[i];

	}
	virtual_tree::ini_tree(G2);

	int rcnt=0;
	int tn,tm,tsz;
	for(int i=1; i<=q; i++) {
		qread(tn);
		qread(tm);
		tsz=0;
		for(int j=1; j<=tn; j++) {
			qread(org_point[j]);
			org_point[j]=(org_point[j]+rcnt)%n;//强制在线
			if(org_point[j]==0) org_point[j]=n;
			org_point[j]=org_bel[org_point[j]];
			point[++tsz]=org_point[j];
		}
	
		for(int j=1; j<=tm; j++) {
			qread(u);
			qread(v);
			u=(u+rcnt)%n;
			if(u==0) u=n;
			v=(v+rcnt)%n;
			if(v==0) v=n;
			if(org_bel[v]!=org_bel[u]) {
				G3.add_edge(org_bel[u],org_bel[v]);
				G3.add_edge(org_bel[v],org_bel[u]);
				G3.add_node(org_bel[u]);
				G3.add_node(org_bel[v]);
			}
			point[++tsz]=org_bel[u];
			point[++tsz]=org_bel[v];//边上的点也要加进去建虚树
		}

		sort(point+1,point+1+tsz);
		tsz=unique(point+1,point+1+tsz)-point-1;
		virtual_tree::get_vir_tree(point,tsz,G3);
		G3.unique_node();
#ifdef DEBUG 
		G3.debug();
#endif
		e_dcc::get_bel(G3);
		if(tn==1||check(tn)) {//不一定只有1个e-dcc，只要询问的tn个点在一个e-dcc中 
			printf("YES\n");
			rcnt+=i;//是加上答案编号，不是+1 
			rcnt%=n; //防止爆int 
		} else {
			printf("NO\n");
		}

		G3.clear();//清空虚树
	}
}

```



