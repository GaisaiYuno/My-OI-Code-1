#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
#define maxlogn 25 
using namespace std;
int n;
struct segment_tree{
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
	void update(int &x,int upos,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].val++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,upos,l,mid);
		else update(tree[x].rs,upos,mid+1,r);
		push_up(x); 
	}
	int query(int x,int L,int R,int l,int r){
		if(L<=l&&R>=r){
			return tree[x].val;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(tree[x].ls,L,R,l,mid);
		if(R>mid) ans+=query(tree[x].rs,L,R,mid+1,r);
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
int root[maxn+5];
int in[maxn+5];

int tim=0;
int dfnl[maxn+5],dfnr[maxn+5];
vector<int>E1[maxn+5],E2[maxn+5];
void dfs1(int x,int fa){
	dfnl[x]=++tim;
	for(int i=0;i<E1[x].size();i++){
		int y=E1[x][i];
		if(y!=fa){
			dfs1(y,x);
		}
	} 
	dfnr[x]=tim;
} 

int cnt[maxn+5];
void dfs2(int x,int fa){
	for(int i=0;i<E2[x].size();i++){
		int y=E2[x][i];
		if(y!=fa){
			dfs2(y,x);
			root[x]=T.merge(root[x],root[y],1,n);
		}
	}
	cnt[x]=T.query(root[x],dfnl[x]+1,dfnr[x],1,n);
}

int main(){
	int u,v;
	int rt1,rt2;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E1[u].push_back(v);
		E1[v].push_back(u);
		in[v]++;
	}
	for(int i=1;i<=n;i++) if(in[i]==0) rt1=i;//根不一定是1 
	memset(in,0,sizeof(in));
	
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E2[u].push_back(v);
		E2[v].push_back(u);
		in[v]++;
	}
	for(int i=1;i<=n;i++) if(in[i]==0) rt2=i;
	
	dfs1(rt1,0);
	for(int i=1;i<=n;i++){
		T.update(root[i],dfnl[i],1,n);
	}
	dfs2(rt2,0);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=(long long)cnt[i]*(cnt[i]-1)/2;
	}
	printf("%lld\n",ans);
}

