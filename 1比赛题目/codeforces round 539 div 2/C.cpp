#include<iostream>
#include<cstdio>
#define maxn 300005
#define maxv 1<<21
using namespace std;
int n;
int a[maxn];
int cnt[maxv][2]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int sum=0;
	cnt[0][0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		sum^=a[i];
		ans+=cnt[sum][i%2];
		cnt[sum][i%2]++;
	}
	printf("%I64d\n",ans);
}

