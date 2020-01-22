#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 2000000
#define mod 1000000007
using namespace std;
typedef long long ll;
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
ll inv(ll x){
	return fast_pow(x,mod-2);
}
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<=n;i++) invfact[i]=inv(fact[i]); 
} 
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

int cnt;
int prime[maxn+5];
bool vis[maxn+5];
void sieve(int n){
	vis[1]=0;
	for(int i=2;i<=n;i++){
		if(!vis[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}

int m,n;
int main(){
	ini(maxn);
 	scanf("%d %d",&m,&n);
 	sieve(m);
 	ll ans=1;
 	for(int i=1;i<=cnt;i++){
 		int k=log(m)/log(prime[i]);
 		printf("%d ",C(n+k-1,k));
 		ans*=C(n+k-1,k);
 		ans%=mod;
	 }
	 printf("%lld\n",ans);
}

