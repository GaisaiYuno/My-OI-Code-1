#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
#define maxn 100000
#define maxm 300000
#define INF 0x3f3f3f3f
using namespace std;
int n,m,p;
struct edge {
	int from;
	int to;
	int tem;
	int len;
	friend bool operator < (edge p,edge q) {
		return p.tem<q.tem;
	}
} E[maxm+5];
//map< pair<int,int> , int> id;



struct link_cut_tree {
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
	struct node {
		int fa;
		int ch[2];
		int revm;
		int id;
		int maxid;
		int sum;
	} tree[maxn+maxm+5];
	inline bool is_root(int x) {
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x) {
		return rson(fa(x))==x;
	}
	void push_up(int x) {
		tree[x].maxid=tree[x].id;
		if(E[tree[lson(x)].maxid].tem<E[tree[x].maxid].tem) tree[x].maxid=tree[lson(x)].maxid;
		if(E[tree[rson(x)].maxid].tem<E[tree[x].maxid].tem) tree[x].maxid=tree[rson(x)].maxid;
		tree[x].sum=tree[lson(x)].sum+tree[rson(x)].sum+E[tree[x].id].len;
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
			rson(x)=y;
			push_up(x);
		}
	}
	void make_root(int x) {
		access(x);
		splay(x);
		reverse(x);
	}
	void link(int x,int y) {
		make_root(x);
		fa(x)=y;
	}
	void split(int x,int y) {
		make_root(x);
		access(y);
		splay(y);
	}
	void cut(int x,int y) {
		split(x,y);
		fa(x)=lson(y)=0;
		push_up(y);
	}
	int find_root(int x) {
		access(x);
		splay(x);
		while(lson(x)) {
			push_down(x);
			x=lson(x);
		}
		splay(x);
		return x;
	}
	int Query_sum(int x,int y) {
		split(x,y);
		return tree[y].sum;
	}
	int Query_tem(int x,int y) {
		split(x,y);
		return tree[y].maxid;
	}
	inline void Add_edge(int id) {
		link(E[id].from,id+n);
		link(E[id].to,id+n);
	}
	inline void Del_edge(int id) {
		cut(E[id].from,id+n);
		cut(E[id].to,id+n);
	}
} T;

void kruskal() {
	for(int i=1; i<=m; i++) {

		int x=E[i].from,y=E[i].to;
		if(T.find_root(x)==T.find_root(y)) continue;
//			printf("db: %d\n",id[make_pair(x,y)]);
		T.Add_edge(i);

	}
}
int main() {
	char cmd[10];
	int u,v,id;
//	freopen("7.in","r",stdin);
	scanf("%d %d",&n,&m);
	E[0].tem=INF; 
	for(int i=1; i<=n+m; i++) {
		if(i<=n) T.tree[i].id=0;
		else  T.tree[i].id=i-n;
	}
	for(int xx=1; xx<=m; xx++) {
		scanf("%s",cmd);
		if(cmd[0]=='f') {
			scanf("%d",&id);
			id++;
			scanf("%d %d %d %d",&E[id].from,&E[id].to,&E[id].tem,&E[id].len);
			E[id].from++;
			E[id].to++;
			if(T.find_root(E[id].from)!=T.find_root(E[id].to)) T.Add_edge(id);
			else {
				int tem=T.Query_tem(E[id].from,E[id].to);
				if(E[id].tem>E[tem].tem) {
					T.Del_edge(tem);
					T.Add_edge(id);
				} else if(E[id].tem==E[tem].tem&&E[id].len<E[tem].len) {
					T.Del_edge(tem);
					T.Add_edge(id);
				}
			}

		} else if(cmd[0]=='m') {
			scanf("%d %d",&u,&v);
			u++;
			v++;
			if(T.find_root(u)!=T.find_root(v)) printf("-1\n");
			else printf("%d\n",T.Query_sum(u,v));
		} else {
			scanf("%d %d",&id,&u);
			id++;
			E[id].len=u;
			T.make_root(id+n);
		}
	}
}
