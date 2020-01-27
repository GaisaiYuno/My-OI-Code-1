#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
#define maxv 15000005
using namespace std;
typedef long long ll;
inline int gcd(int a,int b) {
	return b==0?a:gcd(b,a%b);
}
int n;
int a[maxn];
int vis[maxv];
int minprime[maxv];
int cnt[maxv];
int prime[maxv];
int k=0;

void sieve(int n) {
	for(int i=2; i<=n; i++) {
		if(!vis[i]) {
			minprime[i]=i;
			prime[++k]=i;
		}
		for(ll j=1; j<=k&&(ll)i*prime[j]<=n; j++) {
			minprime[(ll)i*prime[j]]=prime[j];
			vis[(ll)i*prime[j]]=1;
			if(!(i%prime[j])) break;
		}
	}
}

void div(int x) {
	if(!vis[x]||x==1) {
		cnt[x]++;
		return;
	}
	while(x>1) {
		int t=minprime[x];
		cnt[t]++;
		while(x%t==0&&x!=1) {
			x/=t;
		}
	}
}
int main() {
	scanf("%d",&n);
	sieve(15000000);
	int g=0;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		g=gcd(g,a[i]);
	}
	for(int i=1; i<=n; i++) {
		a[i]/=g;
	}
	for(int i=1; i<=n; i++) {
		div(a[i]);
	}
	int ans=0;
	for(int i=2; i<=15000000; i++) {
		if(cnt[i]!=n)ans=max(ans,cnt[i]);
	}
	if(ans==0) printf("-1\n");
	else printf("%d\n",n-ans);
}
