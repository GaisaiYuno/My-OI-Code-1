#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
using namespace std;
int n,k;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
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
int l[maxn],r[maxn],hash[maxn],mark[maxn];
long long a[maxn];
long long sum[maxn];
int fa[maxn];
void dfs(int x,int pa){
	sum[x]=sum[pa]+a[x];
	l[x]=++cnt;
	hash[cnt]=x;
	fa[x]=pa;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=pa){
			dfs(y,x);
		} 
	}	
	r[x]=cnt;
}

struct node{
	int l;
	int r;
	long long v;
	long long mark;
	int point;
}tree[maxn<<2];
void push_up(int pos){
	if(tree[pos<<1].v>tree[pos<<1|1].v){
		tree[pos].v=tree[pos<<1].v;
		tree[pos].point=tree[pos<<1].point;
	}else{
		tree[pos].v=tree[pos<<1|1].v;
		tree[pos].point=tree[pos<<1|1].point;
	}
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	tree[pos].mark=0;
	if(l==r){
		tree[pos].v=sum[hash[l]];
		tree[pos].point=hash[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void push_down(int pos){
	if(tree[pos].mark){
		tree[pos<<1].v+=tree[pos].mark;
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1|1].v+=tree[pos].mark;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos].mark=0;
	}
}
void update(int L,int R,int v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].v+=v;
		tree[pos].mark+=v;
		return; 
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}
void change(int x){
	while(x){
		if(mark[x]) break;
		mark[x]=1;
		update(l[x],r[x],-a[x],1);
		x=fa[x];
	}
}
int main(){
//	freopen("input.txt","r",stdin);
	int u,v;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	build(1,n,1);
	long long ans=0;
	for(int i=1;i<=k;i++){
		ans=ans+tree[1].v;
		change(tree[1].point);
	}
	printf("%lld",ans);
	return 0;
}
