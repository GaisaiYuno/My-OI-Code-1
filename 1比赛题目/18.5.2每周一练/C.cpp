#include<iostream>
#include<cstdio>
#define maxn 500005
using namespace std;
int n;
int a[maxn];
long long sum[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+(long long)a[i];
	}
	int ans=0;
	long long t;
	for(int i=1;i<=n;i++){
		t=sum[i];
//		if(sum[n]-sum[i]<t&&t>=0) continue;
		for(int j=i+1;j<n;j++){
			if(sum[j]-sum[i]==sum[n]-sum[j]&&sum[j]-sum[i]==t) ans++;
		}
	}
	printf("%d\n",ans);
}
