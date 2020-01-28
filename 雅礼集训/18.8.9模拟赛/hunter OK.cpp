#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
#define maxn 100005
long long w[maxn];
using namespace std;
int n;
long long ansa,ansb;
inline long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);	
}
inline long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;	
}
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline long long inv(int x){
	return fast_pow(x,mod-2);
}

int main(){
	ansa=0;
	ansb=0;
	scanf("%d",&n);
	scanf("%lld",&w[1]);
	long long ans=0;
	for(int i=2;i<=n;i++){
		scanf("%lld",&w[i]);
		ans=ans+w[i]%mod*inv(w[i]+w[1])%mod;//第i个猎人在第1个猎人之前死的概率是w[i]/w[i]+w[1] 
	}
	printf("%d\n",(ans+1)%mod);
}
