#include<iostream>
#include<cstdio>
#define maxn 200005
#define INF 0x7fffffffffffffff
using namespace std;
int n;
long long a[maxn];
long long b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++) scanf("%I64d",&b[i]);
	a[n+1]=INF; 
	for(int i=1;i<=n/2;i++){
		a[i]=a[i-1];
		a[n+1-i]=b[i]-a[i];
		if(a[n+2-i]<a[n+1-i]){
			a[n+1-i]=a[n+2-i];
			a[i]=b[i]-a[n+1-i];
		}
	}	
	for(int i=1;i<=n;i++){
		printf("%I64d ",a[i]);
	}
}
