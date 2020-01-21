#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
#define maxn 30000
#define maxm 100000
#define maxq 40000
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
		putchar(x%10+'0');
	}
}

int n,m,qcnt;
struct edge {
	int from;
	int to;
	bool is_del;
} E[maxm+5];
map< pair<int,int>, int >id;

struct oper {
	int type;
	int x;
	int y;
	int ans;
} q[maxq+5];

struct LCT {
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
	struct node {
		int ch[2];
		int fa;
		int revm;
		int sz;
	} tree[maxn+5];
	int bel[maxn+5];
	//并查集维护双连通分量关系,这里不能直接用Splay的fa(虽然也要存储);
	//选联通分量中的一个节点作为代表节点
	//LCT模板里的fa(x)用find_bel(fa(x))代替,相当于每次跳到fa(x)所在e-DCC的代表节点
	//如果两个点的fa不相等，则说明不在一个e-DCC中
	int find_bel(int x) {
		if(bel[x]==x) return x;
		else return bel[x]=find_bel(bel[x]);
	}
	int con_id[maxn+5]; //并查集维护连通性
	int find_con(int x) {
		if(con_id[x]==x) return x;
		else return con_id[x]=find_con(con_id[x]);
	}
	void merge_con(int x,int y) {
		con_id[find_con(x)]=find_con(y);
	}

	void push_up(int x) {
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
	}
	inline bool is_root(int x) {
		return !(lson(find_bel(fa(x)))==x||rson(find_bel(fa(x)))==x);
	}
	int check(int x) {
		return rson(find_bel(fa(x)))==x;
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
		if(!is_root(x)) push_down_all(find_bel(fa(x)));
		push_down(x);
	}
	void rotate(int x) {
		int y=find_bel(fa(x)),z=find_bel(fa(y)),k=check(x),w=tree[x].ch[k^1];
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
			int y=find_bel(fa(x));
			if(!is_root(y)) {
				if(check(x)==check(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		push_up(x);
	}
	void access(int x) {
		for(int y=0; x; y=x,x=find_bel(fa(x))) {
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
	void split(int x,int y) {
		make_root(x);
		access(y);
		splay(y);
	}
	void link(int x,int y) {
		make_root(x);
		fa(x)=y;
	}
	void cut(int x,int y) {
		split(x,y);
		fa(x)=lson(y)=0;
		push_up(y);
	}

	void dfs_tree(int x,int y) {
		bel[x]=y;
		push_down(x);
		if(lson(x)) dfs_tree(lson(x),y);
		if(rson(x)) dfs_tree(rson(x),y);
	}
	void shrink(int x,int y) {
		split(x,y);
		dfs_tree(y,y);//把这棵树(整个联通块)里的节点全部指向y
		lson(y)=0;
	}
	int query_sum(int x,int y) {
		split(x,y);
		return tree[y].sz;
	}
	inline void ini(int n) {
		for(int i=1; i<=n; i++) {
			tree[i].sz=1;
			bel[i]=con_id[i]=i;
		}
	}
} T;

void work_edge(int x,int y) {
	int fx=T.find_bel(x),fy=T.find_bel(y);
	if(fx!=fy) {
		if(T.find_con(fx)!=T.find_con(fy)) {
			T.link(fx,fy);
			T.merge_con(fx,fy);
		} else {
			T.shrink(fx,fy);
		}
	}
}
int main() {
	int tp,x,y;
	qread(n);
	qread(m);
	for(int i=1; i<=m; i++) {
		qread(E[i].from);
		qread(E[i].to);
		id[make_pair(E[i].from,E[i].to)]=i;
		id[make_pair(E[i].to,E[i].from)]=i;
	}
	while(scanf("%d",&tp)!=EOF) {
		if(tp==-1) break;
		scanf("%d %d",&x,&y);
		qcnt++;
		q[qcnt].type=tp;
		q[qcnt].x=x;
		q[qcnt].y=y;
		if(tp==0) E[id[make_pair(x,y)]].is_del=1;
	}

	T.ini(n);
	for(int i=1; i<=m; i++) {
		if(!E[i].is_del) work_edge(E[i].from,E[i].to);
	}
	for(int i=qcnt; i>=1; i--) {
		if(q[i].type==0) {
			work_edge(q[i].x,q[i].y);
		} else {
			q[i].ans=T.query_sum(T.find_bel(q[i].x),T.find_bel(q[i].y))-1;
		}
	}
	for(int i=1; i<=qcnt; i++) {
		if(q[i].type==1) {
			qprint(q[i].ans);
			putchar('\n');
		}
	}
}
