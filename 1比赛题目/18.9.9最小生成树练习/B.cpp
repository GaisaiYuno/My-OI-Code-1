#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1005
#define eps 1e-4
using namespace std;
int n,k;
struct test{
	int a;
	int b;
	double r;
	double cal(){
		return (double)a-r*(double)b;
	}
	friend bool operator <(test x,test y){
		return x.cal()>y.cal(); 
	}
}t[maxn];
double f(double x){
	for(int i=1;i<=n;i++){
		t[i].r=x;
	}
	sort(t+1,t+1+n);
	double ans=0;
	for(int i=1;i<=n-k;i++){
		ans+=t[i].cal();
	}
	return ans;
}

double frac_01(){
	double l=0,r=1,mid;
	while(fabs(r-l)>eps){
		mid=(l+r)/2;
		double t=f(mid);
//		printf("[%.5f,%.5f] %.5f %.5f\n",l,r,mid,t);
		if(t>=0){
			l=mid;
		}else{
			r=mid;
		}
	}
	return l;
}
int main(){
	while(scanf("%d %d",&n,&k)!=EOF){
		if(n==0&&k==0) break;
		for(int i=1;i<=n;i++){
			scanf("%lld",&t[i].a);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&t[i].b);
		}
		printf("%.0f\n",frac_01()*100);
	}
}
