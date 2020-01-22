#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long x2=x,y2=y;
	x=y2;
	y=x2-(a/b)*y2;
} 
long long a,b,x,y;
int main(){
	cin>>a>>b;
	exgcd(a,b,x,y);
	while(x<=0) x+=b;
	cout<<x;
	
}
