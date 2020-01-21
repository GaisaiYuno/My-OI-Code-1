#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 100000
#define mod 10007
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

ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

ll n;
char s[maxn+5];
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++) n=(n*10+s[i]-'0')%mod;
	ini(maxn+2);
	printf("%lld\n",C(n+2,3)%mod);
}

