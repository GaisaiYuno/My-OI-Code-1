#include<iostream>
#include<cstdio>
#define maxn 100005 
using namespace std;
int a[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++) a[i]=min(a[i],a[i-1]+1);
	for(int i=n;i>=1;i--) a[i]=min(a[i],a[i+1]+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	printf("%d\n",ans);
	
}
