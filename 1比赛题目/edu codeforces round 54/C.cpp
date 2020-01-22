#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int t;
long long d;
long long delta;
double x1,x2;
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%I64d",&d);
		delta=d*d-4*d;
		if(delta<0){
			printf("N\n");
		}else{
			printf("Y ");
			x1=(d+sqrt(delta))/2;
			x2=(d-sqrt(delta))/2;
			printf("%.9f %.9f\n",x1,x2);
		}
	}
}
