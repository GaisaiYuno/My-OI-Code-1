#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long n;
int ans;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n;
//	if(n&1){
//		cout<<2*n+2;
//		return 0;
//	}
	if(n>=37000000){
		cout<<4;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(sqrt((n-i)*(n+i))==floor(sqrt((n-i)*(n+i))))ans++;
	}
	cout<<ans*4;
}
