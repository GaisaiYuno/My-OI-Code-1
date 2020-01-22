#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 1000000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n,t;
ll m;
ll a[maxn+5];
ll b[maxn+5];
bool check(ll mid) {
	for(int i=1; i<=n; i++) b[i]=0;
	ll cnt=0;
	for(int i=1; i<=n; i++) {
		if(i==n&&b[i]>=mid) break;
		cnt++;
		b[i]+=a[i];
		if(b[i]>=mid) continue;
		//向前浇水一次再回来 
		ll delta=ceil(1.0*(mid-b[i])/a[i]);
		cnt+=2*delta;
		b[i+1]+=delta*a[i+1];
		b[i]+=delta*a[i];
	}
	return cnt<=m;
}
int main() {
	scanf("%d",&t);
	while(t--) {
		ll mina=INF;
		scanf("%d %lld",&n,&m);
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
			mina=min(mina,a[i]);
		}
		ll l=0,r=mina*m;
		ll mid;
		ll ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else r=mid-1; 
		}
		printf("%lld\n",ans);
	}
}

