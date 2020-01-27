//https://vjudge.net/contest/311947#problem/A
/*
枚举选几人，再枚举队长
ans=sum(C(n,i)*i*2^(i-1)) (1<=i<=k)
发现模数有些特殊，8388608=2^23
那么上面的式子当i>23时都是0

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 8388608
#define maxn 100000
#define maxk 23
using namespace std;
int t,n,k;
typedef long long ll;
ll fast_pow(ll x,ll k){
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

ll C[maxn+5][maxk+5];
void ini(int n,int k){
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=min(k,i);j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
ll calc(int n,int k){
	ll ans=0;
	for(int i=1;i<=min(k,maxk);i++){
		ans+=C[n][i]*i%mod*fast_pow(2,i-1)%mod;
		ans%=mod;
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	ini(maxn,maxk);
	for(int i=1;i<=t;i++){
		scanf("%d %d",&n,&k);
		printf("%lld\n",calc(n,k));
	}
}
