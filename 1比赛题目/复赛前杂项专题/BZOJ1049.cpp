#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 100000
typedef long long ll;
using namespace std;
int n;
int a[maxn+5];
ll b[maxn+5];
int f[maxn+5];
int stk[maxn+5];
int bin_search(int l,int r,int v) {
	int ans=0;
	int mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if(stk[mid]<=v) {
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	return ans+1;
}
int work_dp1() {
	int top=0;
	memset(stk,0x80,sizeof(stk));
	for(int i=1; i<=n; i++) {
		int pos=bin_search(1,top,b[i]);
		f[i]=pos;
		stk[pos]=b[i];
		top=max(top,pos);
	}
	return n-top;
}

ll g[maxn+5];
vector<int>v[maxn+5];
ll sum1[maxn+5],sum2[maxn+5];
ll work_dp2() {
//直接记录turnf不行，因为可能满足dp[i]=dp[j]+1的j有多个
	for(int i=0; i<=n; i++) {
		v[f[i]].push_back(i);//记录dp值一定的节点
	}
	memset(g,0x3f,sizeof(g));
	g[0]=0;
	b[0]=-INF;//玄学
	for(int i=1; i<=n; i++) {
		for(int u=0; u<(int)v[f[i]-1].size(); u++) {
			int j=v[f[i]-1][u];//满足dp[i]=dp[j]+1的j
			if(j>i) break;//j>i,则j不可能转移到i
			if(a[j]>a[i]) continue;
			for(int k=j; k<=i; k++) {
				sum1[k]=abs(b[j]-b[k]);
				sum2[k]=abs(b[i]-b[k]);
			}
			for(int k=j+1;k<=i;k++){
				sum1[k]+=sum1[k-1];
				sum2[k]+=sum2[k-1];
			}
			for(int k=j; k<i; k++) {
				g[i]=min(g[i],g[j]+sum1[k]-sum1[j]+sum2[i]-sum2[k]);
				//以k为分界，前面改成a[j]，后面改成a[i]
			}
		}
	}
	return g[n];
}


int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	a[++n]=INF;
	for(int i=1; i<=n; i++) b[i]=a[i]-i;
	printf("%d\n",work_dp1());
	printf("%lld\n",work_dp2());
}

