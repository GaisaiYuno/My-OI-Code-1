#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-9
using namespace std;
typedef long long ll;
typedef long double db ;
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
db my_round(db x){
	db a=floor(x),b=ceil(x);
	if(a>x) return a;
	else return b; 
}
int main(){
	scanf("%lld %lld %lld",&n,&m,&L);
	ll a=m+L,b=n+L,c=n-m;
	ll x,y;
	ll g=exgcd(a,b,x,y);
	if(c%g!=0) printf("0\n");
	else{
		ll mod=b/g;
		x=x*(c/g);
		db l1=(db)(-x+1)/mod,l2=((db)((2*n+L-m)/(m+L)-x))/mod;
		ll lb=ceil(max(l1,l2)); 
		ll rb=floor((db)(n/L-x)/mod);
		if(rb<lb) printf("0\n");
		else printf("%lld\n",rb-lb+1);
	}
}

