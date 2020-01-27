# 2019-7-3-修学旅行前奏—其二 Tutorial

http://119.29.55.79/contest/60

未做出T2

## T1

http://119.29.55.79/problem/3146

> 现在有一个二维前缀和惯有的矩阵。其中'.'代表空地，'#'代表障碍。
>
> 然后是二维前缀和惯有的查询,求矩形中有多少1 * 2或2 * 1并且全由'.'组成的矩形？

首先肯定是用二维前缀和处理(1,1)到(i,j)的矩形中有多少个满足条件的矩形，。但直接处理会有边界问题。如询问(x1,y1)(x2,y2),在直线x=x1上的矩形右端点，它的左端点会突出框外

因此分别维护横的矩形和纵的矩形的数量，注意边界上的要排除

```cpp
#include<iostream>
#include<cstdio>
#define maxn 5005
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
	x*=sign;
}

int h,w,q;
char s[maxn+5];
char a[maxn+5][maxn+5];
int sum1[maxn+5][maxn+5];
int sum2[maxn+5][maxn+5];
void ini(){
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int val=0;
			if(a[i][j]=='.'&&a[i][j-1]=='.') val++;
			sum1[i][j]=sum1[i][j-1]+sum1[i-1][j]-sum1[i-1][j-1]+val; 
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int val=0;
			if(a[i][j]=='.'&&a[i-1][j]=='.') val++;
			sum2[i][j]=sum2[i][j-1]+sum2[i-1][j]-sum2[i-1][j-1]+val; 
		}
	}
}

int query_1(int x1,int y1,int x2,int y2){
	y1++;
	return sum1[x2][y2]-sum1[x1-1][y2]-sum1[x2][y1-1]+sum1[x1-1][y1-1];
}

int query_2(int x1,int y1,int x2,int y2){
	x1++;
	return sum2[x2][y2]-sum2[x1-1][y2]-sum2[x2][y1-1]+sum2[x1-1][y1-1];
}
int main(){
	int x1,y1,x2,y2;
	scanf("%d %d",&h,&w);
	for(int i=1;i<=h;i++){
		scanf("%s",s+1);
		for(int j=1;j<=w;j++){
			a[i][j]=s[j];
		}
	}
	ini();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int maxx=max(x1,x2),minx=min(x1,x2);
		int maxy=max(y1,y2),miny=min(y1,y2);
		printf("%d\n",query_1(minx,miny,maxx,maxy)+query_2(minx,miny,maxx,maxy));
	}
}
```



## T3

http://119.29.55.79/problem/256

> 解决这样一个问题：给定一颗有根树（根为 1），
>
> 有以下两种操作：
>
> 1.标记操作：对某个结点打上标记（在最开始，只有结点 1有标记，其他结点均无标记，而且对于某个结点，可以打多次标记）。
>
> 2.询问操作：询问某个结点最近的一个打了标记的祖先（这个结点本身也算自己的祖先）。

用线段树维护。

线段树的叶子节点记录该节点到根路径上深度最大的祖先编号。如果我们给x打标记，那x的子树中的节点都要区间更新，判断当前深度最大的祖先的深度是否>deep[x]

于是这样就变成了一个线段树条件赋值问题

维护v和mark,pushdown时判断深度关系，来决定是否修改

线段树的非叶子节点的v表示区间中深度**最小**的节点，如果深度最小的节点的深度都比deep[x]大，那就不用更新。否则更新v和mark,下推标记

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 100000
using namespace std;
int n,q;
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

int log2n;
int tim=0;
int lb[maxn+5],rb[maxn+5];
int deep[maxn+5];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	lb[x]=++tim;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
	rb[x]=tim;
}

struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
		int mark;
		int len(){
			return r-l+1;
		}
	}tree[maxn*4+5];
	void push_up(int pos){
		if(deep[tree[pos<<1].v]<deep[tree[pos<<1|1].v]) tree[pos].v=tree[pos<<1].v;
		else tree[pos].v=tree[pos<<1|1].v;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void push_down(int pos){
		if(tree[pos].mark){
			if(deep[tree[pos].mark]>deep[tree[pos<<1].mark]) tree[pos<<1].mark=tree[pos].mark;
			if(deep[tree[pos].mark]>deep[tree[pos<<1].v]) tree[pos<<1].v=tree[pos].mark;
			if(deep[tree[pos].mark]>deep[tree[pos<<1|1].mark]) tree[pos<<1|1].mark=tree[pos].mark;
			if(deep[tree[pos].mark]>deep[tree[pos<<1|1].v]) tree[pos<<1|1].v=tree[pos].mark;
			tree[pos].mark=0;
		}
	}
	void update(int L,int R,int pt,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			if(deep[tree[pos].v]<deep[pt]){
				tree[pos].v=pt;
				tree[pos].mark=pt;
			}
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,pt,pos<<1);
		if(R>mid) update(L,R,pt,pos<<1|1);
		push_up(pos);
	}
	int query(int qp,int pos){
		if(tree[pos].l==tree[pos].r){
			return tree[pos].v;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(qp<=mid) return query(qp,pos<<1);
		else return query(qp,pos<<1|1);
	}
}T;


int main(){
	char op[2];
	int num;
	int u,v;
	scanf("%d %d",&n,&q);
	log2n=log2(n)+1;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	T.build(1,n,1);
	dfs(1,0);
	T.update(lb[1],rb[1],1,1);
	for(int i=1;i<=q;i++){
		scanf("%s",op);
		scanf("%d",&num);
		if(op[0]=='C'){
			T.update(lb[num],rb[num],num,1);
		}else{
			printf("%d\n",T.query(lb[num],1));
		}
	}
}
```



## T4

http://119.29.55.79/problem/314

> 在 Adera 的异时空中有一张地图。这张地图上有 N个点，有 N-1条双向边把它们连通起来。起初地图上没有任何异象石，在接下来的 M个时刻中，每个时刻会发生以下三种类型的事件之一：
>
> 1. 地图的某个点上出现了异象石（已经出现的不会再次出现）；
> 2. 地图某个点上的异象石被摧毁（不会摧毁没有异象石的点）；
> 3. 向玩家询问使所有异象石所在的点连通的边集的总长度最小是多少。
>
> 请你作为玩家回答这些问题。下图是一个例子，灰色节点表示出现了异象石，加粗的边表示被选为连通异象石的边集。

考虑把异象石全部走一遍然后回到起点，答案就是走的路程/2

显然我们需要根据dfs序依次走，那么维护一个序列，存储所有异象石节点，按dfs序排序

然后路程就是相邻节点距离之和 （记得加上a[n]到a[1]距离）

插入一个节点时找出它的前驱pre和后继nex。sum-=dist(pre,nex) sum+=dist(pre,x)+dist(x,nex)

注意各种边界情况：

1.x为第1个，x没有前驱

2.x为第n个

3.x没有后继



