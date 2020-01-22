#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 100005
using namespace std;
typedef long long ll;
ll num[maxn];
ll n,a0,a1,b0,b1;
ll gcd(ll a,ll b) {
   return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int dissove(ll x,ll *a){//因数分解 
	int cnt=0;
	ll sq=sqrt(x); 
	for(ll i=1;i<=sq;i++){
	    if(x%i==0){
	    	a[++cnt]=i;
	    	if(i!=x/i) a[++cnt]=x/i;
		} 
	} 
	return cnt;
}
int main() {
//	freopen("son10.in","r",stdin);
//	freopen("son.out","w",stdout);
    scanf("%d",&n);
    while(n--) {
        scanf("%lld %lld %lld %lld",&a0,&a1,&b0,&b1);
        int size=dissove(b1,num);
        ll ans=0;
        for(int i=1;i<=size;i++){
        	if(gcd(num[i],a0)==a1&&lcm(num[i],b0)==b1) ans++;
		}
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
41 1 96 288
95 1 37 1776
*/
