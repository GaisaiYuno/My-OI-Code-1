#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int n;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=2;i<=n;i++){
		ans+=(a[i]-a[i-1]-1);
	}
	printf("%I64d\n",ans);
} 
