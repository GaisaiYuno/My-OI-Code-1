#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
#define maxlogn 25
using namespace std;
typedef long long ll;
int n;
vector<int>T1[maxn+5],T2[maxn+5];
int tim;
int dfnl[maxn+5],dfnr[maxn+5];
void dfs1(int x,int fa){
	dfnl[x]=++tim;
	for(int i=0;i<(int)T1[x].size();i++){
		int y=T1[x][i];
		if(y!=fa){
			dfs1(y,x);
		}
	}
	dfnr[x]=tim;
}

struct persist_segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxn*maxlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].val=tree[lson(x)].val+tree[rson(x)].val;
	}
	void update(int &x,int val,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].val++;
			return;
		}
		int mid=(l+r)>>1;
		if(val<=mid) update(lson(x),val,l,mid);
		else update(rson(x),val,mid+1,r);
		push_up(x);
	}
	int query(int x,int L,int R,int l,int r){
		if(L<=l&&R>=r){
			return tree[x].val;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(lson(x),L,R,l,mid);
		if(R>mid) ans+=query(rson(x),L,R,mid+1,r);
		return ans;
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y) return x+y;
		if(l==r){ 
			tree[x].val+=tree[y].val;
			return x;
		}
		int mid=(l+r)>>1;
		tree[x].ls=merge(tree[x].ls,tree[y].ls,l,mid);
		tree[x].rs=merge(tree[x].rs,tree[y].rs,mid+1,r);
		push_up(x);
		return x;
	}
}T;
ll ans=0;
int root[maxn+5];
void dfs2(int x,int fa){
	for(int i=0;i<(int)T2[x].size();i++){
		int y=T2[x][i];
		if(y!=fa){
			dfs2(y,x);
			root[x]=T.merge(root[x],root[y],1,n);
		}
	}
	ans+=T.query(root[x],dfnl[x],dfnr[x],1,n);
	T.update(root[x],dfnl[x],1,n);
}

int main(){
//	freopen("3.in","r",stdin);
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		T1[u].push_back(v);
		T1[v].push_back(u);
	}	
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		T2[u].push_back(v);
		T2[v].push_back(u);
	}	
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld\n",ans);
}
