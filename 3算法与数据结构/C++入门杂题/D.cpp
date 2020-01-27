//https://blog.csdn.net/qq_31759205/article/details/77487920
#include<iostram>
#include<cstdio>
using namespace std;
long long fast_pow(long long x,long long k,long long mod){//快速幂 
	long long ans=1;
	while(k>0){
		if(k&1) ans=ans*x;
		x=x*x;
		k/=2;
	} 
	return ans;
}
long long inv(int x,int mod){//逆元 
	return fast_pow(x,mod-2,mod);
} 
long long fact(int k,int mod){//阶乘 
	int ans=1;
	for(int i=1;i<=k;i++){
		ans=ans*i%mod;
	} 
	return ans;
}
long long C(int n,int m){//组合数 
	if(m==0||m==n) return 1;
	return fact(n,mod)*inv(fact(m,mod))%mod*inv(fact(n-m,mod))%mod;
	//C(n,m)=n!/(m!*(n-m)!)
}
int is_persq(int x){ //完全平方数判断 
	long long l=1,r=1000000000;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(mid*mid==x) return 1;
		else if(mid*mid<x) l=mid+1;
		else r=mid-1;
	} 
	return 0;
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("")
} 
