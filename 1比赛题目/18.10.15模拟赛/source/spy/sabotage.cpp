#include<iostream>
#include<cstdio>
using namespace std;
int n;
double a[100001],p[100001],q[100002],pm[100001],qm[100002];
bool chekku(double mid){
	p[0]=0;q[n+1]=0;
	double op1=1e18,op2=1e18;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i]-mid;
		op1=min(op1,p[i]);
		pm[i]=op1;
	}
	for(int i=n;i>=1;i--){
		q[i]=q[i+1]+a[i]-mid;
		op2=min(op2,q[i]);
		qm[i]=op2;
	}
	for(int i=1;i<=n-1;i++){
		if(pm[i]+qm[i+1]<=0)return true;
	}
	return false;
}
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	double l=0,r=(a[1]+a[n])/2,mid;
	//printf("%lf",&a[1]);
	//cout<<a[1]<<" "<<a[n]<<endl;
	while(r-l>=0.0001){
		mid=(l+r)/2;//cout<<l<<" "<<r<<" "<<mid<<'\n';
		if(chekku(mid))r=mid;
		else l=mid;
	}
	printf("%.3lf",l);
//	cout<<chekku(20.000);
}
