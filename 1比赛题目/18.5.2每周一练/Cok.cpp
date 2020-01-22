#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 500005
using namespace std;
int n;
long long a[maxn];
long long sum[maxn]; 
int main(){
	long long ans=0,cnt=0; 
	scanf("%d",&n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	long long total=sum[n];
	if(total%3) {
		printf("0");
		return 0;
	}
	total=sum[n]/3;
	for(int i=1; i<n; i++) {
		if(sum[i]==total*2) ans+=cnt;
		if(sum[i]==total&&i<n) cnt++;
	}
	printf("%I64d\n",ans);
} 
