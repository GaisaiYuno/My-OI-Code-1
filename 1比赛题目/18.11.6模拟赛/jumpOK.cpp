//O(n^2logn)¿¨¹ý 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int qread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,d;
int k;
int x[maxn];
int a[maxn];
long long dp[maxn];


int check(int g) {
	int l0,r0;
	memset(dp,-0x3f,sizeof(dp));
	long long ans=dp[0];
	if(g<d) {
		l0=d-g;
		r0=d+g;
	} else {
		l0=1;
		r0=d+g;
	}
	dp[0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=i-1; j>=0; j--) {
			if(x[i]-x[j]<l0) continue;
			if(x[i]-x[j]>r0) break;
			if(dp[j]+a[i]>dp[i]) dp[i]=dp[j]+a[i];
			if(dp[i]>=k) return 1;

		}
		if(dp[i]>ans) ans=dp[i];
	}
	if(ans>=k) return 1;
	else return 0;
}

int main() {
	n=qread();
	d=qread();
	k=qread();
	for(int i=1; i<=n; i++) {
		x[i]=qread();
		a[i]=qread();
	}
	dp[0]=0;
	x[0]=0;
	int l=0,r=1005;
	int mid;
	int ans=-1;
	int t;
	while(l<=r) {
		mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	printf("%d\n",ans);
}
//Dedicated to Selina
