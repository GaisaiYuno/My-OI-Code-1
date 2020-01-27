## [Codeforces 603E]Pastoral Oddities(LCT)

### 题面

图中有n个孤立点，依次向图中加入m条带权无向边。使得图中每个点的度数均为奇数的边集是合法的，其权值定义为集合中的最大边权。每次加入边后，询问权值最小的合法边集的权值，不存在合法边集时输出−1。

$n \leq 10^5,m \leq 3\times 10^5$

### 分析

手玩样例可得:**图存在合法边集，当且仅当每个连通块的大小为偶数**

**证明:**

先证明充分性:假设某合法连通块大小为奇数，那么该块的总度数是奇数。但所有点的度数之和一定为偶数(因为一条边会被算入2个点的度数)。所以不存在合法边集。因此连通块大小一定为偶数。

再证明必要性: 求出连通块的任意一棵生成树。从下往上处理每个非根节点$x$.如果$x$到它生成树中的孩子的边中，已经有偶数条被选入边集。那么把$x$到$fa(x)$的边加入边集，这样$x$的度数就是奇数。对于根节点,因为刚刚我们已经把非根节点的度数全部设为奇数,但所有点的度数之和为偶数，那么根节点的度数一定是奇数。

注意到充分性的证明已经给出了一种答案构造方法。这个方法中选择的边一定是原来连通块生成树上的。而且原来的连通块被划分成了更小的连通块(当$x$没有连到$fa(x)$时),每个新联通块的最小生成树就是权值最小的合法边集。

我们用一个优先队列来维护森林中的每条边，按权值从小到大排序。实现上由于```priority_queue```的一些限制，我们改用```set< pair<int,int> >```.其中第一关键字为边权，第二关键字为边的编号

那么我们就可以用LCT维护这个生成树森林。

考虑每次加边操作$(u,v,w)$的影响。

1. 如果$u,v$已经连通,那么我们就维护最小生成树，查找$u$到$v$路径上最大的边权$w_0$.

   若$w_0>w$，那么就把生成树上的$w_0$换成$w$.同时更新`set`. 

   否则，先判断当前是否有解(是否存在度数为奇数的联通块)，有解输出set中的最大边权。

2. 如果$u,v$不连通,我们将新的边加入LCT和`set`.并且更新度数为奇数的联通块个数。

3. 如果生成树的边有变化，我们需要重新计算最优答案。从`set`中最大的边开始，检查能否移除这条边。若能移除则移除并检查次大，否则结束。

那么我们的LCT除了基本操作之外，要支持:

