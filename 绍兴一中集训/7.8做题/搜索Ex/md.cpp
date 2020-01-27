#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#define maxn 100
#define maxv 0x7fffffffffffffff
using namespace std;
typedef long long ll;
inline ll random(ll n){
	return (ll)rand()*rand()*rand()%n+1;
}
inline ll random(ll l,ll r){
	return (ll)rand()*rand()*rand()%(r-l+1)+l;
}

ll p[maxn+5],k[maxn+5];
int divide(ll x){
	memset(p,0,sizeof(p));
	memset(k,0,sizeof(k));
	ll sq=sqrt(x);
	int cnt=0;
	for(ll i=2;i<=sq;i++){
		if(x%i==0){
			cnt++;
			p[cnt]=i;
			while(x%i==0){
				x/=i;
				k[cnt]++;
			}
		}
	}
	if(x>0){
		p[++cnt]=x;
		k[cnt]=1;
	}
	return cnt;
}
int main(){
	srand(time(NULL));
	freopen("1.in","w",stdout);
	int t=500;
	printf("%d\n",t);
	for(int i=1;i<=t;i++){
		ll n=random(maxv);
//		printf("%d\n",n);
		int cnt=divide(n);
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++){
			printf("%lld %lld\n",p[i],k[i]);
		}
		printf("\n");
	}
}
