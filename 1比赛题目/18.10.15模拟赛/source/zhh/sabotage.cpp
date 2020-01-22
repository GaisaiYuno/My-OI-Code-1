#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define zhh 100005
#define eps 1e-4
#define inf 0x7ffffffffff
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
ll n;
ll a[zhh],sum[zhh];
double sj,ans;
double h1[zhh],h2[zhh],p[zhh];
bool pd(double x){
    fu(i,1,n){
		p[i]=sum[i]-x*i;
	}
    fu(i,1,n-2){
		h1[i]=min(h1[i-1],p[i]);
	}
    fd(i,n-1,2){
		h2[i]=max(h2[i+1],p[i]);
	}
    fu(i,2,n-1){
		if(h2[i]-h1[i-1]>p[n]){
			return 0;
		}
	}
    return 1;
}
double ef(double l,double r){
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(pd(mid)) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	n=read();
	fu(i,1,n){
		a[i]=read();
	}
    fu(i,1,n){
		sum[i]=sum[i-1]+a[i];
	}
    sj=((double)(a[1]+a[n]))/2.0;
	h1[0]=inf;
	h2[n]=-inf;
	ans=ef(0,sj);
	printf("%.3lf",ans);
    return 0;
}