1. 查询路径上边权最大的边。类似[[BZOJ2594\] [WC2006]水管局长(Kruskal+LCT)](https://www.cnblogs.com/birchtree/p/12044031.html)那样把边看成点即可。

2. 查询生成树上某个点的子树大小.类似[[BJOI2014\]大融合(Link Cut Tree)](https://www.cnblogs.com/birchtree/p/11966256.html)维护虚子树信息即可。注意由于我们把边看成了点,一个点数为$p$的子树在LCT中变成了$p+(p-1)=2p-1$。那么真正的点数就是$(sz[p]+1)/2$

   

复杂度分析:LCT操作的复杂度为$O((n+m) \log n)$。每条边只会在set中被删除一次,复杂度$O(m \log m)$。

总结:这题先是利用了一个美妙的性质将问题转化为生成树问题，然后又结合了LCT维护生成树和维护子树信息两种套路。既有思维难度又有数据结构难度。给出题人点赞！

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<utility>
#define maxn 100000
#define maxm 300000
using namespace std;
int n,m;
struct edge {
	int from;
	int to;
	int len;
} E[maxm+5];
 
 
struct LCT {
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
	struct node {
		int ch[2];
		int fa;
		int sz;//原树上的子树大小
		int vsz;//虚子树大小
		int id;
		int maxid;
		int revm;
	} tree[maxn+maxm+5];
	inline bool is_root(int x) {
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x) {
		return rson(fa(x))==x;
	}
	void push_up(int x) {
		tree[x].sz=tree[lson(x)].sz+1+tree[rson(x)].sz+tree[x].vsz;
		tree[x].maxid=tree[x].id;
		if(E[tree[lson(x)].maxid].len>E[tree[x].maxid].len) tree[x].maxid=tree[lson(x)].maxid;
		if(E[tree[rson(x)].maxid].len>E[tree[x].maxid].len) tree[x].maxid=tree[rson(x)].maxid;
	}
	void reverse(int x) {
		swap(lson(x),rson(x));
		tree[x].revm^=1;
	}
	void push_down(int x) {
		if(tree[x].revm) {
			reverse(lson(x));
			reverse(rson(x));
			tree[x].revm=0;
		}
	}
	void push_down_all(int x) {
		if(!is_root(x)) push_down_all(fa(x));
		push_down(x);
	}
	void rotate(int x) {
		int y=fa(x),z=fa(y),k=check(x),w=tree[x].ch[k^1];
		tree[y].ch[k]=w;
		tree[w].fa=y;
		if(!is_root(y)) tree[z].ch[check(y)]=x;
		tree[x].fa=z;
		tree[x].ch[k^1]=y;
		tree[y].fa=x;
		push_up(y);
		push_up(x);
	}
	void splay(int x) {
		push_down_all(x);
		while(!is_root(x)) {
			int y=fa(x);
			if(!is_root(y)) {
				if(check(x)==check(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		push_up(x);
	}
	void access(int x) {
		for(int y=0; x; y=x,x=fa(x)) {
			splay(x);
			tree[x].vsz-=tree[y].sz-tree[rson(x)].sz;//把原来是虚子树，现在是实的减掉
			rson(x)=y;
			push_up(x);
		}
	}
	void make_root(int x) {
		access(x);
		splay(x);
		reverse(x);
	}
	void split(int x,int y) {
		make_root(x);
		access(y);
		splay(y);
	}
	void link(int x,int y) {
		make_root(x);
		fa(x)=y;
		tree[y].vsz+=tree[x].sz;
		push_up(y);
	}
	void cut(int x,int y) {
		split(x,y);
		fa(x)=lson(y)=0;
		push_up(y);
	}
	void add_edge(int id) {
		link(E[id].from,id+n);
		link(E[id].to,id+n);
	}
	void del_edge(int id) {
		cut(E[id].from,id+n);
		cut(E[id].to,id+n);
		tree[id+n].vsz=0;
	}
	int find_root(int x) {
		access(x);
		splay(x);
		while(lson(x)) x=lson(x);
		return x;
	}
 
	int query_route(int x,int y) {
		split(x,y);
		return tree[y].maxid;
	}
} T;
set< pair<int,int> >ed;//按边权从小到大存储生成树中的边,first为边权,second为编号
inline int is_odd(int x) {
	//判断x所在联通块的点数是否为奇数
	//LCT里p个点,p-1条边,sz[x]=2p-1
	//真正的点数为(sz[x]+1)/2
	return ((T.tree[x].sz+1)/2)%2==1;
}
void build() {
	while(1) {
		int id=(--ed.end())->second;
		int x=E[id].from;
		int y=E[id].to;
		T.split(x,y);
		if(is_odd(x)) break;
		T.del_edge(id);
		ed.erase(*(--ed.end()));
	}
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n+m; i++) {
		if(i<=n) T.tree[i].id=0;
		else T.tree[i].id=i-n;
		T.push_up(i);
	}
	for(int i=1; i<=m; i++) scanf("%d %d %d",&E[i].from,&E[i].to,&E[i].len);
	int odd_sz_cnt=n;
	for(int i=1; i<=m; i++) {
		int u=E[i].from,v=E[i].to,w=E[i].len;
		if(T.find_root(u)==T.find_root(v)) {
			int now=T.query_route(u,v);
			if(w<E[now].len) {
				T.del_edge(now);
				T.add_edge(i);
				ed.erase(make_pair(E[now].len,now));
			} else {
				if(odd_sz_cnt>1) printf("-1\n");
				else printf("%d\n",(--ed.end())->first);//输出最大边
				continue;
			}
		} else {
			T.make_root(u);
			odd_sz_cnt-=is_odd(u);
			T.make_root(v);
			odd_sz_cnt-=is_odd(v);
			//把原来的两个联通块的贡献减掉
			T.add_edge(i);
			T.make_root(u);
			odd_sz_cnt+=is_odd(u);
			//再加回新的贡献
		}
		ed.insert(make_pair(w,i));
		if(odd_sz_cnt>0) {
			printf("-1\n");
			continue;
		}
		build();//构造出联通块里选择的边集
		printf("%d\n",(--ed.end())->first);
	}
}
```

