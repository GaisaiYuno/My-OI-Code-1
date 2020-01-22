#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,k;
int main(){
	cin>>n>>k;
	if(k%n==0) cout<<(k/n);
	else cout<<(k/n+1);
} 
