//http://111.230.183.91:8080/problem/19
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000005
using namespace std;
int n,m;
long long a[maxn];
long long d[maxn];
long long pre[maxn];
long long suf[maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n+1;i++){
		d[i]=(a[i]-a[i-1]+m)%m;
	}
	sort(d+1,d+1+n+1);
	for(int i=1;i<=n+1;i++){
		pre[i]=pre[i-1]+d[i];
	}
	for(int i=n+1;i>=1;i--){
		suf[i]=suf[i+1]+m-d[i];
	}
	for(int i=1;i<=n+1;i++){
		if(pre[i-1]==suf[i]){
			printf("%lld\n",pre[i-1]);
		}
	}
}
