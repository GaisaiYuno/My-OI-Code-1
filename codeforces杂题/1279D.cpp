#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define mod 998244353
#define maxn 1000000
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x){
	return fast_pow(x,mod-2);
}
 
int n;
vector<int>a[maxn+5];
int cnt[maxn+5];
int main(){
	int k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		a[i].resize(k);
		for(int j=0;j<k;j++){
			scanf("%d",&a[i][j]);
			cnt[a[i][j]]++;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll now=0;
		for(int j=0;j<a[i].size();j++){
			now+=inv(n)*inv(a[i].size())%mod*cnt[a[i][j]]%mod*inv(n)%mod;
		}
		ans+=now;
		ans%=mod;
	}
	printf("%I64d\n",ans);
 
}
