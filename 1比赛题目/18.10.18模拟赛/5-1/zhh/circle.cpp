#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define No_found 1005
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,ans;
bool pd(ll l,ll r,ll qz){
	while(l<=r){
		ll md=l+r>>1;
		if(md*md==qz) return 1;
		if(md*md<qz){
			l=md+1;
		}
		else{
			r=md-1;
		}
	}
	return 0;
//	ll ge;
//	if(x==1||x==0) return 1;
//	for(int i=2;i<=x;i++){
//		ge=0;
//		while(x%i==0){
//			ge++;
//			x/=i;
//		}
//		if(ge&1) return 0;
//	}
//	return 1;
}
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	n=read();
	ll ha=n;
	ans=1;
	for(ll i=2;i<=n-1;i++){
		if(pd(1,(ha-i)*(ha+i),(ha-i)*(ha+i))){
			ans+=2;
			n=(ll)(sqrt((n-i)*(n+i)));
//			cout<<i<<"    "<<n<<endl;
		}
	}
	ans*=4;
	cout<<ans;
	return 0;
}
