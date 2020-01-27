#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 300005
#define MAXM 25
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		ch=getchar();
	}
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int A[MAXN];
int S_max[MAXN][MAXM];
int S_min[MAXN][MAXM];
void ST_init(int n){
	for (register int i=1;i<=n;++i){
		S_max[i][0]=S_min[i][0]=A[i];
	}
	for (register int i=1;i<MAXM;++i){
		for (register int j=1;j<=n-(1<<i)+1;++j){
			S_max[j][i]=max(S_max[j+(1<<(i-1))][i-1],S_max[j][i-1]);
			S_min[j][i]=min(S_min[j+(1<<(i-1))][i-1],S_min[j][i-1]);
		}
	}
}
inline int query_max(int L,int R){
	int k=0;
	while ((1<<k)<=(R-L+1)) k++;
	k--;
	return max(S_max[L][k],S_max[R-(1<<k)+1][k]);
}
inline int query_min(int L,int R){
	int k=0;
	while ((1<<k)<=(R-L+1)) k++;
	k--;
	return min(S_min[L][k],S_min[R-(1<<k)+1][k]);
}
//struct SegmentTree{
//	struct node{
//		int l,r;
//		int maxval,minval;
//	}tree[MAXN<<2];
//	inline void push_up(int i){
//		tree[i].maxval=max(tree[i<<1].maxval,tree[i<<1|1].maxval);
//		tree[i].minval=min(tree[i<<1].minval,tree[i<<1|1].minval);
//	}
//	void build(int l,int r,int i){
//		tree[i].l=l;
//		tree[i].r=r;
//		if (l==r){
//			tree[i].maxval=tree[i].minval=A[l];
//			return ;
//		}
//		int mid=(l+r)>>1;
//		build(l,mid,i<<1);
//		build(mid+1,r,i<<1|1);
//		push_up(i);
//	}
//	int query_max(int L,int R,int i){
//		int l=tree[i].l,r=tree[i].r;
//		if (L<=l&&r<=R){
//			return tree[i].maxval;
//		}
//		int mid=(l+r)>>1;
//		int ans=-0x7fffffff;
//		if (L<=mid){
//			ans=max(ans,query_max(L,R,i<<1));
//		}
//		if (mid<R){
//			ans=max(ans,query_max(L,R,i<<1|1));
//		}
//		return ans;
//	}
//	int query_min(int L,int R,int i){
//		int l=tree[i].l,r=tree[i].r;
//		if (L<=l&&r<=R){
//			return tree[i].minval;
//		}
//		int mid=(l+r)>>1;
//		int ans=0x7fffffff;
//		if (L<=mid){
//			ans=min(ans,query_min(L,R,i<<1));
//		}
//		if (mid<R){
//			ans=min(ans,query_min(L,R,i<<1|1));
//		}
//		return ans;
//	}
//}Seg;
int n,k;
inline bool check(int mid){
	for (register int i=1;i<=n-mid+1;++i){
//		printf("Querying %d %d\n",i,i+mid-1);
//		printf("Result: %d %d\n",maxn,mino);
		if (query_max(i,i+mid-1)-query_min(i,i+mid-1)<=k){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	n=read(),k=read();
	for (register int i=1;i<=n;++i) A[i]=read();
	ST_init(n);
	int l=0,r=n+1,ans=0;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else {
			r=mid-1;
		}
	}
	printf("%d\n",ans);
}
