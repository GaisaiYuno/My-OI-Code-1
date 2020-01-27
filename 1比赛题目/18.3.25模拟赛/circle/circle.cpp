#include<iostream>
#include<cstdio>
using namespace std;
inline long long fastpow(long long x,long long n,long long mod){
	if(n==0) return 1;
	long long ans=x;
	n-=1;
	while(n>0){
		if(n%2==1){
			ans=(ans%mod*x)%mod;
		}
		n/=2;
		x=(x%mod*x)%mod;
	}
	return ans%mod;
}
long long n,m,k,x;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	cout<<(fastpow(10,k,n)*m%n+x)%n;
	return 0;
} 
