/*
Problem:D
Source:Codeforces Good Bye 2018 https://codeforces.com/contest/1091/
Algorithm:
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
#define maxn 1000005
using namespace std;
int n;
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
	return fast_pow(x,mod-2)%mod;
}
long long fact[maxn];
long long invfact[maxn];
int main(){
	scanf("%d",&n);
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i%mod;
		invfact[i]=inv(fact[i]);
	}
	long long ans=0;
	ans+=n*fact[n]%mod;
	for(int i=1;i<=n-1;i++){
		ans=(ans-fact[n]*invfact[i]%mod+mod)%mod;
	} 
	printf("%I64d\n",ans); 
}

