#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,l,r;
int a[maxn+5];
long long get_max(int k){
	a[1]=1;
	for(int i=2;i<=n;i++){
		if(i<=k) a[i]=a[i-1]*2;
		else a[i]=a[i-1];
	}
	long long ans=0;
	for(int i=1;i<=n;i++) ans+=a[i];
	return ans;
}
long long get_min(int k){
	a[1]=1;
	for(int i=2;i<=n;i++){
		if(i<=k) a[i]=a[i-1]*2;
		else a[i]=1;
	}
	long long ans=0;
	for(int i=1;i<=n;i++) ans+=a[i];
	return ans;
}
int main(){
	scanf("%d %d %d",&n,&l,&r);
	long long ans1=0,ans2=INF;
	for(int i=l;i<=r;i++){
		ans1=max(ans1,get_max(i));
		ans2=min(ans2,get_min(i)); 
	}
	printf("%I64d %I64d\n",ans2,ans1);
}

