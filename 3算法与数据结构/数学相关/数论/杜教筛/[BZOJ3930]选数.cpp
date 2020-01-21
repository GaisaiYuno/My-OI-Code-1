#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 2000000
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,k;
ll A,B;

int cnt;
bool vis[maxn+5];
int prime[maxn+5];
int mu[maxn+5];
ll s_mu[maxn+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			mu[i]=-1;
		} 
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}else mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=n;i++) s_mu[i]=(s_mu[i-1]+mu[i])%mod;
}

map<ll,ll>sum_mu;
ll dujiao_sieve(ll x){
	if(x<=maxn) return s_mu[x];
	if(sum_mu.count(x)) return sum_mu[x];
	ll ans=1;
	for(ll l=2,r;l<=x;l=r+1){
		r=x/(x/l);
		ans-=(r-l+1)*dujiao_sieve(x/l)%mod;
		ans=(ans+mod)%mod;
	}
	sum_mu[x]=ans;
	return ans;
} 

inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

int main(){
	sieve(maxn);
	scanf("%d %d %lld %lld",&n,&k,&A,&B);
	A=(A-1)/k;
	B/=k;
	ll ans=0;
	for(ll l=1,r;l<=B;l=r+1){
		if(A/l) r=min(A/(A/l),B/(B/l));
		else r=B/(B/l);
//		printf("%d %d\n",l,r);
		ans+=fast_pow(B/l-A/l,n)*(dujiao_sieve(r)-dujiao_sieve(l-1)+mod)%mod;
		ans%=mod;
	}
	printf("%lld\n",ans);
}

