#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 1000005
using namespace std;
typedef long long ll;
ll n,base;
ll p[maxn],k[maxn]; 
int cnt=0;
void divide(ll x){
	ll sq=sqrt(x);
	ll ans=0;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			p[++cnt]=i;
			while(x%i==0){
				x/=i;
				k[cnt]++;
			}
		}
	}
	if(x>1){
		p[++cnt]=x;
		k[cnt]=1;
	}
} 
ll f(ll x,ll y){
	if(x<y) return 0;
	else return x/y+f(x/y,y);
}
ll count(ll n,ll x){
	divide(x);
	ll ans=0x7fffffffffffffff;
	for(int i=1;i<=cnt;i++){
		ans=min(ans,f(n,p[i])/k[i]);
	}
	return ans;
}
int main(){
	cin>>n>>base;
	cout<<count(n,base);
}

