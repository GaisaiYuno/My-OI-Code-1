//http://111.230.183.91:8080/problem/319
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	cout<<min(min(n,m),(n+m)/3);
}
