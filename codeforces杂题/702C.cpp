#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
int b[maxn];
int sum[maxn];
int check(long long r){
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=m;i++){
		int x=lower_bound(a+1,a+1+n,b[i]-r)-a;
		int y=upper_bound(a+1,a+1+n,b[i]+r)-a-1;
		if(y<x) continue;
		sum[x]++;
		sum[y+1]--;
	}
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		if(sum[i]<=0) return 0;
	}
	return 1;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	long long l=0,r=1e10,mid;
	long long ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans;
} 
