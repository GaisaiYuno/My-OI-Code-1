#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-11 
#define pi 3.141592653589793
using namespace std;
double L,n,C,theta,x;
int main(){
//	freopen("A.1.dat","r",stdin);
	while(scanf("%lf %lf %lf",&L,&n,&C)!=EOF){
		if(L==n&&n==C&&C==-1) break;
		if(n*C==0){
			printf("0.000\n");
			continue;
		} 
		double l=eps,r=pi/2;//用弧度表示角 
		while(fabs(l-r)>eps){
			double mid=(l+r)/2;
			double hu=L/sin(mid)*mid;
			if(hu>L+L*n*C) r=mid;
			else l=mid;
		}
		theta=l;
		double R=L/(2*sin(theta));
		printf("%.3f\n",R*(1-cos(theta)));
	} 
} 
