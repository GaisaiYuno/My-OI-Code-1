#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#define maxn 1000005
using namespace std;
int n,k;
int a[maxn]; 
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
int cnt=0;
int lb[maxn],rb[maxn];
void dfs(int x,int fa){
	lb[x]=++cnt;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
	rb[x]=cnt;
}

struct node{
	int l;
	int r;
	int v;
	int mark;
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
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
int query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans=max(ans,query(L,R,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
	return ans;
}

int nex[maxn];
void init(){
	stack<int>s;
	for(int i=n;i>=1;i--){
		while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
		if(!s.empty()){
			int p=s.top();
			add_edge(p,i);
			add_edge(i,p);
		}else{
			add_edge(n+1,i);
			add_edge(i,n+1);
		}
		s.push(i);
	}
	dfs(n+1,0);
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init();
	build(1,n+1,1);
	for(int i=1;i<=k;i++){
		update(lb[i],rb[i],1,1);
	}
	for(int i=1;i+k-1<=n;i++){
		int r=i+k-1;
		printf("%d ",query(1,n+1,1));
		update(lb[i],rb[i],-1,1);
		update(lb[r+1],rb[r+1],1,1);
	}
}

