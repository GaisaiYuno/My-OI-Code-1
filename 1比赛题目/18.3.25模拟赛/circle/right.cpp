#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,k,x;
int main(){
	cin>>n>>m>>k>>x;
	cout<<(x+(long long)pow(10,k)%n*m)%n;
} 
