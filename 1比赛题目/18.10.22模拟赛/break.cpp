//For my love Selina
//������-�����ڵ���
//�ܷ�����n*m
//������m*(m-1)*...*(m-1)=m*(m-1)^(n-1) 
#include<iostream>
#include<cstdio>
#define mod 100003
using namespace std;
typedef long long ll;
ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1; 
	}
	return ans%mod;
}
ll m,n;
int main(){
//	freopen("break.in","r",stdin);
//	freopen("break.out","w",stdout);
	cin>>m>>n;
	ll ans=1;
	ans=fast_pow(m,n)-fast_pow(m-1,n-1)*m%mod;
	while(ans<=mod) ans=ans+mod;
	ans%=mod;
	cout<<ans;
}
