#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring> 
#define maxn 1000000
#define mod 1000000007
using namespace std;
typedef long long ll;
ll x,n;
int cnt;
ll p[maxn+5];
ll a[maxn+5];
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

void divide(ll x){
	ll sq=sqrt(x);
	for(ll i=2;i<=sq;i++){
		if(x%i==0){
			p[++cnt]=i;
			while(x%i==0){
				x/=i;
				a[cnt]++;
//				if(x==0) break; 
			}
		}
	}
	if(x>1){
		p[++cnt]=x;
		a[cnt]=1;
	}
}


int main(){
	scanf("%I64d %I64d",&x,&n);
	divide(x);
	ll ans=1;
	for(int i=1;i<=cnt;i++){
		ll tmp=n;
		while(tmp){
			ans=ans*fast_pow(p[i],tmp/p[i])%mod;
			tmp/=p[i];
		}
	}
	printf("%I64d\n",ans);
}

