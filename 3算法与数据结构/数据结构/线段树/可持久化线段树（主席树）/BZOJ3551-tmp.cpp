//http://119.29.55.79/contest/95/problem/6
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 100000
#define maxm 500000
#define maxlogn 16
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
int n,m,mv,q;
int val[maxn+5];//原来点的权值 
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
	int len;
	friend bool operator < (edge p,edge q){
		return p.len<q.len;
	}
}G[maxm+5];

int lim[maxn*2+5];//kruskal重构树上点的权值 
vector<int>E[maxn*2+5];
void add_edge(int u,int v){
//	printf("%d %d\n",u,v);
	E[u].push_back(v);
	E[v].push_back(u);
}

int cnt=0;
int fa[maxn*2+5];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void kruskal(){
	cnt=n;
	for(int i=1;i<=n*2;i++) fa[i]=i;
	sort(G+1,G+1+m);
	for(int i=1;i<=m;i++){
		int x=G[i].from;
		int y=G[i].to;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			cnt++;
			fa[fx]=cnt;
			fa[fy]=cnt;
			lim[cnt]=G[i].len;
//			printf("lim[%d]=%d\n",cnt,G[i].len);
			add_edge(fx,cnt);
			add_edge(fy,cnt);
		}
	}
} 


struct persist_segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxn*2*maxlogn+5];
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
	int query(int xl,int xr,int k,int l,int r){
		if(l==r){
			return l;
		}
		int mid=(l+r)>>1;
		int lcnt=tree[lson(xr)].val-tree[lson(xl)].val;
		if(k<=lcnt) return query(lson(xl),lson(xr),k,l,mid);
		else return query(rson(xl),rson(xr),k-lcnt,mid+1,r); 
	}
#undef lson
#undef rson
}T;
int root[maxn*2+5];

int tim=0;
int sz[maxn+5];
int dfnl[maxn*2+5],dfnr[maxn*2+5],hash_dfn[maxn*2+5];
int anc[maxn*2+5][maxlogn+5];
void dfs(int x,int fa){
	sz[x]=1;
	dfnl[x]=++tim;
	hash_dfn[dfnl[x]]=x;
	anc[x][0]=fa;
	for(int i=1;i<=maxlogn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=0;i<(int)E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs(y,x); 
			sz[x]+=sz[y];
		}
	}
	dfnr[x]=tim;
}
void rebuild(){
	dfs(cnt,0);
	for(int i=1;i<=tim;i++){
		T.update(root[i],root[i-1],val[hash_dfn[i]],0,mv);
	}
}
int query(int x,int maxd,int k){
	for(int i=maxlogn;i>=0;i--){
		if(anc[x][i]!=0&&lim[anc[x][i]]<=maxd) x=anc[x][i];
	}
	int l=dfnl[x],r=dfnr[x];
	int tot=sz[x];
	if(tot<k) return -1;
	int id=T.query(root[l-1],root[r],tot-k+1,0,mv);
	if(id==0) return -1;
	return tmp[id]; 
}

int main(){
	int x,y,z;
	qread(n);
	qread(m);
	qread(q);
	for(int i=1;i<=n;i++) qread(val[i]);
	mv=discrete(val,n);
	for(int i=1;i<=m;i++){
		qread(G[i].from);
		qread(G[i].to);
		qread(G[i].len);
	}
	kruskal();
	rebuild();
    int last=-1;
	for(int i=1;i<=q;i++){
		qread(x);
		qread(y);
		qread(z);
		if(last!=-1){
			x^=last;
			y^=last;
			z^=last;
		}
		last=query(x,y,z); 
		qprint(last);
		putchar('\n');
	}
}
