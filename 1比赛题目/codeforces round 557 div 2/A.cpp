#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 50 
using namespace std;
typedef long long ll;
ll ans=0;
int n,h,m;
int lim[maxn+5];
int main(){
	int l,r,x;
	scanf("%d %d %d",&n,&h,&m);
	memset(lim,0x3f,sizeof(lim));
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&l,&r,&x);
		for(int j=l;j<=r;j++) lim[j]=min(lim[j],x);
	}
	ll now;
	for(int i=1;i<=n;i++){
		now=min(lim[i],h);
		ans+=now*now;
	}
	printf("%I64d\n",ans); 
}


