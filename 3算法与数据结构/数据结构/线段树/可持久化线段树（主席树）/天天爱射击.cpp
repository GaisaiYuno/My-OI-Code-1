//http://119.29.55.79/problem/354
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<vector>
#define maxn 300000
#define maxlogn 25
using namespace std;
int n,m;
int maxx;
struct board{
	int l;
	int r;
	int lim;
}a[maxn+5]; 
int b[maxn+5];
vector<int>id[maxn+5];

struct persist_segment_tree{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
#ifdef DEBUG
		int l;
		int r;
#endif 
		int ls;
		int rs;
		int cnt;
	}tree[maxn*maxlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].cnt=tree[lson(x)].cnt+tree[rson(x)].cnt;
	}
	void update(int &x,int last,int upos,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
#ifdef DEBUG
		tree[x].l=l;
		tree[x].r=r;
#endif 
		if(l==r){
			tree[x].cnt++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
		else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
		push_up(x); 
	}
	int query(int xl,int xr,int k,int l,int r){
		if(l==r) return l;
		int mid=(l+r)>>1;
		int cnt=tree[lson(xr)].cnt-tree[lson(xl)].cnt;
		if(k<=cnt) return query(tree[xl].ls,tree[xr].ls,k,l,mid);
		else return query(tree[xl].rs,tree[xr].rs,k-cnt,mid+1,r);
	}
}T;
int root[maxn+5];

int ans[maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i].l,&a[i].r,&a[i].lim);
		maxx=max(maxx,a[i].r);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		maxx=max(maxx,b[i]);
		id[b[i]].push_back(i);
	}
	for(int i=1;i<=maxx;i++){ 
		root[i]=root[i-1];
		for(int j=0;j<id[i].size();j++){
			T.update(root[i],root[i],id[i][j],1,m);
		}
	}
	for(int i=1;i<=n;i++){
		int l=a[i].l,r=a[i].r,k=a[i].lim;
		if(T.tree[root[r]].cnt-T.tree[root[l-1]].cnt<k) continue;
		else{
			int x=T.query(root[l-1],root[r],k,1,m);
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
}

