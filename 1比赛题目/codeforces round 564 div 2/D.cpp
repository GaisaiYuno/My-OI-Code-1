#include<iostream>
#include<cstdio>
#define maxn 200005
#define mod 998244353
using namespace std;
int n;
long long fact[maxn];
int deg[maxn];

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		deg[u]++;
		deg[v]++; 
	}
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=fact[deg[i]];
		ans%=mod;
	}
	ans*=n;
	ans%=mod;
	printf("%I64d\n",ans);
}

