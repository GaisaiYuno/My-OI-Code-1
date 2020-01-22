#include<iostream>
#include<cstdio>
using namespace std;
long long n,S;
int main(){
	cin>>n>>S;
	if(S%n) cout<<S/n+1;
	else cout<<S/n;
} 
