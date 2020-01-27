#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m,k;
int b[maxn];
int d[maxn];
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]); 
	} 
	for(int i=1;i<n;i++){
		d[i]=b[i+1]-b[i]-1;
	}
	sort(d+1,d+n);
	long long ans=0;
	for(int i=1;i<=n-k;i++){
		ans+=d[i];
	} 
	ans+=n;
	printf("%I64d\n",ans);
}

