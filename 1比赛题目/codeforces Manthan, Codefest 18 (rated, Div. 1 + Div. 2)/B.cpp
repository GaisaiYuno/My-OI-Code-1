#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;
int n,s;
int a[maxn];
int main(){
	scanf("%d %d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	long long ans=0;
	ans+=abs(a[n/2+1]-s);
	for(int i=n/2;i>=1;i--){
		if(a[i]>s) ans+=(a[i]-s);
		else break;
	}
	for(int i=n/2+2;i<=n;i++){
		if(a[i]<s)ans+=(s-a[i]);
		else break;
	}
	printf("%I64d\n",ans);
}
