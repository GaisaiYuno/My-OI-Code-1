#include<iostream>
#include<cstdio>
using namespace std;
long long n;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%I64d",&n);
	long long l=1,r=n,a=1,b=2*n-1,t=0;
	while(l<r){//cout<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
		if(a==b){t++;l++;r--;a=a+l*2-1;b=b+r*2-1;}
		else if(a<b){l++;a=a+l*2-1;}
		else {r--;b=b+r*2-1;}
	}
	//cout<<t<<endl;
	cout<<t*8+4;
}
