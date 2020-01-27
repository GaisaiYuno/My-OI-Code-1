#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,t;
int a[maxn];
int sum[maxn];
int bin_search(int *a,int L,int R,int x){
	int l=L,r=R,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else{
			ans=mid;
			l=mid+1;
		}
	} 
	return ans;
}
int main(){
	scanf("%d %d",&n,&t);
	for(int i=1;i<=n;i++){ 
		 scanf("%d",&a[i]);
		 sum[i]=sum[i-1]+a[i];
	} 
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>t) continue;
		cnt=max(cnt,bin_search(sum,1,n,sum[i-1]+t)-i+1);
	} 
	printf("%d\n",cnt);
} 
