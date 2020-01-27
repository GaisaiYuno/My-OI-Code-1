//http://119.29.55.79/problem/3262
#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;
typedef long long ll; 
int t;
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

ll a,b,d,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld %lld",&n,&d,&a,&b);
		ll x,y,c=(b-a+n)%n;
		ll g=exgcd(d,n,x,y);
		if(c%g!=0) printf("Impossible\n");
		else{
			ll mod=n/g;
			x=(x*(c/g)%mod+mod)%mod;
			printf("%lld\n",x);
		}
	}
}

