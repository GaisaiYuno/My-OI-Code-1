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
int P;
ll L;
set<ll>S[maxl+5];

namespace brute_force_1{
	void solve(){
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
}

namespace brute_force_2{
	void solve(){ 
		int K=L%(P-1); 
		for(int i=0;i<=P-1;i++){
			for(int x=1;x<=P-1;x++){
				for(int y=1;y<=P-1;y++){
					S[i].insert((fast_pow(x,i,P)+fast_pow(y,i,P))%P);
				}
			}
		}
		ll sum1=0; 
		bool flag=false;
		for(int i=0;i<=P-1;i++){
			for(int z=1;z<=P-1;z++){
				if(S[i].count(fast_pow(z,i,P))){
					sum1++;
					if(i==0) flag=true;
					break;
				}
			}
		}
		ll sum2=0; 
		for(int i=0;i<=K;i++){
			for(int z=1;z<=P-1;z++){
				if(S[i].count(fast_pow(z,i,P))){
					sum2++;
	//				printf("%d ",i);
					break;
				}
			}
		}
		ll ans=L/(P-1)*sum1+sum2;
		if(flag) ans--;
		printf("%lld\n",ans);
	}
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d %lld",&P,&L);
//	L=L%(P-1);
	if(P<=100&&L<=100) brute_force_1::solve();
	else brute_force_2::solve(); 
} 
