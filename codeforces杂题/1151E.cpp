#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n;
long long a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			ans+=(a[i]-a[i-1])*(n-a[i]+1);
		}else{
			ans+=a[i]*(a[i-1]-a[i]);
		}
	}
	printf("%I64d\n",ans);
}

