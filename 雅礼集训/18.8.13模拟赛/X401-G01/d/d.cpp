#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid (l+r)/2
#define maxn 100005
using namespace std;
int cases,n,m;
struct rect {
	int a;
	int b;
} r[maxn];
int cmp(rect x,rect y) {
	return x.a<y.a;
}
int tm, cnt = 0;
int ta[maxn], tb[maxn], T[maxn];
int sum[maxn<<5], L[maxn<<5], R[maxn<<5];

inline int build(int l, int r) {
	int rt = ++ cnt;
	sum[rt] = 0;
	if (l < r) {
		L[rt] = build(l, mid);
		R[rt] = build(mid+1, r);
	}
	return rt;
}

inline int update(int pre, int l, int r, int x) {
	int rt = ++ cnt;
	L[rt] = L[pre];
	R[rt] = R[pre];
	sum[rt] = sum[pre]+1;
	if (l < r) {
		if (x <= mid) L[rt] = update(L[pre], l, mid, x);
		else R[rt] = update(R[pre], mid+1, r, x);
	}
	return rt;
}

inline int query(int u, int v, int l, int r, int k) {
	if (l >= r) return l;
	int x = sum[L[v]] - sum[L[u]];
	if (x >= k) return query(L[u], L[v], l, mid, k);
	else return query(R[u], R[v], mid+1, r, k-x);
}

int main() {
//	freopen("d5.in","r",stdin);
////	freopen("d2.out","w",stdout);
////	freopen("d.in","r",stdin);
////	freopen("d.out","w",stdout);
	scanf("%d",&cases);
	for(int cas=1; cas<=cases; cas++) {
		cnt=0;
		scanf("%d %d",&n,&m);
		for(int i=1; i<=n; i++) {
			scanf("%d %d",&r[i].a,&r[i].b);
		}
		sort(r+1,r+1+n,cmp);
		if(n==m){
			printf("0\n");
			continue;
		}
		for (int i = 1; i <= n; i ++) {
			ta[i]=r[i].b;
			tb[i]=ta[i];
		}
		sort(tb+1, tb+1+n);
		tm = unique(tb+1, tb+1+n)-tb-1;
		T[0] = build(1, tm);
		for (int i = 1; i <= n; i ++) {
			int t = lower_bound(tb+1, tb+1+tm, ta[i])-tb;
			T[i] = update(T[i-1], 1, tm, t);
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(i<=m+1){
				int t=query(T[i-1],T[n],1,tm,m-i+2);
				int minv=tb[t];
				ans=max(ans,(long long)minv*r[i].a);
//				printf("debug %d %d %d\n",i,m-i+2,minv);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
