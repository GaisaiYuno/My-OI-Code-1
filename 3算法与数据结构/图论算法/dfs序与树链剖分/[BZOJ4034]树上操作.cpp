#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<2];
int size=0;
int head[maxn];
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

int cnt=0;
int l[maxn],r[maxn];
int deep[maxn];
long long dist[maxn];
void dfs(int x,int fa){
	 l[x]=++cnt;
	 for(int i=head[x];i;i=E[i].next){
	 	int y=E[i].to;
	 	if(y!=fa){
	 		dist[y]=dist[x]+a[y];
	 		deep[y]=deep[x]+1;
	 		dfs(y,x);
		}
	 }
	 r[x]=cnt;
} 
struct segment_tree{
	struct node{
		int l;
		int r;
		long long v;
		long long mark;
		long long len(){
			return r-l+1;
		}
	}tree[maxn<<2];
	void push_up(int pos){
		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].v=0;
		tree[pos].mark=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1); 
	}
	void push_down(int pos){
		if(tree[pos].mark){
			tree[pos<<1].mark+=tree[pos].mark;
			tree[pos<<1|1].mark+=tree[pos].mark;
			tree[pos<<1].v+=tree[pos].mark*tree[pos<<1].len();
			tree[pos<<1|1].v+=tree[pos].mark*tree[pos<<1|1].len();
			tree[pos].mark=0;
		}
	}
	void update(int L,int R,long long v,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].mark+=v;
			tree[pos].v+=(v*tree[pos].len());
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,v,pos<<1);
		if(R>mid) update(L,R,v,pos<<1|1);
		push_up(pos);
	}
	long long query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		long long ans=0;
		if(L<=mid) ans+=query(L,R,pos<<1);
		if(R>mid) ans+=query(L,R,pos<<1|1);
		return ans;
	}
};
segment_tree T1,T2;
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dist[1]=a[1];
	deep[1]=1;
	dfs(1,0);
	T1.build(1,n,1);
	T2.build(1,n,1);
//	for(int i=1;i<=n;i++){
//		printf("[%d,%d]\n",l[i],r[i]);
//	}
//	for(int i=1;i<=n;i++){
//		T1.update(l[i],l[i],a[i],1);
//		T2.update(l[i],l[i],(long long)a[i]*(deep[i]-1),1);	
//	}
	int cmd;
	for(int i=1;i<=n;i++){
		scanf("%d",&cmd); 
		if(cmd==1){
			scanf("%d %d",&u,&v);
			T2.update(l[u],r[u],v,1);
		}else if(cmd==2){ 
			scanf("%d %d",&u,&v);
			T1.update(l[u],r[u],(long long)v,1); 
			T2.update(l[u],r[u],(long long)v*(1-deep[u]),1);
		}else{
			scanf("%d",&u);
			long long t1=T1.query(l[u],l[u],1),t2=T2.query(l[u],l[u],1);
//			printf("%d %d %d %d\n",deep[u],t1,t2,dist[u]);
			printf("%lld\n",(long long)deep[u]*t1+t2+dist[u]);
		}
	} 
}
