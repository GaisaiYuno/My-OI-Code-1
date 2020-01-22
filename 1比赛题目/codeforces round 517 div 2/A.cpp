#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	long long ans=0;
	for(int i=1;i<=k;i++){
		int a=n-4*(i-1);
		int b=m-4*(i-1);
		ans+=(long long)2*(a+b)-4;
	}
	cout<<ans;
} 
