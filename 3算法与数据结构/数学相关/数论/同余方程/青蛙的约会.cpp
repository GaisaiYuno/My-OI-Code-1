//http://119.29.55.79/problem/3260
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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

ll a,b,m,n,L;
int main(){
	ll x,y;
	scanf("%lld %lld %lld %lld %lld",&a,&b,&m,&n,&L);
	ll p=m-n,q=L,c=b-a;
	if(p<0){
		p=-p;
		c=-c;
	}
	ll g=exgcd(p,q,x,y);
	if(c%g!=0) printf("Impossible\n");
	else{
		ll mod=q/g;
		//Í¨½â:x+i*(q/g) i \in Z 
		printf("%lld\n",(x*(c/g)%mod+mod)%mod);
	}
	
}
