#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
const ll maxn=500010,inf=9999999999999;
ll x[maxn],s[maxn],f[maxn];
ll n,d,k;
bool pd(ll m){   //(1)d-m~d+m
	ll temp=-1;
	for(ll i=1;i<=n;++i)f[i]=-inf;
	f[0]=0;
	for(ll i=0;i<=n;++i){
		for(ll j=i+1;j<=n;++j){
			if(x[j]>=d+x[i]-m&&x[j]<=d+x[i]+m){
				f[j]=max(f[j],f[i]+s[j]);
				temp=max(temp,f[j]);
			}
			if(x[j]>d+x[i]+m)break;
		}
	}
	if(temp>=k)return 1;
	else return 0;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;  //n格子数   d固定距离   k至少分数 
	ll l=0,r=0;
	for(ll i=1;i<=n;++i){ //x[i]距离   s[i]分数 
		cin>>x[i]>>s[i];
		r=max(r,x[i]);
	}
	ll ans=inf;
	while(l<r){
		ll mid=(l+r)/2;
		if(pd(mid)){
			ans=min(ans,mid);
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(ans!=inf)cout<<ans;
	else cout<<-1;
	return 0;
}
