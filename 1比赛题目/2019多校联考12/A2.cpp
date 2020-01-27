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
ll n,m,L; 
int main(){
	scanf("%lld %lld %lld",&n,&m,&L);
	ll a=m+L,b=n+L,c=n-m;
	ll x,y;
	ll g=exgcd(a,b,x,y);
	if(c%g!=0) printf("0\n");
	else{
		ll mod=b/g;
		x=(x*(c/g)%mod+mod)%mod;
		if(x==0) x+=mod;
		ll maxt=(n/L-x)/mod;
		printf("%lld\n",maxt+1);
	}
}

