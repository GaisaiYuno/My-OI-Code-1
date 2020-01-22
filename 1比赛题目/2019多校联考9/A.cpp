#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,k;
inline ll C2(ll x){
	return x*(x-1)/2;
}

ll check(ll p){
	ll x=C2(p);
	ll y=k-C2(p);
	if(y/p<=n-p) return C2(n-p)+x;
	else return -1;
}
int main(){
	scanf("%lld %lld",&n,&k);
	ll ans=-1;
	for(int i=1;C2(i)<=k;i++){
		ans=max(ans,check(i));
	}
	printf("%lld\n",ans);
}
