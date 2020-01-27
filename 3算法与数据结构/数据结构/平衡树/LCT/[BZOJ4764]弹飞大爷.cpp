#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
using namespace std;
struct link_cut_tree {
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
#define fa(x) (tree[x].fa)
	struct node {
		int ch[2];
		int fa;
		int sz;
//		int revm; 有根树不能make_root,自然也不需要反转标记
		int out;//环上的那条边
	} tree[maxn+5];
	inline bool is_root(int x) {
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x) {
		return rson(fa(x))==x;
	}
	void push_up(int x) {
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
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
//		push_down_all(x);
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
	int find_root(int x) {
		access(x);
		splay(x);
		while(lson(x)) {
			x=lson(x);
		}
		splay(x);
		return x;
	}
	void link(int x,int y) {
		if(find_root(y)==x) tree[x].out=y;
		else {
			access(x);
			splay(x);//有根树不能make_root
			fa(x)=y;
		}
	}
	void cut(int x,int y) {
		if(tree[x].out==y) tree[x].out=0;
		else {
			int rt=find_root(x);
			access(x);
			splay(x);
			fa(lson(x))=0;
			lson(x)=0;
			push_up(x);
			
			if(tree[rt].out&&find_root(tree[rt].out)!=rt) {
				link(rt,tree[rt].out);//删掉一条边后，原来的环上边变成树边
				tree[rt].out=0;
			}
		}
	}
	int query(int x) {
		access(x);
		int rt=find_root(x);
		if(tree[rt].out) return -1;//有环
		else {
			splay(x);
			return tree[x].sz;
		}
	}
} T;

int n,m;
int a[maxn+5];

bool check(int x) {
	return x>=1&&x<=n;
}
int main() {
#ifdef LOCAL
	freopen("4764.in","r",stdin);
#endif
	int cmd,x,k;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1; i<=n; i++) T.tree[i].sz=1;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(check(i+a[i]))T.link(i,i+a[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d",&cmd);
		if(cmd==1) {
			scanf("%d",&x);
			printf("%d\n",T.query(x));
		} else {
			
			scanf("%d %d",&x,&k);
			if(check(x+a[x])) T.cut(x,x+a[x]);
			a[x]=k;
			if(check(x+a[x])) T.link(x,x+a[x]);
		}

	}

}

