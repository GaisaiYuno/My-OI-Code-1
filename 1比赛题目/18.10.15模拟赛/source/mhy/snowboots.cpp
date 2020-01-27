#include <iostream>
#include <cstdio>
#define MAXN 100005
using namespace std;
int A[MAXN],maxn[MAXN];
struct SegmentTree{
	struct node{
		int l,r;
		int val;
	}tree[MAXN<<2];
	void pushup(int i){
		tree[i].val=min(tree[i<<1].val,tree[i<<1|1].val);
	}
	void build(int l,int r,int i){
		tree[i].l=l,tree[i].r=r;
		if (l==r){
			tree[i].val=A[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,i<<1);
		build(mid+1,r,i<<1|1);
		pushup(i);
	}
	int query(int L,int R,int i){
		int l=tree[i].l,r=tree[i].r;
		if (L<=l&&r<=R){
			return tree[i].val;
		}
		int mid=(l+r)>>1,ans=0x7fffffff;
		if (L<=mid){
			ans=min(ans,query(L,R,i<<1));
		}
		if (mid<R){
			ans=min(ans,query(L,R,i<<1|1));
		}
		return ans;
	}
}Seg;
int main(){
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	int n,b;
	scanf("%d%d",&n,&b);
	for (register int i=1;i<=n;++i){
		scanf("%d",&A[i]);
	}
	Seg.build(1,n,1);
	for (register int i=1;i<n;++i){
		for (register int j=1;j<=n-i;++j){
			maxn[i]=max(maxn[i],Seg.query(j,j+i-1,1));
		}
	}
	while (b--){
		int s,d;
		scanf("%d%d",&s,&d);
		if (d==0){
			puts("0");
			continue;
		}
		else if (d>=n){
			puts("1");
			continue;
		}
		puts(maxn[d]<=s?"1":"0");
	}
}
