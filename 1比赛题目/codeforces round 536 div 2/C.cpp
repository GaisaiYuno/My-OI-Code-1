#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 300005
using namespace std;
int n;
long long a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	}
	cout<<ans;
}

