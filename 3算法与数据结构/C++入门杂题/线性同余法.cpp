#include<iostream>
using namespace std;
int a,b,m,n;
int num[40];
int main(){
	cin>>a>>b>>m;
	cin>>n;
	num[1]=10;
	for(int i=2;i<=n;i++){
		num[i]=(a*num[i-1]+b)%m;
	}
	for(int i=1;i<=n;i++) cout<<num[i]<<' ';
}
