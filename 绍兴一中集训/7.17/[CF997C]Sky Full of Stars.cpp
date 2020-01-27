#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
#define mod 998244353
using namespace std;
typedef long long ll;
int n;
ll fact[maxn+5],invfact[maxn+5];
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
inline ll C(int n,int m){
    if(n<m) return 0;//小心特殊情况 
    if(n==m) return 1;
    if(m==0) return 1;
    return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

void pre_work(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
    for(int i=0;i<=n;i++) invfact[i]=inv(fact[i]);
}


int main(){
	scanf("%d",&n);
	pre_work(n);
	ll ans=0;
	ans=fast_pow(3,(ll)n*n);
	ans=(ans-fast_pow(fast_pow(3,n)-3,n)+mod%mod);
	for(int i=1;i<=n;i++){
		ll now=fast_pow(-1,i)*C(n,i)%mod*(3*fast_pow(fast_pow(3,n-i)-1,n)%mod+(fast_pow(3,i)-3+mod)*fast_pow(3,(ll)n*(n-i))%mod)%mod;
		ans=(ans-now+mod)%mod;
	}
	printf("%I64d\n",ans);
}
