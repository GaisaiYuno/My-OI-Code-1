#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 2000000
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
inline ll inv(ll x){
	return fast_pow(x,mod-2);
}

int cnt;
bool vis[maxn+5];
int prime[maxn+5];
ll phi[maxn+5];
ll sumf[maxn+5]; 
void sieve(int n){
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for(int i=1;i<=n;i++) sumf[i]=(sumf[i-1]+i*phi[i]%mod)%mod;//f(n)=phi(n^2)=n*phi(n)
}

map<ll,ll>ans;
ll inv6;
ll inv2;//¿¨³£ 
ll dujiao_sieve(ll n){//orz dujiao 
	if(n<=maxn) return sumf[n];
	if(ans.count(n)) return ans[n];
	ll res=n*(n+1)%mod*(2*n+1)%mod*inv6;
	ll tmp;
	for(ll l=2,r;l<=n;l=r+1){
		r=n/(n/l);
		tmp=(l+r)*(r-l+1)%mod*inv2%mod*dujiao_sieve(n/l)%mod; 
		res=(res-tmp+mod)%mod;
	}
	ans[n]=res;
	return res;
} 

ll n;
int main(){
	sieve(maxn);
	inv6=inv(6);
	inv2=inv(2); 
	scanf("%lld",&n);
	printf("1\n%lld\n",dujiao_sieve(n));
}

