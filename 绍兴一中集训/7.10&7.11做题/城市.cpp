//BZOJ 5457 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 400000
#define maxlogn 20
using namespace std;
int n,m;
struct segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{//权值线段树,以a[i]为下标，存储编号落在[l,r]内的数个数最大值,和最大值对应的编号 
		int ls;
		int rs;
		int cnt;
		int id;
	}tree[maxn*maxlogn+5];//注意空间复杂度为O(nlogn) 
	int root[maxn+5];
	int ptr;
	void push_up(int x){
		if(tree[lson(x)].cnt>tree[rson(x)].cnt){
			tree[x].cnt=tree[lson(x)].cnt;
			tree[x].id=tree[lson(x)].id;
		}else if(tree[lson(x)].cnt==tree[rson(x)].cnt){
			tree[x].cnt=tree[lson(x)].cnt;
			tree[x].id=min(tree[lson(x)].id,tree[rson(x)].id);
		}else{
			tree[x].cnt=tree[rson(x)].cnt;
			tree[x].id=tree[rson(x)].id;
		}
	}
	void insert(int &x,int l,int r,int ucnt,int uid){
		if(x==0) x=++ptr;
		if(l==r){
			tree[x].id=uid;
			tree[x].cnt=ucnt;
			return;
		}
		int mid=(l+r)>>1;
		if(uid<=mid) insert(tree[x].ls,l,mid,ucnt,uid);
		else insert(tree[x].rs,mid+1,r,ucnt,uid);
		push_up(x);
	}
	
	int merge(int x,int y,int l,int r){
		if(!x||!y) return x+y;
		if(l==r){//对应区间相同，编号相同，可以相加 
			tree[x].cnt+=tree[y].cnt;
			return x;
		}
		int mid=(l+r)>>1;
		tree[x].ls=merge(tree[x].ls,tree[y].ls,l,mid);
		tree[x].rs=merge(tree[x].rs,tree[y].rs,mid+1,r);
		push_up(x);
		return x;
	}
#undef lson
#undef rson
}T;

struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

pair<int,int> ans[maxn+5];
void dfs(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			T.merge(T.root[x],T.root[y],1,m);
		}
	}
	ans[x]=make_pair(T.tree[T.root[x]].id,T.tree[T.root[x]].cnt);
} 

int main(){
	int u,v;
	int a,b;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a,&b);
		T.insert(T.root[i],1,m,b,a);
	} 
	dfs(1,0);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}


