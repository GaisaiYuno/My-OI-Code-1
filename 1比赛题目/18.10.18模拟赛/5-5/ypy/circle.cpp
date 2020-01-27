#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int cnt=0;
long double r;
long double x;
long double y;
int main(){
	cin>>r;
	if(r>30000000){
		printf("4\n");
		return 0;
	} 
	for(register long double n=1;n<r;n++){
		x=n;
		y=sqrt(r*r-x*x);
		if(y==int(y)){
//			printf("%Lf %Lf\n",x,y);
			cnt++;
		}
	}
	cout<<cnt*4+4;
}
