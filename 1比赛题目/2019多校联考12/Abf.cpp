#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,L; 
int main(){
	scanf("%lld %lld %lld",&n,&m,&L);
	ll ans=0;
	for(ll x=1;x<=n/L;x++){
		if(((m+L)*x+m-n)%(n+L)==0&&((m+L)*x+m-n)/(n+L)>0){
			ans++;
			printf("x=%lld\n",x);
		}
	} 
	printf("%lld\n",ans);
}

