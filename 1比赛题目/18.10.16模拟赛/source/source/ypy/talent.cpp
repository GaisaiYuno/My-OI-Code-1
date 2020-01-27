#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 255
#define maxv 2000005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,m;
int w[maxn],t[maxn];
double v[maxn];
double dp[maxv];
int check(double k){
	int sum=0;
	double ans=0;
	for(int i=1;i<=n;i++){
		v[i]=(double)w[i]-k*t[i];
		sum+=w[i];
		ans+=v[i];
	}
	sum=sum-m;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=w[i];j--){
			dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	ans=ans-dp[sum];
	if(ans<0) return 0;
	else return 1;
}
double bin_ans(){
	double l=0,r=1e9;
	for(int i=1;i<=70;i++){
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++){
		t[i]=qread();
		w[i]=qread();
	}
	double t=bin_ans();
	long long x=floor(1000.0*t);
	printf("%lld\n",x);
}
