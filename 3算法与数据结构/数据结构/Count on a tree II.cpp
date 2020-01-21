//https://www.luogu.org/problem/SP10707
///update 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxlogn 20
#define maxn 40000
#define maxm 100000 
using namespace std;
int n,m;
int dn; 
int a[maxn+5];
int tmp[maxn+5];
void discrete(){
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	dn=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+dn,a[i])-tmp;
}

struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn*2+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
} 

int log2n;
int tim;
int st[maxn+5],ed[maxn+5];
int hash_num[maxn*2+5];
int deep[maxn+5];
int anc[maxn+5][maxlogn+5]; 
void dfs(int x,int fa){
	st[x]=++tim;
	hash_num[tim]=x;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	} 
	ed[x]=++tim;
	hash_num[tim]=x;
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
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
	int lc;
	int id;
	friend bool operator < (que x,que y){
		if(belong[x.l]==belong[y.l]) return x.r<y.r;
		else return belong[x.l]<belong[y.l];
	}
}q[maxm+5]; 
int vis[maxn+5];//某个点是否被处理过，处理了2次的点会被去掉，相当于dfs时进去一次出来一次 
int cnt[maxn+5];//每个值出现的次数 , 
int ans[maxm+5];
int sum=0;
void add(int v){
	cnt[v]++;
	if(cnt[v]==1) sum++;
}
void del(int v){
	cnt[v]--;
	if(cnt[v]==0) sum--;
}
void calc(int x){
	if(vis[x]){
		del(a[x]);
		vis[x]=0;
	}else{
		add(a[x]);
		vis[x]=1;
	} 
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	log2n=log2(n)+1; 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	discrete();
	dfs(1,0);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		if(st[u]>st[v]) swap(u,v);
		int lc=lca(u,v); 
		if(lc==u){
			q[i].l=st[u];
			q[i].r=st[v];
			q[i].lc=-1;
		}else{
			q[i].l=ed[u];
			q[i].r=st[v];
			q[i].lc=lc;
		}
		q[i].id=i;
	}
	bsz=sqrt(n);
	for(int i=1;i<=n*2;i++) belong[i]=i/bsz+1;
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l>q[i].l){
			l--;
			calc(hash_num[l]);
		}
		while(r<q[i].r){
			r++;
			calc(hash_num[r]);
		}
		while(l<q[i].l){
			calc(hash_num[l]);
			l++;
		}
		while(r>q[i].r){
			calc(hash_num[r]);
			r--;
		}
		if(q[i].lc!=-1) calc(q[i].lc);
		ans[q[i].id]=sum;
		if(q[i].lc!=-1) calc(q[i].lc);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]); 
}

