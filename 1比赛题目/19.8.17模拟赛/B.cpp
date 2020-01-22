#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define eps 1e-4
#define maxans 1e4
#define maxt 25
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qread(ll &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
int n;
ll d;
ll a[maxn+5],x[maxn+5];
ll sum[maxn+5];
bool check(int k,double mid){
	double curtim=0;
	double maxtim; 
	double shoottim;
	for(int i=k;i>=1;i--){
		maxtim=x[k]+(k-i)*d-curtim;
		shoottim=a[i]/mid;
		if(shoottim-maxtim>eps) return 0;
		curtim+=shoottim;
	}
	return 1;
}
double solve(int k){
//	double l=0,r=maxans;
//	double ans=r;
//	double mid;
//	for(int i=1;i<=maxt;i++){
//		mid=(l+r)/2;
//		if(check(k,mid)){
//			ans=mid;
//			r=mid-eps;
//		}else l=mid+eps;
//	}
//	return ans;
	double ans=0;
	for(int i=k;i>=1;i--){
		ans=max(ans,1.0*(sum[k]-sum[i-1])/(x[k]+(k-i)*d));
	}
	return ans;
}
int main(){
	qread(n);
	qread(d);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		qread(x[i]);
		sum[i]=sum[i-1]+a[i];
//		scanf("%lld %lld",&a[i],&x[i]);
	}
	double ans=0;
	double cur=0;
	for(int i=1;i<=n;i++){
		cur=solve(i);
		ans+=cur;
//		printf("%.5f\n",cur);
	}
//	ans=7.6;
	printf("%.0f\n",ans);
}
