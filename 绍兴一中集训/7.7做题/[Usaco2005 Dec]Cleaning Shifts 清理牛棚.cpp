//https://www.luogu.org/recordnew/show/20335265 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,l0,r0;
struct tim{
	int t1;
	int t2;
	int v;
	friend bool operator < (tim p,tim q){
		return p.t2<q.t2;
	}
}a[maxn+5];
//dp[x]表示覆盖[l0,x]的最小代价 
//dp[r[i]]=min(dp[j])+c[i],l[i]-1<=j<=r[i]
struct segment_tree{
	struct node{
		int l;
		int r;
		long long v;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=min(tree[pos<<1].v,tree[pos<<1|1].v); 
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].v=INF;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void update(int tpos,long long v,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v=v;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) update(tpos,v,pos<<1);
		else update(tpos,v,pos<<1|1);
		push_up(pos);
	}
	long long query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		long long ans=INF;
		if(L<=mid) ans=min(query(L,R,pos<<1),ans);
		if(R>mid) ans=min(query(L,R,pos<<1|1),ans);
		return ans;
	} 
}T;

long long dp[maxn+5];
int main(){
	scanf("%d %d %d",&n,&l0,&r0);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i].t1,&a[i].t2,&a[i].v);
		a[i].t1=max(a[i].t1,l0);
		a[i].t2=min(a[i].t2,r0);
	}
	T.build(l0,r0,1);
	sort(a+1,a+1+n);
	memset(dp,0x3f,sizeof(dp));
	dp[l0]=0;
	T.update(l0,0,1);
	for(int i=1;i<=n;i++){
		dp[a[i].t2]=min(dp[a[i].t2],T.query(a[i].t1-1,a[i].t2,1)+a[i].v);//记得取min，一个点可能被多个区间更新 
		T.update(a[i].t2,dp[a[i].t2],1);
	} 
	if(dp[r0]>=INF) printf("-1\n");
	else printf("%lld\n",dp[r0]);
} 
