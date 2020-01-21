//http://119.29.55.79/problem/3257
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
ll a[maxn+5],m[maxn+5];
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0) {
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

ll calc(ll a,ll b,ll c){
	ll x,y;
	ll g=exgcd(a,b,x,y);
	if(c%g!=0) return -1;
	ll mod=b/g;
	x=(x*(c/g)%mod+mod)%mod;
	return x;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld %lld",&m[i],&a[i]);
	}
	ll ms=m[1],x0=a[1];
	for(int i=2;i<=n;i++){
		ll x=calc(ms,m[i],((a[i]-x0)%m[i]+m[i])%m[i]);
		if(x==-1) break;
		x0+=x*ms;
		ms*=m[i]/gcd(ms,m[i]);
		x0=(x0%ms+ms)%ms;
	} 
	printf("%lld\n",x0);
}
