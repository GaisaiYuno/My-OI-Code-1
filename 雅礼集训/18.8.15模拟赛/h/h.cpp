#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define maxm 100005
#define mod 998244353
using namespace std;
int n,m,k;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline long long inv(long long x){
//	printf("%d %d %d\n",x,mod-2,fast_pow(x,mod-2));
	return fast_pow(x,mod-2)%mod;
}
long long fact[maxn+maxm];
long long invfact[maxn+maxm];
inline long long C(int n,int m){
	if(n<m) return 0;
	if(n==m||m==0) return 1;
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}
int vis[maxn];
int prime[maxn];
int cnt_prime=0;
void sieve(int n){
	vis[0]=1;
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt_prime]=i;
			for(long long j=i*i;j<=n;j+=i){
				vis[j]=1;
			}
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	fact[0]=1;
	for(int i=1;i<=n+m;i++){
		fact[i]=fact[i-1]*i%mod;
		invfact[i]=inv(fact[i]);
	}
	sieve(k);
	long long ans;
	int p;
	for(int i=0;i<=m;i++){
		ans=0;
//		for(int j=cnt_prime;j>=1;j--){
//			p=prime[j];
//			if(p<k-i) break;
//			ans+=C(n,p)*C(i,k-p)%mod;
//			ans%=mod;
//		}
		for(int j=1;j<=cnt_prime;j++){
			int p=prime[j];
			if(p<k-i) continue;
			ans+=C(n,p)*C(i,k-p)%mod;
			ans%=mod;
		}
		ans=ans*inv(C(n+i,k))%mod;
		printf("%lld\n",ans%mod);
	}
}

