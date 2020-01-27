//http://119.29.55.79/problem/3261
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15
using namespace std;
typedef long long ll;
int n;
ll c[maxn+5],p[maxn+5],l[maxn+5];
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

bool check(int m){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll x,y;
			ll a=(p[i]-p[j]+m)%m,b=m,cc=(c[j]-c[i]+m)%m;//ax+by=c，小心负数 
			ll g=exgcd(a,b,x,y);
			ll mod=b/g;
			if(cc%g==0){
				x=(x*(cc/g)%mod+mod)%mod;
				if(x<=min(l[i],l[j])) return 0;
				//只要有一个方程有解，且最小整数解<=min(l[i],l[j]),就不行 
			}
		}
	}
	return 1; 
}

int main(){
	scanf("%d",&n);
	ll lb=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&c[i],&p[i],&l[i]);
		lb=max(lb,c[i]); 
	}
	for(int i=lb;i<=1000000;i++){//注意枚举下界 
		if(check(i)){
			printf("%d\n",i);
			break;
		}
	}
}
