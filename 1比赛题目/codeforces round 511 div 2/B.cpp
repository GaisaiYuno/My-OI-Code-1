#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n;
int x[maxn],y[maxn];
int main(){
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x[i],&y[i]);
		ans=max(ans,(long long)x[i]+y[i]);
	}
	printf("%I64d\n",ans);
}
