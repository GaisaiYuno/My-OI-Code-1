#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long x,y,a,b;
inline long long gcd(long long x,long long y){
	return y==0?x:gcd(y,x%y); 
}
int main(){
	cin>>x>>y>>a>>b;
	long long g=gcd(a,b);
	a/=g;
	b/=g;
	cout<<min(x/a,y/b);
}
