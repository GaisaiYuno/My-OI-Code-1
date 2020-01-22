#include<iostream>
#include<cstdio>
#define maxn 300005
using namespace std;
long long l,r;
long long a[maxn];
int main(){
	scanf("%I64d %I64d",&l,&r);
	for(long long i=l;i<=r;i++){
		a[i-l+1]=i;
	}
	printf("YES\n");
	for(int i=1;i<=r-l+1;i+=2){
		printf("%I64d %I64d\n",a[i],a[i+1]);
	} 
}
