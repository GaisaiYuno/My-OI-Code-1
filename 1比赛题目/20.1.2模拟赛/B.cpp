#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
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
inline void qprint(long long x) {
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

int n,q;
int ch[maxn+5][2],fa[maxn+5];
#define lson(x) (ch[x][0])
#define rson(x) (ch[x][1]) 
long long ans=0;
int sz[maxn+5],son[maxn+5];
int deep[maxn+5];
int sum=0;
void dfs1(int x,int f) {
	fa[x]=f;
	sz[x]=1;
	deep[x]=deep[f]+1;
	for(int i=0; i<=1; i++) {
		int y=ch[x][i];
		if(y!=0) {
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
	ans+=son[x];
}

int tim=0;
int dfn[maxn+5],hash_dfn[maxn+5];
int top[maxn+5];
void dfs2(int x,int t){
	dfn[x]=++tim;
	hash_dfn[dfn[x]]=x;
	top[x]=t;
	if(son[x]) dfs2(son[x],t);
	for(int i=0; i<=1; i++) {
		int y=ch[x][i];
		if(y!=0&&y!=fa[x]&&y!=son[x]) {
			dfs2(y,y);
		}
	}
}

struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
		int addm;
		int len(){
			return r-l+1;
		} 
	}tree[maxn*4+5];
	void push_up(int pos){
//		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void add_tag(int x,int val){
		tree[x].v+=val*tree[x].len();
		tree[x].addm+=val;
	}
	void push_down(int x){
		if(tree[x].addm){
			add_tag(x<<1,tree[x].addm);
			add_tag(x<<1|1,tree[x].addm);
			tree[x].addm=0;
		}
	} 
	void update(int L,int R,int val,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			add_tag(pos,val);
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
		push_up(pos);
	}
	int query(int qpos,int pos){
		if(tree[pos].l==tree[pos].r){
			return tree[pos].v;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1; 
		if(qpos<=mid) return query(qpos,pos<<1);
		else return query(qpos,pos<<1|1);
	}
}Tsz;


int kth_anc(int x,int k){//x的k级祖先 
	int x0=x;
	while(deep[top[x]]>deep[x0]-k) x=fa[top[x]];//先跳整段的 
	return hash_dfn[dfn[x]+deep[x0]-k-deep[x]];//利用重链上dfs序连续,找到剩余那一段 
}
void update_sz(int x){
	while(x){
		Tsz.update(dfn[top[x]],dfn[x],-1,1);
		x=fa[top[x]];
	}
}
void update_son(int x){
	if(x){
		ans-=son[x];
		int lsz=Tsz.query(dfn[lson(x)],1);
		int rsz=Tsz.query(dfn[rson(x)],1);
		int xsz=Tsz.query(dfn[son[x]],1);
		if(lsz==0&&rsz==0) son[x]=0;
		else if(max(lsz,rsz)!=xsz){
			if(lsz==max(lsz,rsz))son[x]=ch[x][0];
			else son[x]=ch[x][1];
		}
		ans+=son[x];
	}
}
int bin_search(int x,int l,int r){
	int ans=0;
	int mid;
	int all=Tsz.query(dfn[kth_anc(x,r)],1);
	while(l<=r){
		mid=(l+r)>>1;
		if(Tsz.query(dfn[kth_anc(x,mid)],1)*2<=all){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
void del(int x){
	int d=deep[x];
	update_sz(x);
	while(d){
		//二分出最上面的一条轻边
		int nex=bin_search(x,1,d);
		update_son(kth_anc(x,nex+1));
		if(nex==0) break;
		else d=nex;
	}
}

int main() {
	int x;
	qread(n);
	for(int i=1; i<=n; i++) {
		qread(ch[i][0]);
		qread(ch[i][1]);
	} 
	qread(q);
	dfs1(1,0);
	dfs2(1,0);
	Tsz.build(1,n,1);
	for(int i=1;i<=n;i++) Tsz.update(dfn[i],dfn[i],sz[i],1);
//	for(int i=1;i<=n;i++){
//		printf("db: %d\n",sz[i]); 
//	}
	qprint(ans);
	putchar('\n'); 
	for(int i=1;i<=q;i++){
		qread(x);
		del(x);
		qprint(ans);
		putchar('\n');
	}
}
