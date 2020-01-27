#include<iostream>
#include<cstdio>
using namespace std;
double h,l;
int main(){
	cin>>h>>l;
	double ans=(h*h+l*l)/(2*h)-h;
	printf("%.10f\n",ans);
}

