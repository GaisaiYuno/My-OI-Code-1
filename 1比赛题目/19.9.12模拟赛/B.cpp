#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 300000
#define maxlogn 25
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
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar(x%10+'0');
	}
}

int testcase;
int n,m,t;
int mv;
int a[maxn+5];
int tmp[maxn+5];

struct disjoint_set{
	int fa[maxn+5];
	int sz[maxn+5];
	int find(int x){
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		fa[fx]=fy;
		sz[fy]+=sz[fx];
	}
	int size(int x){
		return sz[find(x)];
	}
	void ini(int n){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			sz[i]=1;
		}
	}
}S;

struct persist_segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxn*30+5];
	int ptr;
	void push_up(int x){
		tree[x].val=tree[lson(x)].val+tree[rson(x)].val;
	}
	void update(int &x,int last,int upos,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].val++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(lson(x),lson(last),upos,l,mid);
		else update(rson(x),rson(last),upos,mid+1,r);
		push_up(x);
	}
	int query(int x,int y,int lc,int lcfa,int k,int l,int r){
		if(l==r){
			return l;
		}
		int lcnt=tree[lson(x)].val+tree[lson(y)].val-tree[lson(lc)].val-tree[lson(lcfa)].val;
		int mid=(l+r)>>1;
		if(k<=lcnt) return query(lson(x),lson(y),lson(lc),lson(lcfa),k,l,mid);
		else return query(rson(x),rson(y),rson(lc),rson(lcfa),k-lcnt,mid+1,r);
	}
}T;

struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	head[v]=sz;
}

int log2n;
int root[maxn+5];
int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	T.update(root[x],root[fa],a[x],1,mv);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
	}
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

void merge(int x,int y){
	if(S.size(x)>S.size(y)) swap(x,y);
	add_edge(x,y);
	dfs(x,y);
	S.merge(x,y);
}
int query(int x,int y,int k){
	int lc=lca(x,y);
	int lcfa=anc[lc][0];
	int ans=T.query(root[x],root[y],root[lc],root[lcfa],k,1,mv);
	return tmp[ans];
}

void discrete(){
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	mv=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+mv,a[i])-tmp;
}

int main(){
	int last=0;
	char op[2];
	int x,y,k;
	qread(testcase);
	qread(n);
	qread(m);
	qread(t);
	log2n=log2(n)+1;
	S.ini(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	discrete();
	for(int i=1;i<=m;i++){
		qread(x);
		qread(y);
		add_edge(x,y);
		S.merge(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!deep[i]) dfs(i,0);
	}
	for(int i=1;i<=t;i++){
		scanf("%s",op);
		if(op[0]=='Q'){
			qread(x);
			qread(y);
			qread(k);
			x^=last;
			y^=last;
			k^=last;
			last=query(x,y,k);
			qprint(last);
			putchar('\n');
		}else{
			qread(x);
			qread(y);
			x^=last;
			y^=last;
			merge(x,y);
		}
	}
	
}
/*
1
8  4 8
1  1 2 2 3 3 4 4
4  7
1  8
2  4
2  1
Q 8 7 3 
Q 3 5 1
Q 10 0 0
L 5 4
L 3 2 
L 0 7
Q 9 2 5 
Q 6 1 6
*/

