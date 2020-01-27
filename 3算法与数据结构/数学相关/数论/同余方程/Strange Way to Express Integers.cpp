//http://119.29.55.79/problem/3258
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
using namespace std;
typedef long long ll;
int n;
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
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld %lld",&m[i],&a[i]);
		}
		ll ms=m[1],x0=a[1];
		
		for(int i=2;i<=n;i++){
			ll x,y,c=((a[i]-x0)%m[i]+m[i])%m[i];
			ll g=exgcd(ms,m[i],x,y);
			if(c%g!=0){
				x0=-1;
				break;				
			}
			ll mod=m[i]/g;
			x=((x*c/g)%mod+mod)%mod;
			x0=x0+x*ms;
			ms*=m[i]/g;
			x0=(x0%ms+ms)%ms;
		}
		printf("%lld\n",x0);
	}
	
} 
