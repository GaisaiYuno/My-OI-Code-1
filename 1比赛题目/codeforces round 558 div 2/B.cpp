#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int sum[maxn];
int cntsum[maxn];
int maxs,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	maxs=0;
	for(int i=1;i<=n;i++){
		cntsum[sum[a[i]]]--;
		sum[a[i]]++;
		cntsum[sum[a[i]]]++;
		maxs=max(maxs,sum[a[i]]);
		if(cntsum[1]==i||
		   cntsum[i]==1||
		  (cntsum[1]==1&&cntsum[maxs]*maxs+1==i)||
		  (cntsum[maxs]==1&&cntsum[maxs-1]*(maxs-1)+cntsum[maxs]*maxs==i)
		) ans=max(ans,i); 
	}
	printf("%d\n",ans);
}

