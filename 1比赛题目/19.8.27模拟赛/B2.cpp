#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#define maxl 5000
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k,ll mod){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
} 
int P,K;
ll L;
set<ll>S[maxl+5];
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d %lld",&P,&L);
	for(int i=1;i<=L;i++){
		for(int x=1;x<=P-1;x++){
			for(int y=1;y<=P-1;y++){
				S[i].insert((fast_pow(x,i,P)+fast_pow(y,i,P))%P);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=L;i++){
		for(int z=1;z<=P-1;z++){
			if(S[i].count(fast_pow(z,i,P))){
				ans++;
				break;
			}
		}
	}

	printf("%d\n",ans);
} 
