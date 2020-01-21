//https://www.luogu.org/problem/P1516 
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
	ll g=exgcd(b,a%b,x,y);
	ll tmp=y;
	y=x-a/b*y;
	x=tmp;
	return g;
}

ll n,m,x,y,l;
int main(){
	scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l);
	ll a=n-m;
	ll b=l;
	ll c=x-y;
	ll t,u;
	if(a<0){
		a=-a;//gcd只对非负整数有意义，所以要取反a,c,而求解t的时候-b和b是等价的，不用取反b 
		c=-c;
	}
	ll g=exgcd(a,b,t,u);
	if(c%g!=0) printf("Impossible\n");
	else{
		ll p=b/g;
		t=t*c/g;
		t=(t%p+p)%p;
		printf("%lld\n",t); 
	}
}

