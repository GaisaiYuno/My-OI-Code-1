#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void exgcd(long long a,long long b,long long& x,long long& y){
	if(!b){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long x2=x,y2=y;
	x=y2;
	y=x2-(a/b)*y2;
}
long long a,b;
int main(){
	scanf("%lld %lld",&a,&b);
	long long x,y;
	exgcd(a,b,x,y);
	long long x0=x;
	while(x0<=0) x0+=b;
	printf("%lld\n",x0);
}
