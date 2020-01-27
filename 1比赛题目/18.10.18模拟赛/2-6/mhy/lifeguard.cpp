#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 2000005
using namespace std;
int val[MAXN],cnt;
int s[MAXN],t[MAXN],c[MAXN];
int ans,n,k,value[MAXN];
struct SegmentTree{
	struct node{
		int l,r;
		int val,tag;
		inline int len(){
			return r-l+1;
		}
	}tree[MAXN<<2];
	inline void pushup(int i){
		tree[i].val=tree[i<<1].val+tree[i<<1|1].val; 
	}
	inline void pushdown(int i){
		if (tree[i].tag){
			tree[i<<1].tag+=tree[i].tag;
			tree[i<<1|1].tag+=tree[i].tag;
			tree[i<<1].val+=tree[i].tag*tree[i<<1].len();
			tree[i<<1|1].val+=tree[i].tag*tree[i<<1|1].len();
			tree[i].tag=0;
		}
	}
	void build(int l,int r,int i){
		tree[i].l=l,tree[i].r=r;
		tree[i].val=tree[i].tag=0;
		if (l==r){
			return ;
		}
		int mid=(l+r)>>1;
		build(l,mid,i<<1);
		build(mid+1,r,i<<1|1);
	}
	void update(int L,int R,int i,int val){
		int l=tree[i].l,r=tree[i].r;
		if (L<=l&&r<=R){
			tree[i].val+=val;
			tree[i].tag+=val;
			return ;
		}
		pushdown(i);
		int mid=(l+r)>>1;
		if (L<=mid){
			update(L,R,i<<1,val);
		}
		if (mid<R){
			update(L,R,i<<1|1,val);
		}
		pushup(i);
	}
	void query(int i){
		pushdown(i);
		if (tree[i].l==tree[i].r){
			value[tree[i].l]=tree[i].val;
			return ;
		}
		query(i<<1);query(i<<1|1);
	}
}Seg;
inline int Ask(){
	Seg.query(1);
	int len=0;
	for (int i=1;i<=cnt;++i){
		if (value[i]){
			int j=i;
			while (value[++j]&&j<=cnt);
			--j;
			len+=val[j]-val[i];
			i=j+1;
		}
	}
	return len;
}
inline void dfs(int i,int used){
	if (i==n+1||used>n-k){
		return ;
	}
	ans=max(ans,Ask());
	Seg.update(lower_bound(val+1,val+1+cnt,s[i+1])-val,lower_bound(val+1,val+1+cnt,t[i+1])-val,1,1);
//	printf("Update : %d %d 1\n",s[i+1],t[i+1]);
//	printf("Is £º %d %d\n",lower_bound(val+1,val+1+cnt,s[i+1])-val,lower_bound(val+1,val+1+cnt,t[i+1])-val);
	dfs(i+1,used+1);
	Seg.update(lower_bound(val+1,val+1+cnt,s[i+1])-val,lower_bound(val+1,val+1+cnt,t[i+1])-val,1,-1);
	dfs(i+1,used);
	//printf("Update : %d %d -1\n",lower_bound(val+1,val+1+cnt,s[i+1])-val,lower_bound(val+1,val+1+cnt,t[i+1])-val);
}
int main(){
	freopen("lifeguard.in","r",stdin);
	freopen("lifeguard.out","w",stdout);
	scanf("%d%d",&n,&k);
	if (n==k){
		printf("%d\n",0);
		return 0;
	}
	int maxlen=0;
	for (int i=1;i<=n;++i){
		scanf("%d%d",&s[i],&t[i]);
		val[++cnt]=s[i];
		val[++cnt]=t[i];
		maxlen=max(maxlen,t[i]-s[i]);
	}
	if (k==n-1){printf("%d\n",maxlen);return 0;}
	sort(val+1,val+1+cnt);
	Seg.build(1,cnt,1);
	dfs(0,0);
	printf("%d\n",ans);
}

