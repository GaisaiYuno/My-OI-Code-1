#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define zhh 200005
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
//bool pd(ll x){
//	
//}
//void ba(ll l,ll r){
//	while(l<=r){
//		ll md=(l+r)/2;
//		if(pd(md)){
//			ans=md;
//			l=md+1;
//		}
//		else r=md-1;
//	}
//}
ll n,ans;
ll a[zhh];
bool fl=0;
bool cmp(ll l1,ll l2){
	return l1>l2;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=read();
	fu(i,1,n){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	fu(i,1,n){
		fu(j,i+1,n){
			if((a[i]%a[j])>ans){
				ans=a[i]%a[j];
			}
			else{
				if(ans>=a[i]){
					fl=1;
					break;
				}
			}
		}
		if(fl) break;
	}
	cout<<ans;
	return 0;
}
