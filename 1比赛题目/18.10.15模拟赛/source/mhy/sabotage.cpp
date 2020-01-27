#include <iostream>
#include <cstdio>
#define MAXN 100005
using namespace std;
int A[MAXN],sum[MAXN];
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (register int i=1;i<=n;++i){
		scanf("%d",&A[i]);
	}
	for (register int i=1;i<=n;++i){
		sum[i]=A[i]+sum[i-1];
	}
	double ans=0x7fffffff;
	int time=0;
	for (register int i=2;i<=n-1;++i){
		for (register int j=n-1;j>=i;--j){
			int len=n-(j-i+1);
			int s=(sum[i-1]+sum[n]-sum[j]);
			ans=min(ans,(double)((double)s/(double)len));
			time++;
			if (time==100000000){
				printf("%.3f\n",ans);
				return 0;
			}
		}
	}
	printf("%.3f\n",ans);
}
