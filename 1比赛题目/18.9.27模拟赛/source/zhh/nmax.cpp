#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define zhh 1005
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
ll q,t,l,r;
vector<ll>v;
double ans;
vector<ll>sum;
int main(){
	freopen("nmax.in","r",stdin);
	freopen("nmax.out","w",stdout);
	q=read();
	while(q--){
		t=read();
		if(t==1){
			ll x=read();
			v.push_back(x);
			sum.push_back(x);
			if(sum.size()>1){
				sum[sum.size()-1]+=sum[sum.size()-2];
			}
		}
		else{
			if(v.size()==1){
				puts("0.0000000000");
				continue;
			}
			l=0,r=v.size()-2;
			ans=0;
			while(l<=r){
				ll md=(r-l)/3;
				ll m1=l+md,m2=l+2*md;
				double l1=v.back()-(double)((double)(sum[m1]+v.back())/(double)(m1+2));
				double l2=v.back()-(double)((double)(sum[m2]+v.back())/(double)(m2+2));
				if(l1>l2){
					ans=max(ans,l1);
					r=m2-1;
				}
				else{
					ans=max(ans,l2);
					l=m1+1;
				}
			}
			printf("%.10lf",ans);
			puts("");
		}
	}
	return 0;
}
