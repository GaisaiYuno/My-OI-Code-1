#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
int n,m,k;
long long a[maxn];
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+1+n);
	printf("%I64d\n",m/(k+1)*(a[n]*k+a[n-1])+m%(k+1)*a[n]);
}

