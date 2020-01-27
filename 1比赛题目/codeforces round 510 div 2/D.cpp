#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;
int n;
long long t;
long long input[maxn];
long long a[maxn];
long long T[maxn],L[maxn<<5],R[maxn<<5],sum[maxn<<5],Hash[maxn];
int all=0;
int build(int l,int r) {
	int rt=(++all);
	sum[rt]=0;
	if(l==r) return rt;
	int m=(l+r)>>1;
	L[rt]=build(l,m);
	R[rt]=build(m+1,r);
	return rt;
}
int update(int pre,int x,int l,int r) {
	int rt=(++all);
	L[rt]=L[pre],R[rt]=R[pre],sum[rt]=sum[pre]+1;
	if(l==r) return rt;
	int m=(l+r)>>1;
	if(x<=m) L[rt]=update(L[pre],x,l,m);
	else R[rt]=update(R[pre],x,m+1,r);
	return rt;
}
int query(int u,int v,int k,int l,int r) {
	if(1<=l&&r<=k)
		return sum[v]-sum[u];
	int m=(l+r)>>1;
	int res=0;
	res+=query(L[u],L[v],k,l,m);
	if(k>m)
		res+=query(R[u],R[v],k,m+1,r);
	return res;
}


int main() {
	scanf("%d %I64d",&n,&t);
	for(int i=1; i<=n; i++) {
		scanf("%I64d",&input[i]);
	}
	for(int i=1; i<=n; i++) {
		a[i]=a[i-1]+input[i];
//		printf("%d ",a[i]);
	}
//	printf("\n");
	for(int i=1;i<=n;i++) Hash[i]=a[i]; 
	sort(Hash+1,Hash+n+1);
	int tol=unique(Hash+1,Hash+n+1)-Hash-1;
	T[0]=build(1,tol);
	for(int i=1; i<=n; i++) {
		int x=lower_bound(Hash+1,Hash+tol+1,a[i])-Hash;
		T[i]=update(T[i-1],x,1,tol);
	}
	long long ans=0;
//	int q;
//	scanf("%d",&q);
	int x,g,l,r;
	long long k;
	for(int i=1;i<=n;i++){
		l=i,r=n;
		k=a[i-1]+t-1;
//		l++,r++;
		int g=lower_bound(Hash+1,Hash+tol+1,k)-Hash;
		if(Hash[g]>k)g--;
		if(g>0) x=query(T[l-1],T[r],g,1,tol);
		else x=0;
//		printf("%d\n",x);
		ans+=x;
	}
	printf("%I64d\n",ans);
}
