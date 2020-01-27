## [BZOJ 3731] Gty的超级妹子树 (树分块)

### 题面

给出一棵树(或森林)，每个点都有一个值。现在有四种操作

1.查询x子树里>y的值有多少个

2.把点x的值改成y

3.添加一个新节点，它的父亲是x,值是y

4.断开节点x与父亲节点的边，一棵树变成两棵树

### 分析

新姿势-树分块get

#### 分块预处理

如果没有树的形态变化，一棵主席树就可以了。但是有形态变化，我们考虑树分块。树分块的思路是把树分成许多大小相等的树，可以用dfs预处理出来。我们dfs的时候把当前块的所有值记录在一个vector里，当我们dfs到一个儿子y的时候，如果当前块大小>我们设定的最大大小，就新建一个块。

注意vector里要排好序，具体方法就是每次插入的时候找到原来的序列中它应该插入的位置，然后再插入

同时，我们要新建一棵新树，新树的节点等于块数，相当于把每个块缩成一个点。每次新建块的时候向父亲节点的所在块连边即可得到新树。

我们需要维护一下几个信息:

```cpp
int bcnt=0;//块的数量
int bsz;//设定的块大小 
int bel[maxn+5];//x属于哪个块 
int fa[maxn+5];//节点x的父亲 
int root[maxn+5];//第x块对应的子树的根 
vector<int>num[maxn+5];//存储第x个块的值
```



#### 查询

我们查询x的子树的时候，x可能被分成了多个块。对于每个整块，我们只要在num里面二分查找就可以找到>y的数的个数。如果x本身是某个整块的根节点，那直接二分查找就可以了。否则在原树上x的子树里dfs,如果dfs到的节点y是某个整块的根节点，那么在新树上dfs累加整块的答案，返回。对于不完整的块里的散点，直接暴力统计即可。

### 修改值

只需要修改所在块的num即可

####　添加新节点

分类讨论

首先，在原树上添加一条边

１.若加入新节点后父亲节点所在块大小没有超过最大块大小，只需要更新一下块里的num

２.否则新建一个块，类似预处理里面新建块的方法维护每个块的答案

#### 分成两棵树

这种情况比较复杂。

首先，删掉原树上和父亲节点相连的边

1.若x是某个整块的根节点，删除新树上x对应的块和父亲节点对应的块的边

2.若x不是某个整块的根节点。在原树上dfs,找出x的子树里和x在同一个块的点，和x子树里的整块。把x新建成一个块，把散点全部插入新的块中，同时删除新树上x对应的块和父亲节点对应的块的边，删掉新树上x原来的块和x子树里的整块相连的边，新的块向dfs的时候找到的x子树里的整块连边

#### 时间复杂度分析

树分块的时间复杂度没有保证，但数据随机的情况下为$O(m \sqrt n \log n)$,块大小取$\sqrt n\log n$较优秀

###代码

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100000
#define maxm 100000
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
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];
vector<int>E1[maxn+5],E2[maxn+5];//E1原树，E2新书
vector<int>num[maxn+5];//存储第x个块的值
void vec_insert(vector<int>&x,int y){//插入y，且不破坏从小到大的序列 
	vector<int>::iterator it=lower_bound(x.begin(),x.end(),y+1);
	if(it==x.end()) x.push_back(y);
	else x.insert(it,y);
}
void vec_del(vector<int>&x,int y){//删除y 
	vector<int>::iterator it=lower_bound(x.begin(),x.end(),y);
	if(it!=x.end()) x.erase(it);
}
//注意尽量多判边界，否则容易RE，比如删除的时候可能父节点不存在，这时如果没判x.end()就会RE
//在这里判边界，比操作的时候判方便
void vec_modify(vector<int>&x,int last,int now){//把last修改成now 
	vec_del(x,last);
	vec_insert(x,now);
}


void add_edge(vector<int>* E,int x,int y){
	E[x].push_back(y);
} 
void del_edge(vector<int>*E,int x,int y){
	vec_del(E[x],y);
}

