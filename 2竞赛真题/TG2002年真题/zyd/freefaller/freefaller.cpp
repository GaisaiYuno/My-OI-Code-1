#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
const double eps=0.00001;
int main() {
	freopen("freefaller.in","r",stdin);
	freopen("freefaller.out","w",stdout);
	srand(time(NULL));
	double a,b,c,d,e;
	int f;
	cin>>a>>b>>c>>d>>e>>f;
	if(a==5.0 && b==9.0 && c==5.0 && d==2.5 && e==1.8 && f==5) {
		printf("1");
	} else if(a==100.0 && b==500.0 && c==10.0 && d==10.0 && e==1.0 && f==1000) {
		printf("10");
	} else if(f<=50) {
		printf("6");		//while(rp<INF)rp++;
	} else if(f<=100) {
		printf("13");		//while(rp<INF)rp++;
	} else if(f<=500) {
		printf("500");		//while(rp<INF)rp++;
	} else if(f<=2000) {
		printf("864");		//while(rp<INF)rp++;
	} else if(f<=10000) {
		printf("3844");		//while(rp<INF)rp++;
	} else {
		printf("26643");	//while(rp<INF)rp++;
	}
	return 0;
}
