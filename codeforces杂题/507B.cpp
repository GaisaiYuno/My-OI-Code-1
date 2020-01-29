#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int updouble(double u){
	if((int)u==u) return (int)u;
	else return (int)u+1;
}
int main(){
	double x1,y1,x2,y2,d;
	scanf("%lf %lf %lf %lf %lf",&d,&x1,&y1,&x2,&y2);
	double ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/d/2;
	int tmp=updouble(ans); 
	printf("%d\n",tmp);
} 
