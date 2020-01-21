## [BZOJ2594] [WC2006]水管局长(Kruskal+LCT)

### 题面

SC省MY市有着庞大的地下水管网络，嘟嘟是MY市的水管局长（就是管水管的啦），嘟嘟作为水管局长的工作就是：每天供水公司可能要将一定量的水从x处送往y处，嘟嘟需要为供水公司找到一条从A至B的水管的路径，接着通过信息化的控制中心通知路径上的水管进入准备送水状态，等到路径上每一条水管都准备好了，供水公司就可以开始送水了。嘟嘟一次只能处理一项送水任务，等到当前的送水任务完成了，才能处理下一项。

在处理每项送水任务之前，路径上的水管都要进行一系列的准备操作，如清洗、消毒等等。嘟嘟在控制中心一声令下，这些水管的准备操作同时开始，但由于各条管道的长度、内径不同，进行准备操作需要的时间可能不同。供水公司总是希望嘟嘟能找到这样一条送水路径，路径上的所有管道全都准备就绪所需要的时间尽量短。嘟嘟希望你能帮助他完成这样的一个选择路径的系统，以满足供水公司的要求。另外，由于MY市的水管年代久远，一些水管会不时出现故障导致不能使用，你的程序必须考虑到这一点。

不妨将MY市的水管网络看作一幅简单无向图（即没有自环或重边）：水管是图中的边，水管的连接处为图中的结点。

### 分析

要求路径上的所有管道全都准备就绪所需要的时间尽量短，实际上就是让最长的边尽量短，显然就是要求一个动态的最小生成树。删边不容易处理，考虑离线转化成动态加边。每加入一条边$(u,v,w)$，就在原来的最小生成树上查询$u$到$v$路径上的最长边$k$.如果$w<k$,就把那条最长边删掉，换成$w$.否则不进行任何操作。

显然需要用LCT,但是LCT是维护点的,我们可以把边看成一个点。对于第$i$条边$(u,v,w)$,我们$link(u,i+n),link(v,i+n)$,并把$i+n$的点权设为$w$.其他点的点权均为0.然后在LCT上维护点权最大点的点的编号

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
#define maxn 1000
#define maxm 100000
#define maxq 100000
using namespace std;
int n,m,p;
struct edge{
	int from;
	int to;
	int len;
	bool is_del;
	friend bool operator < (edge p,edge q){
		return p.len<q.len;
	}
}E[maxm+5];
map< pair<int,int> , int> id;

struct oper{
	int type;
	int x;
	int y;
	int id;
	int ans;
}q[maxq+5];

struct link_cut_tree{
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1]) 
	struct node{
		int fa;
		int ch[2];
		int revm;
		int id;
		int maxid;
	}tree[maxn+maxm+5];
	inline bool is_root(int x){
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x){
		return rson(fa(x))==x;
	}
	void push_up(int x){
		tree[x].maxid=tree[x].id;
		if(E[tree[lson(x)].maxid].len>E[tree[x].maxid].len) tree[x].maxid=tree[lson(x)].maxid;
		if(E[tree[rson(x)].maxid].len>E[tree[x].maxid].len) tree[x].maxid=tree[rson(x)].maxid;
	}
	void reverse(int x){
		swap(lson(x),rson(x));
		tree[x].revm^=1;
	}
	void push_down(int x){
		if(tree[x].revm){
			reverse(lson(x));
			reverse(rson(x));
			tree[x].revm=0;
		}
	}
	void push_down_all(int x){
		if(!is_root(x)) push_down_all(fa(x));
		push_down(x);
	}
	void rotate(int x){
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
	void splay(int x){
		push_down_all(x);
		while(!is_root(x)){
			int y=fa(x);
			if(!is_root(y)){
				if(check(x)==check(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		push_up(x);
	}
	void access(int x){
		for(int y=0;x;y=x,x=fa(x)){
			splay(x);
			rson(x)=y;
			push_up(x);
		}
	}
	void make_root(int x){
		access(x);
		splay(x);
		reverse(x);
	}
	void link(int x,int y){
		make_root(x);
		fa(x)=y;
	}
	void split(int x,int y){
		make_root(x);
		access(y);
		splay(y);
	}
	void cut(int x,int y){
		split(x,y);
		fa(x)=lson(y)=0;
		push_up(y);
	}
	int find_root(int x){
		access(x);
		splay(x);
		while(lson(x)){
			push_down(x);
			x=lson(x);
		}
		splay(x);
		return x;
	}
	
	int Query_edge(int x,int y){
		split(x,y);
		return tree[y].maxid;
	}
	inline void Add_edge(int id){
		link(E[id].from,id+n);
		link(E[id].to,id+n);
	}
	inline void Del_edge(int id){
		cut(E[id].from,id+n);
		cut(E[id].to,id+n);
	}
}T;

void kruskal(){
	for(int i=1;i<=m;i++){
		if(!E[i].is_del){
			int x=E[i].from,y=E[i].to;
			if(T.find_root(x)==T.find_root(y)) continue;
//			printf("db: %d\n",id[make_pair(x,y)]);
			T.Add_edge(i);
		}
	}
}
int main(){
//	freopen("7.in","r",stdin); 
	scanf("%d %d %d",&n,&m,&p);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&E[i].from,&E[i].to,&E[i].len);
	}
	sort(E+1,E+1+m);
	for(int i=1;i<=m;i++){
		id[make_pair(E[i].from,E[i].to)]=id[make_pair(E[i].to,E[i].from)]=i;
	}
	for(int i=1;i<=p;i++){
		scanf("%d %d %d",&q[i].type,&q[i].x,&q[i].y);
		if(q[i].type==2){
			int t=id[make_pair(q[i].x,q[i].y)];
			q[i].id=t;
			E[t].is_del=1;
		}
	}
	for(int i=1;i<=n+m;i++){
		if(i<=n) T.tree[i].id=0;
		else T.tree[i].id=i-n;
	}
	kruskal();
	for(int i=p;i>=1;i--){
		int x=q[i].x,y=q[i].y;
		if(q[i].type==1){
			q[i].ans=E[T.Query_edge(x,y)].len;
		}else{
			int pre=T.Query_edge(x,y);
			int nex=q[i].id;
			if(E[pre].len>E[nex].len){
				T.Del_edge(pre);
				T.Add_edge(nex);
			} 
		}
	}
	for(int i=1;i<=p;i++){
		if(q[i].type==1) printf("%d\n",q[i].ans);
	}
}
```

