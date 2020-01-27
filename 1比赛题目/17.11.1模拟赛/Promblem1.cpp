#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=3.1415926;
int n,year;
double x,y,d,r1,r2;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		d=x*x+y*y;
		year=0;
		//for(r1=0;r2=(100/pi+r1*r1),r2<d;r1=sqrt(r2)) year++;
		r1=0;
		while(r2<d){
			r2=(100/pi+r1*r1);
			r1=sqrt(r2);
			year++;
		}
		 printf("Property %d: This property will begin eroding in year %d.\n",i,year); 
	}
	printf("END OF OUTPUT.\n");
}