int bcnt=0;//块的数量
int bsz;//设定的块大小 
int bel[maxn+5];//x属于哪个块 
int fa[maxn+5];//原树上节点x的父亲 
int root[maxn+5];//第x块对应的子树的根 
void dfs1(int x,int f){
	fa[x]=f;
	bel[x]=bcnt;
	vec_insert(num[bel[x]],a[x]);
	for(int y : E1[x]){
		if(y!=f){
			if((int)num[bel[x]].size()==bsz){
				bcnt++;
				root[bcnt]=y; 
				add_edge(E2,bel[x],bcnt);//由于我们知道新树上父亲和儿子的关系，直接建有向边就好了，这样dfs的时候比较方便
			}
			dfs1(y,x);
		}
	}
}

int ans=0;
int get_ans(int id,int val){
	return num[id].end()-upper_bound(num[id].begin(),num[id].end(),val);
} 
void dfs2(int idx,int val){//处理整块子树 
	ans+=get_ans(idx,val);
	for(int y : E2[idx]){
		dfs2(y,val);
	} 
}
void dfs3(int x,int val){
	if(a[x]>val) ans++;//处理散点 
	for(int y : E1[x]){
		if(y!=fa[x]){
			if(bel[x]==bel[y]) dfs3(y,val);
			else dfs2(bel[y],val);
		}
	}
}

vector<int>nd;//需要重构的点 (x子树和x在同一个块的点)
vector<int>bk;//需要重构的块 （x子树里的整块）
void dfs4(int x){
	nd.push_back(x);
	for(int y : E1[x]){
		if(y!=fa[x]){
			if(bel[y]==bel[x]) dfs4(y);
			else bk.push_back(bel[y]);
		} 
	}
}
int query(int x,int val){
	ans=0;
	if(root[bel[x]]==x) dfs2(bel[x],val);
	else dfs3(x,val);
	return ans;
}
void change_val(int x,int val){
	vec_modify(num[bel[x]],a[x],val);
	a[x]=val;
}
void add_point(int f,int val){
	a[++n]=val;
	add_edge(E1,f,n);
	add_edge(E1,n,f);
	fa[n]=f;
	if((int)num[bel[f]].size()==bsz){//如果大小超过bsz,就新建一块 
		bel[n]=++bcnt;
		root[bcnt]=n;
		vec_insert(num[bel[n]],a[n]);
		add_edge(E2,bel[f],bel[n]);
	}else{//否则插入 
		bel[n]=bel[f];
		vec_insert(num[bel[n]],a[n]); 
	}
}

void split(int x){
	if(root[bel[x]]==x){//正好自成一块 
		if(fa[x]){
			del_edge(E1,x,fa[x]);//删掉原树上的边
			del_edge(E1,fa[x],x);
			del_edge(E2,bel[fa[x]],bel[x]);//删掉新树上的边
		}
	}else{
		del_edge(E1,x,fa[x]);//删掉原树上的边
		del_edge(E1,fa[x],x);
		bk.clear();
		nd.clear();
		dfs4(x);
		vec_del(num[bel[x]],a[x]);//x特殊处理一下
		bel[x]=++bcnt;
		vec_insert(num[bel[x]],a[x]);
		for(int u : nd){
			if(u==x) continue;
			vec_del(num[bel[u]],a[u]);
			vec_insert(num[bcnt],a[u]);//把散点全部插入新的块中
			bel[u]=bcnt;
		}
		for(int t : bk){
			del_edge(E2,bel[fa[x]],t);
			add_edge(E2,bcnt,t);//新块向dfs的时候找到的x子树里的整块连边
		}
	} 
}
int main(){
	int cmd;
	int x,y;
	int last=0;
	qread(n);
	bsz=sqrt(n)*log(n);
	for(int i=1;i<n;i++){
		qread(x);
		qread(y);
		add_edge(E1,x,y);
		add_edge(E1,y,x);
	}
	for(int i=1;i<=n;i++) qread(a[i]);
	bcnt=1;
	root[1]=1;
	dfs1(1,0);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(cmd);
		if(cmd==0){
			qread(x);
			qread(y);
			x^=last;
			y^=last;
			last=query(x,y);
			qprint(last);
			putchar('\n');
		}else if(cmd==1){
			qread(x);
			qread(y);
			x^=last;
			y^=last;
			change_val(x,y);
		}else if(cmd==2){
			qread(x);
			qread(y);
			x^=last;
			y^=last;
			add_point(x,y); 
		}else{
			qread(x);
			x^=last;
			split(x);
		}
	}
}

```

