#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#define maxn 300005
using namespace std;
int n;
long long x;
long long a[maxn];
long long sum[maxn];
long long lf[maxn],rf[maxn];
deque<long long >q;
int main(){
	scanf("%d %I64d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		lf[i]=max(lf[i],lf[i-1]+a[i]);
		lf[i]=max(lf[i],a[i]);
		lf[i]=max(lf[i],0ll);
	}
	for(int i=n;i>=1;i--){
		rf[i]=max(rf[i],rf[i+1]+a[i]);
		rf[i]=max(rf[i],a[i]);
		rf[i]=max(rf[i],0ll);
	}
	long long ans=0;
	long long lsum,rsum;
	lsum=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,lf[i]);
		ans=max(ans,x*sum[i]+rf[i+1]+lsum);
		lsum=max(lsum,lf[i]-x*sum[i]);
	}
	printf("%I64d\n",ans);
}
/*
My approach for problem D is quite different. I hope it would be easy to understand.

At first, I build 2 arrays Left(i) and Right(j) that return the maximum sum of a subarray ending at i with Left(i) and starting at j with Right(j). I also have array Sum(i) is sum of all elements from 1 to i.

When we multiply the subarray (l..r), the result in current case is

Left(l-1) + x * (Sum(r) - Sum(l-1)) + Right(r+1).

We can rewrite it by

(Right(r+1) + x * Sum(r)) + (Left(l-1) - x * Sum(l-1)).

With this formula, my solution is a loop for i from 1 to n, take i as the right most of the multiply subarray, get the best value of the left most to update the answer.

See my submission for more details: 53150702
*/
