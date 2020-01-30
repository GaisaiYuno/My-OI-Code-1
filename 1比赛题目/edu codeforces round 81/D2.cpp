#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
using namespace std;
typedef long long ll;

ll a,m;
inline ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll phi(ll x){
	ll ans=x;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			ans=ans/i*(i-1); 
			while(x%i==0) x=x/i;
		}
	}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d %I64d",&a,&m);
		ll g=gcd(a,m);
		printf("%I64d\n",phi(m/g));
	}
}

