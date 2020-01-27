#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[4]; 
long long d;
int main(){
	for(int i=1;i<=3;i++) scanf("%I64d",&a[i]);
	scanf("%I64d",&d);
	sort(a+1,a+1+3);
	long long d1=a[2]-a[1];
	long long d2=a[3]-a[2];
	printf("%I64d\n",max(d-d1,0ll)+max(d-d2,0ll)); 
}

