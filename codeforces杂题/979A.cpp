#include<iostream>
#include<cstdio>
using namespace std;
long long n;
int main(){
	cin>>n;
	n++;
	if(n%2==1) cout<<n;
	else cout<<n/2;
} 
