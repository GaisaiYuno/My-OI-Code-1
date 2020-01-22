#include<iostream>
#include<cstdio>
#define mod 1000000007 
using namespace std;
long long n,m,k;
long long fact(int n){
	long long ans=1;
	for(int i=2;i<=n;i++) ans=ans*i%mod;
	return ans;
}
long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
long long inv(long long x){
	return fast_pow(x,mod-2);
}
long long C(int n,int m){
	return fact(n)*inv(fact(n-m))%mod*inv(fact(m))%mod;
}
int main(){
	scanf("%lld %lld %lld",&n,&m,&k);
	printf("%lld\n",C(n-k,m-1));
}

