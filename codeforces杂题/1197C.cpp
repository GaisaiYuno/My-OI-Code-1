#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 300000
using namespace std;
int n,k;
long long sum=0;
int a[maxn+5];
int d[maxn+5];
int cmp(int x,int y){
	return x>y;
} 
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sum+=d[i];
	}
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<=k-1;i++){
		sum-=d[i];
	}
	printf("%I64d\n",sum);
}

