#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
using namespace std;
typedef long long ll;

ll a,m;
inline ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll solve(ll x,ll n){
	vector<ll>p;
	p.clear();
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			p.push_back(i);
			while(x%i==0) x=x/i;
		}
	}
	if(x>1) p.push_back(x);
	ll sum=0;
	for(ll i=1;i<(1<<p.size());i++){
		int cnt1=0;
		ll fac=1; 
		for(ll j=0;j<p.size();j++){
			if(i&(1<<j)){
				cnt1++;
				fac*=p[j];
			} 
		}
		if(cnt1%2==1) sum+=n/fac;
		else sum-=n/fac;
	}
	return n-sum;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d %I64d",&a,&m);
		ll g=gcd(a,m);
//		for(ll x=a/g;x<=(a+m-1)/g;x++) if(gcd(x,m/g)==1) ans++;
//		printf("%I64d %I64d %I64d\n",a/g,(a+m-1)/g,ans);
		printf("%I64d\n",solve(m/g,(a+m-1)/g)-solve(m/g,a/g-1));
	}
}

