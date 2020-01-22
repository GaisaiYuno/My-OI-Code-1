#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int a[maxn],used[maxn];
int n,k;
long long l;
int main(){
	scanf("%d %d %I64d",&n,&k,&l);
	for(int i=1;i<=n*k;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n*k);
	int last=0,cnt=0;
	long long ans=0;
	if(a[n]-a[1]>l){
		printf("0\n");
		return 0;
	}
    last=lower_bound(a+1,a+n*k+1,a[1]+l+1)-a-1;
	for(int i=1;i<=last;i+=k){
		used[i]=1;
		ans+=a[i];
		cnt++;
	}
	if(cnt==n){
		printf("%I64d\n",ans);
		return 0;
	}
	for(int i=last;i>=1;i--){
		if(used[i]) continue;
		ans+=a[i];
		cnt++;
		if(cnt==n) break;
	}
	printf("%I64d\n",ans);
	return 0;
}
