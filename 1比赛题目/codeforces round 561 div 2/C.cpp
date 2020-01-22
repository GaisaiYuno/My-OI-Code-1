#include<iostream>
#include<cstdio>
#include<algorithm> 
#define maxn 500005
using namespace std;
int n;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0) a[i]=-a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		int j=upper_bound(a+i,a+1+n,a[i]*2)-a-1;
		ans+=(j-i);
	}
	printf("%I64d\n",ans);
}

