#include<iostream>
#include<cstdio>
#define INF 0x7fffffff
#define maxn 105
using namespace std;
int n;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long ans=INF,sum=0;
	for(int x=1;x<=n;x++){
		sum=0;
		for(int i=2;i<=n;i++){
			sum+=2*abs(x-i)*a[i];
			sum+=2*abs(x-1)*a[i];
			sum+=2*abs(i-1)*a[i];
		}
		ans=min(ans,sum); 
	}
	cout<<ans;
} 
