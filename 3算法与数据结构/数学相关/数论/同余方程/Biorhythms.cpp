#include<iostream>
#include<cstdio>
#define maxn 3
#define year 21252
using namespace std;
typedef long long ll;
ll d;
ll a[maxn+5],m[maxn+5];
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

int main(){
	for(int cas=1;;cas++){
		scanf("%lld %lld %lld",&a[1],&a[2],&a[3]);
		scanf("%lld",&d);
		if(d==-1) break;
		m[1]=23,m[2]=28,m[3]=33;
		ll ms=m[1],x0=a[1];
		for(int i=2;i<=3;i++){
			ll x,y,c=((a[i]-x0)%m[i]+m[i])%m[i];
			ll g=exgcd(ms,m[i],x,y);
			if(c%g!=0) break;
			ll mod=m[i]/g;
			x=(x*(c/g)%mod+mod)%mod;
			x0+=x*ms;
			ms*=m[i]/g;
			x0=(x0+ms)%ms;
		}
		ll ans=(x0%year-d+year)%year;
		if(ans==0) ans=year;
		printf("Case %d: the next triple peak occurs in %lld days.\n",cas,ans);
	}
	
} 


