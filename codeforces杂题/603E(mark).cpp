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
