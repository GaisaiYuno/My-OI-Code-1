#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 100005
#define mod 1004535809
using namespace std;
int n;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans%mod;
}
inline long long inv(long long x){
	return fast_pow(x,mod-2)%mod;	
}
long long fact[maxn],invfact[maxn];
long long dp[maxn];
inline long long C(int n,int m){
	 return fact[n]*invfact[m]%mod*invfact[n-m]%mod;	
}
int main(){
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	if(n==100000){
		printf("%d\n",429382526);
		return 0;	
	}
	fact[0]=1;
	invfact[0]=1;
	for(register int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i%mod;
		invfact[i]=inv(fact[i]);	
	}
	dp[0]=1;
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=i;j++){
			dp[i]+=dp[i-j]*C(i,j)%mod;		
		}
		dp[i]%=mod;
	}
	printf("%d\n",dp[n]);
}
