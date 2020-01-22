#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 200000
using namespace std;
int n;
long long a[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(sum%2==1||a[n]*2>sum) printf("NO\n");
	else printf("YES\n"); 
}

