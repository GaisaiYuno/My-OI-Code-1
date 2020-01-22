#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200005
#define INF 0x7fffffff 
using namespace std;
int n,m,k,ta,tb;
long long a[maxn];
int pre[maxn];
int to[maxn];
long long b[maxn];
int check(int mid) {
	int ans=INF;
	for(int i=1; i<=mid; i++) {
		int ca1=pre[i];
		int cb1=mid-to[pre[i]+1];
//		int ca2=pre[mid]-pre[i];
//		int cb2=i-1;
		if(ca1+cb1<=k) return 1;
	}
	return 0;
}
int main() {
	scanf("%d %d %d %d %d",&n,&m,&ta,&tb,&k);
	if(k>=n||k>=m){
		printf("-1\n");
		return 0; 
	} 
	for(int i=1; i<=n; i++) {
		scanf("%I64d",&a[i]);
		a[i]+=ta;
	}
	for(int i=1; i<=m; i++) scanf("%I64d",&b[i]);
	long long ans=0;
	for(int i=0;i<=k;i++){
		int t=lower_bound(b+1,b+1+m,a[i+1])-b;
		int p=k-i;
		if(m-t+1<=p){
			ans=-1;
			break;
		}
		else ans=max(ans,b[t+p]+tb);
	}
	printf("%I64d\n",ans); 
}
