#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 200000
#define mod 998244353
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
ll p[maxn+5];
ll dp[maxn+5];
//dp[i]=(dp[i-1]+1)*p[i]+ (dp[i-1]+1+dp[i])*(1-p[i])
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
		p[i]=p[i]*inv(100)%mod; 
	}
	for(int i=1;i<=n;i++){
		dp[i]=(dp[i-1]+1)*inv(p[i])%mod;
	}
	printf("%lld\n",dp[n]);
}

