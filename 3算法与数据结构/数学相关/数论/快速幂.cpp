#include<iostream>
#include<cstdio>
using namespace std;
int fast_pow(int x,int k,int mod){
	int ans=x;
	k-=1;
	while(k>0){
		if(k%2==1){
			ans=(ans*x)%mod;
		}
		x=(x*x)%mod;
		k/=2;
	}
	return ans%mod;
}
int x,k,mod;
int main(){
	while(cin>>x>>k>>mod){
		cout<<fast_pow(x,k,mod)<<endl;
	}
}
