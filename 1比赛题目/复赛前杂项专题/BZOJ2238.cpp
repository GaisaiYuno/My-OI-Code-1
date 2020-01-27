//http://119.29.55.79/problem/544
//对于一条非树边，它可以替代生成树上两端点路径上的树边
//所以如果删掉的是生成树上的边,就查询可以替代这条树边的非树边的最小值,更新生成树长度
//对于每条树边区间修改，查询时树剖区间查询即可
//否则答案不变
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 50000
#define maxm 100000
#define INF 0x3f3f3f3f
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

int n,m,q;
namespace Kruskal {
	struct edge {
		int from;
		int to;
		int id;//记录初始编号，防止排序时混乱 
		int len;
		int type;//树边/非树边
		friend bool operator < (edge p,edge q) {
			return p.len<q.len;
		}
	} E[maxm+5];
	int fa[maxn+5];
	int find(int x) {
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}

	vector<int>T[maxn+5];
	int kruskal() { //求出最小生成树长度，并建出生成树
		int ans=0;
		for(int i=1; i<=n; i++) fa[i]=i;
		sort(E+1,E+1+m);
		for(int i=1; i<=m; i++) {
			int x=E[i].from,y=E[i].to;
			int fx=find(x),fy=find(y);
			if(fx!=fy) {
				ans+=E[i].len;
				E[i].type=1;
				fa[fx]=fy;
			}
		}
		
		static edge tmp[maxm+5];
		for(int i=1;i<=m;i++) tmp[E[i].id]=E[i];
		for(int i=1;i<=m;i++) E[i]=tmp[i];//将边复位 
		
		int cnt_block=0;
		for(int i=1; i<=n; i++) if(fa[i]==i) cnt_block++;
		if(cnt_block>1) return -1;//图不联通
		else return ans;
	}
}

namespace HLD {
	struct segment_tree {
		struct node {
			int l;
			int r;
			int mark;
			int val;
		} tree[maxn*4+5];
		void push_up(int pos) {
			tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
		}
		void build(int l,int r,int pos) {
			tree[pos].l=l;
			tree[pos].r=r;
			tree[pos].mark=INF;
			tree[pos].val=INF;
			if(l==r) return;
			int mid=(l+r)>>1;
			build(l,mid,pos<<1);
			build(mid+1,r,pos<<1|1);
			push_up(pos);
		}
		void push_down(int pos) {
			if(tree[pos].mark!=INF) {//注意标记设成INF 
				tree[pos<<1].mark=min(tree[pos<<1].mark,tree[pos].mark);
				tree[pos<<1|1].mark=min(tree[pos<<1|1].mark,tree[pos].mark);
				tree[pos<<1].val=min(tree[pos<<1].val,tree[pos].mark);
				tree[pos<<1|1].val=min(tree[pos<<1|1].val,tree[pos].mark);
				tree[pos].mark=INF;
			}
		}
		void update(int L,int R,int val,int pos) {
			if(L<=tree[pos].l&&R>=tree[pos].r) {
				tree[pos].val=min(tree[pos].val,val);
				tree[pos].mark=min(tree[pos].mark,val);
				return;
			}
			push_down(pos);
			int mid=(tree[pos].l+tree[pos].r)>>1;
			if(L<=mid) update(L,R,val,pos<<1);
			if(R>mid) update(L,R,val,pos<<1|1);
			push_up(pos);
		}
		int query(int L,int R,int pos) {
			if(L<=tree[pos].l&&R>=tree[pos].r) {
				return tree[pos].val;
			}
			push_down(pos);
			int mid=(tree[pos].l+tree[pos].r)>>1;
			int ans=INF;
			if(L<=mid) ans=min(ans,query(L,R,pos<<1));
			if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
			return ans;
		}
	} T;
	vector<int>E[maxn+5]; 
	inline void add_edge(int u,int v){
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int deep[maxn+5];
	int fa[maxn+5],son[maxn+5];
	int sz[maxn+5];
	void dfs1(int x,int f) {
		deep[x]=deep[f]+1;
		sz[x]=1;
		fa[x]=f;
		for(int i=0; i<(int)E[x].size(); i++) {
			int y=E[x][i];
			if(y!=f) {
				dfs1(y,x);
				sz[x]+=sz[y];
				if(sz[y]>sz[son[x]]) son[x]=y;
			}
		}
	}
	int tim;
	int dfn[maxn+5];
	int top[maxn+5];
	void dfs2(int x,int t) {
		dfn[x]=++tim;
		top[x]=t;
		if(son[x]) dfs2(son[x],t);
		for(int i=0; i<(int)E[x].size(); i++) {
			int y=E[x][i];
			if(y!=fa[x]&&y!=son[x]) {
				dfs2(y,y);
			}
		}
	}

	void update(int x,int y,int val) {
		int tx=top[x],ty=top[y];
		while(tx!=ty) {
			if(deep[tx]<deep[ty]) {
				swap(tx,ty);
				swap(x,y);
			}
			T.update(dfn[tx],dfn[x],val,1);
			x=fa[tx];
			tx=top[x];
		}
		if(x==y) return;
		if(deep[x]>deep[y]) swap(x,y);//否则下面用到son[x]就会爆 
		T.update(dfn[son[x]],dfn[y],val,1);//因为是边更新，最顶上的那个点是不用更新的 
	}
	int query(int x,int y) {
		int tx=top[x],ty=top[y];
		int ans=INF;
		while(tx!=ty) {
			if(deep[tx]<deep[ty]) {
				swap(tx,ty);
				swap(x,y);
			}
			ans=min(ans,T.query(dfn[tx],dfn[x],1));
			x=fa[tx];
			tx=top[x];
		}
		if(deep[x]>deep[y]) swap(x,y);
		if(x==y) return ans; 
		ans=min(ans,T.query(dfn[son[x]],dfn[y],1));
		return ans;
	}
}


int main() {
	using namespace Kruskal;
	int id;
	qread(n);
	qread(m);
	for(int i=1; i<=m; i++) {
		qread(E[i].from);
		qread(E[i].to);
		qread(E[i].len);
		E[i].id=i; 
	}
	int tot_len=kruskal();
	bool is_cnct=true;
	if(tot_len==-1) is_cnct=false;
	if(is_cnct) {
		for(int i=1;i<=m;i++){
			if(E[i].type==1){
				HLD::add_edge(E[i].from,E[i].to);
			}
		}
		HLD::dfs1(1,0);
		HLD::dfs2(1,1);
		HLD::T.build(1,n,1);
		for(int i=1; i<=m; i++) {
			if(E[i].type==0) HLD::update(E[i].from,E[i].to,E[i].len);
		}
	}
	
//	printf("debug %d\n",HLD::query(2,4)); 
	qread(q);
	for(int k=1; k<=q; k++) {
		qread(id);
		if(!is_cnct) puts("Not connected");
		else {
			if(E[id].type==0) {
				qprint(tot_len);
				putchar('\n');
			} else {
				int newlen=HLD::query(E[id].from,E[id].to);
				if(newlen==INF) puts("Not connected");
				else {
					qprint(tot_len-E[id].len+newlen);
					putchar('\n');
				}
			}
		}
	}
}

