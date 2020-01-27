//http://119.29.55.79/problem/3263 
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x2,y2;
	ll g=exgcd(b,a%b,x2,y2);
	x=y2;
	y=x2-a/b*y2;
	return g;
}

ll a,b,c,k;
int main(){
	while(scanf("%lld %lld %lld %lld",&a,&b,&c,&k)!=EOF){
		if(a==0&&b==0&&c==0&&k==0) break;
		k=(1ll<<k);
		ll x,y,tot=(b-a+k)%k;
		ll g=exgcd(c,k,x,y);
		if(tot%g!=0) printf("FOREVER\n");
		else{
			ll mod=k/g;
			x=(x*(tot/g)%mod+mod)%mod;
			printf("%lld\n",x);
		}
	}
}

