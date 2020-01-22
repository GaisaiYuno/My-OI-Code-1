#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
#define int long long
using namespace std;
typedef long long ll;
int m;
ll N,I,K;
ll a[maxn+5];
ll lim[maxn+5];
bool check(ll mid) {
	ll in=N+I*(mid/2);//morning
	if(mid%2==1) in=N+I*(mid/2+1);
	ll out=0;
	ll dec_day=mid/2;
	for(int i=1; i<=m; i++) {
		if(dec_day*K<a[i]) out+=a[i]-dec_day*K;
		else out+=(a[i]%K==0?K:a[i]%K);
	}
	if(in>=out) return 1;
	else return 0;

}

#undef int
int main() {
#define int long long
	scanf("%lld %lld %lld %lld",&N,&I,&m,&K);
	for(int i=1; i<=m; i++) {
		scanf("%lld",&a[i]);
//		if(a[i]%K==0) lim[i]=a[i]/K-1;
//		else lim[i]=a[i]/K;
	}
	ll l=0,r=2e12+1,mid,ans=0;
	while(l<=r) {
		mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	if(ans%2==0) printf("%lld morning",ans/2+1);
	else printf("%lld evening",ans/2+1);
}


