#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 300000
using namespace std;
int n;
long long p,k;
long long a[maxn+5];
long long fast_pow(long long x,long long k,long long mod){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
map<long long,long long>cnt; 
int main(){
	scanf("%d %I64d %I64d",&n,&p,&k);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		long long v=fast_pow(a[i],4,p)-k*a[i]%p;
		if(v<0) v+=p; 
		cnt[v]++;
	}
	long long ans=0; 
	for(auto x : cnt){
		ans+=(x.second)*(x.second-1)/2;
	}
	printf("%I64d\n",ans);
}
