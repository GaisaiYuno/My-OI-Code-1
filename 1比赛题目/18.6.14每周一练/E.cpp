#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn],b[maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	int ans=0;
	b[0]=b[1];
	b[m+1]=b[m];
	for(int i=1;i<=n;i++){
		int k=lower_bound(b+1,b+1+m,a[i])-b;
		int x=min(abs(b[k]-a[i]),abs(b[k-1]-a[i]));
		ans=max(ans,x);
	} 
	printf("%d\n",ans);
} 
