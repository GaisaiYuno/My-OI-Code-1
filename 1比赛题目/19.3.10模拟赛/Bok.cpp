#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 100005
#define maxb 505
#define ll unsigned long long
using namespace std;
int n,m;
struct segment_tree {
	ll t[maxn];
	inline ll lowbit(int x){
		return x&(-x);
	}
	void update(int x,ll v){
		while(x<=n){
			t[x]+=v;
			x+=lowbit(x);
		}
	}
	ll sum(int x){
		ll ans=0;
		while(x>0){
			ans+=t[x];
			x-=lowbit(x);
		}
		return ans;
	}
	ll query(int l,int r){
		return sum(r)-sum(l-1);
	}
//	struct node {
//		int l;
//		int r;
//		ll v;
//	} tree[maxn<<2];
//	void push_up(int pos) {
//		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
//	}
//	void build(int l,int r,int pos) {
//		tree[pos].l=l;
//		tree[pos].r=r;
//		if(l==r) {
//			return;
//		}
//		int mid=(l+r)>>1;
//		build(l,mid,pos<<1);
//		build(mid+1,r,pos<<1|1);
//	}
//	void update(int tpos,ll v,int pos) {
//		if(tree[pos].l==tree[pos].r) {
//			tree[pos].v+=v;
//			return;
//		}
//		int mid=(tree[pos].l+tree[pos].r)>>1;
//		if(tpos<=mid) update(tpos,v,pos<<1);
//		else update(tpos,v,pos<<1|1);
//		push_up(pos);
//	}
//	ll query(int L,int R,int pos) {
//		if(L<=tree[pos].l&&R>=tree[pos].r) {
//			return tree[pos].v;
//		}
//		ll ans=0;
//		int mid=(tree[pos].l+tree[pos].r)>>1;
//		if(L<=mid) ans+=query(L,R,pos<<1);
//		if(R>mid) ans+=query(L,R,pos<<1|1);
//		return ans;
//	}
}T;

struct edge {
	int from;
	int to;
	int next;
} E[maxn<<1];
int head[maxn];
int esz=1;
void add_edge(int u,int v) {
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}


ll a[maxn];
int bsz,bcnt;//块大小，块个数
inline int lb(int id) {
	return (id-1)*bsz+1;
}
inline int rb(int id) {
	return (id*bsz>n)?n:id*bsz;
}
int cnt[maxb];//cnt[i]存第i个块内有多少个当前搜索树中的节点
int f[maxn][maxb]; //f[i][j]存第i个块内有多少个j的祖先节点
ll sum[maxn];//整块的和 
int id[maxn];
int dfnl[maxn],dfnr[maxn];
int tim=0;
void dfs(int x,int fa) {
	dfnl[x]=++tim;
	cnt[id[x]]++;
	for(int i=1; i<=bcnt; i++) {
		f[x][i]=cnt[i];
	}
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			dfs(y,x);
		}
	}
	dfnr[x]=tim;
	cnt[id[x]]--;
}

void change(int u,ll v){
	ll pre=T.query(dfnl[u],dfnl[u]);
	T.update(dfnl[u],v-pre);
	for(int i=1;i<=bcnt;i++){
		sum[i]+=(ll)f[u][i]*(v-pre);
	}
} 
ll ask(int l,int r){
	ll ans=0;
	for(int i=l;i<=min(r,rb(id[l]));i++){
		ans+=T.query(dfnl[i],dfnr[i]);
	}
	for(int i=id[l]+1;i<id[r];i++){
		ans+=sum[i]; 
	}
	if(id[l]!=id[r]){
		for(int i=lb(id[r]);i<=r;i++){
			ans+=T.query(dfnl[i],dfnr[i]);
		}
	}
	return ans;
}
int main() {
	int op,u,v,l,r,root;
	ll k;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%llu",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&u,&v);
		if(u==0) root=v;
		else{
			add_edge(u,v);
			add_edge(v,u);
		}
	}
	bsz=sqrt(n);
	bcnt=1;
	for(int i=1;i<=n;i++){
		id[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
	dfs(root,0);
	for(int i=1;i<=n;i++){
		T.update(dfnl[i],a[i]);
	}
	for(int i=1;i<=n;i++){
		sum[id[i]]+=T.query(dfnl[i],dfnr[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&u);
			scanf("%llu",&k);
			change(u,k);
		}else{
			scanf("%d %d",&l,&r);
			printf("%llu\n",ask(l,r));
		}
	}
}

