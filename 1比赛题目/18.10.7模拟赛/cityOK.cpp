#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
#define INF 0x7fffffffffff
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	} 
	return x*sign;
}

char out[40];
inline void qprint(long long x){
	if(x==0){
		putchar('0');
	}else{
		int ptr=0;
		while(x>0){
			out[++ptr]=x%10+'0';
			x/=10;
		}
		for(int i=ptr;i>=1;i--){
			putchar(out[i]);
		}
	}
	putchar('\n');
}

int n,q;
int a[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int siz=0;
int head[maxn];
void add_edge(int u,int v){
	siz++;
	E[siz].from=u;
	E[siz].to=v;
	E[siz].next=head[u];
	head[u]=siz;
}

int deep[maxn]; 
int top[maxn];
int fa[maxn];
int son[maxn]; 
int sz[maxn];
int dfn[maxn];
int hash_dfn[maxn];
int cnt=0;
void dfs(int x,int fath){
	fa[x]=fath;
	sz[x]=1;
	deep[x]=deep[fath]+1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to; 
		if(y!=fath){
			dfs(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}

void dfs2(int x,int tp){
	dfn[x]=++cnt;
	hash_dfn[cnt]=x;
	top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}	
}
struct val{
	long long maxv;
	long long minv;
	long long upv;
	long long downv;
	val(){
		maxv=0;
		minv=INF;
		upv=0;
		downv=0;
	}
	val(long long ma,long long mi,long long up,long long down){
		maxv=ma;
		minv=mi;
		upv=up;
		downv=down;
	}
};
struct node{
	int l;
	int r;
	long long mark;
	long long maxv;
	long long minv;
	long long upv;//区间向下走时的最大差值 
	long long downv;//区间向上走时的最大差值 
	int len(){
		return r-l+1;
	}
}tree[maxn<<2]; 
void push_up(int pos){
	tree[pos].maxv=max(tree[pos<<1].maxv,tree[pos<<1|1].maxv); 
	tree[pos].minv=min(tree[pos<<1].minv,tree[pos<<1|1].minv);
	tree[pos].upv=max(tree[pos<<1].upv,tree[pos<<1|1].upv); 
	tree[pos].upv=max(tree[pos].upv,tree[pos<<1].maxv-tree[pos<<1|1].minv); 
	//因为一条重链的dfs序连续，前面dfn小的肯定在上方
	tree[pos].downv=max(tree[pos<<1].downv,tree[pos<<1|1].downv);
	tree[pos].downv=max(tree[pos].downv,tree[pos<<1|1].maxv-tree[pos<<1].minv); 
} 

void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[pos].maxv=tree[pos].minv=a[hash_dfn[l]];
		tree[pos].upv=tree[pos].downv=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}

void push_down(int pos){
	if(tree[pos].mark){
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1].minv+=tree[pos].mark;
		tree[pos<<1].maxv+=tree[pos].mark;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos<<1|1].minv+=tree[pos].mark;
		tree[pos<<1|1].maxv+=tree[pos].mark;
		tree[pos].mark=0;
	}
}

void update(int L,int R,long long v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].maxv+=v;
		tree[pos].minv+=v;
		tree[pos].mark+=v;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,mid,v,pos<<1);
	if(R>mid) update(L,mid,v,pos<<1|1);
	push_up(pos); 
}

val query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return val(tree[pos].maxv,tree[pos].minv,tree[pos].upv,tree[pos].downv);
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(R<=mid){
		return query(L,R,pos<<1);
	}else if(L>mid){
		return query(L,R,pos<<1|1);
	}else{
		val ans;
		val lson,rson;
		lson=query(L,R,pos<<1|1);
		rson=query(L,R,pos<<1|1);
		ans.maxv=max(lson.maxv,rson.maxv);
		ans.minv=min(lson.minv,rson.minv);
		ans.upv=max(max(lson.upv,rson.upv),lson.maxv-rson.minv);
		ans.downv=max(max(lson.downv,rson.downv),rson.maxv-lson.minv);
		return ans;
	} 
}
void change(int x,int y,long long v){
	int tx=top[x];
	int ty=top[y];
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(tx,ty);
			swap(x,y);
		}
		update(dfn[tx],dfn[x],v,1);
		x=fa[tx];
		tx=top[x];
	} 
	if(deep[x]>deep[y]) swap(x,y);
	update(dfn[x],dfn[y],v,1);
}

long long xl[maxn],xr[maxn],yl[maxn],yr[maxn];
//存储x向上，y向上重链上的最大值，最小值 
long long solve(int x,int y){
	int tx=top[x];
	int ty=top[y];
	int p1=0,p2=0;
	long long ans=0;
	val t;
	while(tx!=ty){
		if(deep[tx]>deep[ty]){
			t=query(dfn[tx],dfn[x],1);
			ans=max(ans,t.upv);//该条重链上能取到的最大差值 
			xl[++p1]=t.maxv;
			xr[p1]=t.minv;
			x=fa[tx];
			tx=top[x];
		}else{
			t=query(dfn[ty],dfn[y],1);
			ans=max(ans,t.downv);
			yl[++p2]=t.minv;
			yr[p2]=t.maxv;
			y=fa[ty];
			ty=top[y];
		} 
	} 
	if(deep[x]>deep[y]){
		swap(x,y);
		t=query(dfn[x],dfn[y],1);
		ans=max(ans,t.upv);
		xl[++p1]=t.maxv;
		xr[p1]=t.minv;
	}else{
		t=query(dfn[x],dfn[y],1);
		ans=max(ans,t.downv);
		yl[++p2]=t.minv;
		yr[p2]=t.maxv; 
	}
	for(int i=p2;i>=1;i--){//将x->lca(x,y),y->lca(x,y)两段信息合并 
		xl[++p1]=yl[i];
		xr[p1]=yr[i];
	}
	long long minv=INF;
	long long maxv=0;//分类讨论 
	for(int i=1;i<=p1;i++){ //当前链最大-之前最小 
		ans=max(ans,xr[i]-minv);
		minv=min(minv,xl[i]);
	}
	for(int i=1;i<=p1;i++){ //之前最大-当前链最小 
		ans=max(ans,maxv-xl[i]);
		maxv=max(maxv,xr[i]);
	}
	return ans;
} 
int main(){
	n=qread();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int u,v,w;
	for(int i=1;i<=n-1;i++){
		v=qread();
		u=qread();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	dfs2(1,1); 
	build(1,n,1); 
	q=qread();
	for(int i=1;i<=q;i++){
		u=qread();
		v=qread();
		w=qread();
		qprint(solve(u,v));
		change(u,v,w);
	}
}
