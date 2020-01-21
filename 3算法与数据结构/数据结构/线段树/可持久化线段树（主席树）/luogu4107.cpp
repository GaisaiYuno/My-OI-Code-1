#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 250005
#define maxm 500005
#define maxlogn 16
#define INF 0x3f3f3f3f
using namespace std;
int n,m,q;
struct graph {
	struct edge {
		int from;
		int to;
		int next;
		int len;
		friend bool operator < (edge p,edge q) {
			return p.len<q.len;
		}
	} E[maxm];
	int sz;
	int head[maxn];
	void add_edge(int u,int v,int w) {
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].len=w;
		E[sz].next=head[u];
		head[u]=sz;
	}
};
graph G,T;
int val[maxn];
struct kruskal_tree {
	int fa[maxn];
	int find(int x) {
		if(fa[x]==x) return fa[x];
		else return fa[x]=find(fa[x]);
	}
	int size;

	void build() {
		for(int i=1; i<=n*2-1; i++) fa[i]=i;
		size=n;
		sort(G.E+1,G.E+1+m);
		for(int i=1; i<=m; i++) {
			int u=G.E[i].from;
			int v=G.E[i].to;
			int fu=find(u);
			int fv=find(v);
			if(fu!=fv) {
				val[++size]=G.E[i].len;
				fa[fu]=fa[fv]=size;
//				printf("%d->%d\n%d->%d\n",fu,size,fv,size);
				T.add_edge(fu,size,0);
				T.add_edge(size,fu,0);
				T.add_edge(fv,size,0);
				T.add_edge(size,fv,0);
				if(size==2*n-1) break;
			}
		}
	}
	int logn;
	int anc[maxn][20];
	int maxl[maxn][20];
	int hash_dfn[maxn];
	int dfnl[maxn],dfnr[maxn];
	int ptr;
	void dfs(int x,int fa) {
		dfnl[x]=++ptr;
		hash_dfn[ptr]=x;
		anc[x][0]=fa;
		maxl[x][0]=val[fa];
		for(int i=1; i<=logn; i++) {
			anc[x][i]=anc[anc[x][i-1]][i-1];
			maxl[x][i]=max(maxl[x][i-1],maxl[anc[x][i-1]][i-1]);
		}
		for(int i=T.head[x]; i; i=T.E[i].next) {
			int y=T.E[i].to;
			if(y!=fa) {
				dfs(y,x);
			}
		}
		dfnr[x]=ptr;
	}
	int find_close(int x,int v) {
		for(int i=logn; i>=0; i--) {
			if(anc[x][i]>0&&maxl[x][i]<=v) {
				x=anc[x][i];
			}
		}
		return x;
	}
} KT;



struct hjt_segment_tree {
	struct node {
#ifdef DEBUG
		int l;
		int r;
#endif
		int ls;
		int rs;
		int cnt;
	} tree[maxn*maxlogn];
	int root[maxn];
	int ptr;
	void push_up(int pos) {
		tree[pos].cnt=tree[tree[pos].ls].cnt+tree[tree[pos].rs].cnt;
	}
	void insert(int &pos,int last,int upos,int l,int r) {
		pos=++ptr;
		tree[pos]=tree[last];
#ifdef DEBUG
		tree[pos].l=l;
		tree[pos].r=r;
#endif
		if(l==r) {
			tree[pos].cnt++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) insert(tree[pos].ls,tree[last].ls,upos,l,mid);
		else insert(tree[pos].rs,tree[last].rs,upos,mid+1,r);
		push_up(pos);
	}
	int query(int ql,int qr,int qk,int l,int r) {
		if(l==r) {
			return l;
		}
		int mid=(l+r)>>1;
		int lcnt=tree[tree[qr].ls].cnt-tree[tree[ql].ls].cnt;
		if(qk<=lcnt) return query(tree[ql].ls,tree[qr].ls,qk,l,mid);
		else return query(tree[ql].rs,tree[qr].rs,qk-lcnt,mid+1,r);
	}
} HT;


int dis_cnt;
int seq[maxn];
int tmp[maxn];
void kruskal_tree_ini() {
	KT.build();
	KT.logn=log2(KT.size);
	for(int i=KT.size; i>=1; i--) {//由于图可能不联通，要dfs多次 
		if(!KT.dfnl[i]) KT.dfs(KT.find(i),0);
	}
}

void hjt_tree_ini() {
	for(int i=1; i<=KT.size; i++) {
		if(i>n) seq[KT.dfnl[i]]=0;
		else seq[KT.dfnl[i]]=val[i];
	}
	for(int i=1; i<=KT.size; i++) {
		tmp[++dis_cnt]=seq[i];
	}
	sort(tmp+1,tmp+1+dis_cnt);
	dis_cnt=unique(tmp+1,tmp+1+dis_cnt)-tmp-1;
	for(int i=1; i<=KT.size; i++) {
		int ds=lower_bound(tmp+1,tmp+1+dis_cnt,seq[i])-tmp;
		HT.insert(HT.root[i],HT.root[i-1],ds,1,dis_cnt);
	}
}

int cal(int ver,int lim,int k) {
	int rt=KT.find_close(ver,lim);
	int l=KT.dfnl[rt],r=KT.dfnr[rt];
	//由于我们把非叶子节点的权值设为0，且[l,r]中可能有0，所以要注意 
	if(l==r) {//如果直接询问叶子节点，那么[l,r]中不可能有0，直接判断 
		if(k>1) return -1;
		else return val[rt];
	} else {
		//如果询问的子树大小>1,那么[l,r]中一定有0，第k大的数就是从小到大(r-l+1)+k个 
		int ans=HT.query(HT.root[l],HT.root[r],(r-l+1)-k,1,dis_cnt);
		if(tmp[ans]==0) return -1;
		else return tmp[ans];
	}

}
int main() {
	int u,v,w;
	int ver,lim,k;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1; i<=n; i++) {
		scanf("%d",&val[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&u,&v,&w);
		G.add_edge(u,v,w);
	}
	kruskal_tree_ini();
	hjt_tree_ini();
	for(int i=1; i<=q; i++) {
		scanf("%d %d %d",&ver,&lim,&k);
		printf("%d\n",cal(ver,lim,k));
	}
}
/*
6 6 4
1 2 3 4 5 6
1 2 3
1 3 4
2 3 4
4 6 4
5 6 4
4 5 3
1 3 1
2 3 2
4 3 1
5 3 2
*/
