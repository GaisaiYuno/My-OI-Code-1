//http://119.29.55.79/contest/95/problem/5
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<cmath>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 100000
#define maxlogn 22
#define maxnlogn 10000000
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
		putchar('0'+x%10);
	}
}

int testcase;//是测试点编号，不是数据组数... 
int n,m,q,mv;
int val[maxn+5];
int tmp[maxn+5];
int discrete(int *a,int n){
	int sz=0;
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	sz=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(tmp+1,tmp+1+sz,a[i])-tmp;
	}
	return sz;
}

struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int esz;
void add_edge(int u,int v){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
	esz++;
	E[esz].from=v;
	E[esz].to=u;
	E[esz].next=head[v];
	head[v]=esz;
}

struct disjoint_set{
	int fa[maxn+5];
	int sz[maxn+5];
	void ini(int n){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			sz[i]=1;
		}
	}
	int find(int x){
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	inline int size(int x){//返回x所在联通块大小 
		return sz[find(x)];
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(sz[fx]>sz[fy]) swap(fx,fy);
		fa[fx]=fy;
		sz[fy]+=sz[fx]; 
	} 
}S;

struct persist_segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxnlogn+5];
	int ptr;
	inline void push_up(int x){
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
		int mid=(l+r)>>1;
		int lcnt=tree[lson(x)].val+tree[lson(y)].val-tree[lson(lc)].val-tree[lson(lcfa)].val;
		if(k<=lcnt) return query(lson(x),lson(y),lson(lc),lson(lcfa),k,l,mid);
		else return query(rson(x),rson(y),rson(lc),rson(lcfa),k-lcnt,mid+1,r); 
	}
#undef lson
#undef rson
}T;
int root[maxn+5];

int log2n;
int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	T.update(root[x],root[fa],val[x],1,mv);
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
	S.merge(x,y);
	add_edge(x,y);
	if(deep[y]==0) deep[y]=1;
	dfs(x,y);//注意不是dfs(x,0),因为x的父亲是y 
} 
int query(int x,int y,int k){
	int lc=lca(x,y);
	int id=T.query(root[x],root[y],root[lc],root[anc[lc][0]],k,1,mv);
	return tmp[id];
}


int main(){
//	freopen("5.in","r",stdin);
	int last=0;
	char op[2];
	int x,y,k;
	qread(testcase);
	qread(n);
	qread(m);
	qread(q);
	S.ini(n);
	log2n=log2(n)+1; 
	for(int i=1;i<=n;i++) qread(val[i]);
	mv=discrete(val,n);
	for(int i=1;i<=m;i++){
		qread(x);
		qread(y);
		add_edge(x,y);
		S.merge(x,y);
	} 
	for(int i=1;i<=n;i++){
		if(!anc[i][0]) dfs(i,0);
	}
	for(int i=1;i<=q;i++){
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
8 4 8
1 1 2 2 3 3 4 4
4 7
1 8
2 4
2 1
Q 8 7 3 
Q 3 5 1
Q 10 0 0
L 5 4
L 3 2 
L 0 7
Q 9 2 5 
Q 6 1 6
*/

