#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,k,x;
inline long long fast_pow(long long x,long long k,long long mod){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	} 
	return ans;
} 
int main(){
	cin>>n>>m>>k>>x;
	long long ans=(x+m*fast_pow(10,k,n)%n)%n;
	cout<<ans; 
}
