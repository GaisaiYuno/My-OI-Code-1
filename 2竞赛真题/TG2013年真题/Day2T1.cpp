#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int d[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i]=a[i]-a[i-1];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(d[i]>0)ans+=d[i];
	}
	printf("%lld\n",ans); 
} 
