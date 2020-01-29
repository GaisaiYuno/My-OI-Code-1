#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
long long a[maxn];
long long b[maxn];
long long c[maxn];
long long cmp(long long a,long long b){
	return a>b;
}
int main(){
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d %I64d",&a[i],&b[i]);
		c[i]=a[i]-b[i];
		ans+=b[i]*n-a[i];
	}
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++){
		ans+=i*c[i];
	}
	printf("%I64d\n",ans);
}

