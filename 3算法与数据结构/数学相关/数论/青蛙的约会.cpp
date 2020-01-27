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
		a=-a;//gcdֻ�ԷǸ����������壬����Ҫȡ��a,c,�����t��ʱ��-b��b�ǵȼ۵ģ�����ȡ��b 
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

