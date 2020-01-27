//O(n^2logn)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 250
#define mod 1000000007
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
ll inv(ll x){
	return fast_pow(x,mod-2);
}
ll fact[maxn+5],invfact[maxn+5];
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod; 
}
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

int n,k;
int main(){
	scanf("%d %d",&n,&k);
	ini(n);
	ll ans=0;
	for(int i=0;i<=n;i++){//共i行不符合条件 
		for(int j=0;j<=n;j++){//共j列不符合条件 
			ll cnt=i*n+j*n-i*j;//不符合条件行和列的格子，这些格子的值>1 
			ans+=fast_pow(-1,i+j)*C(n,i)%mod*C(n,j)%mod*fast_pow(k-1,cnt)%mod*fast_pow(k,n*n-cnt)%mod;
			ans=(ans+mod)%mod;
		}
	}
	printf("%I64d\n",ans);
}

