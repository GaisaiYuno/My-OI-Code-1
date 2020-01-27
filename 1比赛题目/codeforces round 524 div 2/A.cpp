#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
long long r,g,b;
long long divs(long long a,long long b){
	if(a%b==0) return a/b;
	else return a/b+1;
}
int main(){
	cin>>n>>k;
	r=2*n;
	g=5*n;
	b=8*n;
	r=divs(r,k);
	g=divs(g,k);
	b=divs(b,k);
	cout<<r+g+b<<endl;
} 
