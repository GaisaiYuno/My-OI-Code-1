#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 100000
#define maxv 100000ll
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
int n;
ll k;
ll a[maxn+5];
ll vis[maxn+5];
ll calc(ll x){
	ll tot=fast_pow(x,k);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(tot%a[i]==0&&tot/a[i]<=maxv) ans+=vis[tot/a[i]];
		vis[a[i]]++;
	}
	for(int i=1;i<=n;i++) vis[a[i]]=0;
	return ans;
} 
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll ans=0;
	for(ll x=1;fast_pow(x,k)<=maxv*maxv;x++){
		ans+=calc(x);
	}
	printf("%lld\n",ans);
}

