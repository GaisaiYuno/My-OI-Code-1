#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,k;
int a[maxn];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	long long sum=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>sum){
			printf("%d\n",a[i]-sum);
			cnt++;
			sum+=a[i]-sum; 
		}
		if(cnt==k) break;
	}
	for(int i=cnt+1;i<=k;i++){
		printf("%d\n",0);
	}
} 
