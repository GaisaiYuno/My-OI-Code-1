#include<iostream>
#include<cstdio>
using namespace std;
long long n,ans;
int main(){
	scanf("%I64d",&n);
	while(n){
		ans++;
		n/=2;
	}
	printf("%I64d\n",ans);
} 
