#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
#define maxn 1000 
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
int n,a,b,c,d;
ll fact[maxn+5],invfact[maxn+5];

void ini(){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod; 
} 

inline ll C(ll n,ll m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod; 
} 

ll cnt[maxn+5];
int main(){
	printf("%d\n",inv(3)); 
	scanf("%d",&n);
	scanf("%d %d %d %d",&a,&b,&c,&d);
	ini();
	int mx=min(min(a,b),min(c,d));
	ll ans=0;
	for(int i=0;i<=n/4&&i<=mx;i++){
		memset(cnt,0,sizeof(cnt));
		//可重排列((a+b+c+d)!)(a!b!c!d!)
		//类似中途相遇分两半求解 
		for(int j=0;j<=a-i;j++){
			for(int k=0;k<=b-i;k++){
				cnt[j+k]=(cnt[j+k]+invfact[j]*invfact[k]%mod)%mod;
			}
		}
		ll sum=0; 
		for(int j=0;j<=c-i;j++){
			for(int k=0;k<=d-i&&j+k<=n-4*i;k++){
				sum=(sum+cnt[n-4*i-(j+k)]*invfact[j]%mod*invfact[k]%mod)%mod;
			}
		}
		sum=sum*fact[n-4*i]%mod;
		
		
		//捆绑法，把4个一组的捆绑成1个,共n-3i个
		//再从中选出n-4i个单独1个的，其他展开
		//C(n-3i,n-4i) 
		ans+=fast_pow(-1,i)*C(n-3*i,n-4*i)*sum%mod;
		ans=(ans+mod)%mod; 
	} 
	printf("%lld\n",ans);
} 
