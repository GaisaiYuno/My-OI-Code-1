#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200000
#define mod 998244353
using namespace std;
typedef long long ll;
int n;
int d[maxn+5];
ll fact[maxn+5];
int main(){
//	freopen("1.in","r",stdin); 
	int u,v;
	scanf("%d",&n);
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod; 
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		d[u]++;
		d[v]++;
	}
	ll ans=n;
	for(int i=1;i<=n;i++){
		ans=ans*fact[d[i]]%mod;
	}
	printf("%lld\n",ans);
}
