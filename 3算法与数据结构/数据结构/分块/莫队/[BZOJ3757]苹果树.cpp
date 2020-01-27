#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
#define maxn 50000 
#define maxm 100000
#define maxlogn 20
using namespace std;
int n,m;
int a[maxn+5];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int log2n;
int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
int st[maxn+5],ed[maxn+5];
int hash_dfn[maxn*2+5];
int tim=0;
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	st[x]=++tim;
	hash_dfn[tim]=x;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	} 
	ed[x]=++tim;
	hash_dfn[tim]=x;
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

int bsz;
int belong[maxn*2+5];
struct que{
	int l;
	int r;
	int cola,colb;
	int lc;
	int id;
	friend bool operator < (que p,que q){
		if(belong[p.l]==belong[q.l]) return p.r<q.r;
		else return belong[p.l]<belong[q.l];
	}
}q[maxm+5];

int sum=0;
int cnt[maxn+5];
int vis[maxn+5];
void add(int val){
	cnt[val]++;
	if(cnt[val]==1) sum++;
}
void del(int val){
	cnt[val]--;
	if(cnt[val]==0) sum--;
}
void calc(int x){
	if(vis[x]) del(a[x]);//把访问过2次的点去掉 
	else add(a[x]);
	vis[x]^=1;
}

int ans[maxm+5]; 
int main(){
	int root;
	int x,y,lc,qa,qb;
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&u,&v);
		if(u==0||v==0){
			root=u+v;
			continue;
		}
		add_edge(u,v);
		add_edge(v,u);
	}
	log2n=log2(n)+1;
	dfs(root,0);
	bsz=sqrt(n*2);
	for(int i=1;i<=n*2;i++) belong[i]=i/bsz+1;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&x,&y,&qa,&qb);
		lc=lca(x,y);
		if(st[x]>st[y]) swap(x,y);
		if(x==lc){
			q[i].l=st[x];
			q[i].r=st[y];
			q[i].cola=qa;
			q[i].colb=qb;
			q[i].id=i;
			q[i].lc=0;
		}else{
			q[i].l=ed[x];
			q[i].r=st[y];
			q[i].cola=qa;
			q[i].colb=qb;
			q[i].id=i;
			q[i].lc=lc;
		}
	}
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l>q[i].l) calc(hash_dfn[--l]);
		while(r<q[i].r) calc(hash_dfn[++r]);
		while(l<q[i].l) calc(hash_dfn[l++]);
		while(r>q[i].r) calc(hash_dfn[r--]);
		if(q[i].lc) calc(q[i].lc);
		ans[q[i].id]=sum;
		if(q[i].cola!=q[i].colb&&cnt[q[i].cola]&&cnt[q[i].colb]) ans[q[i].id]--;//把a看成b，少一种
		//注意a=b时的特判 
		if(q[i].lc) calc(q[i].lc); 
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
