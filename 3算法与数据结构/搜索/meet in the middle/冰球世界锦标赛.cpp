//http://111.230.183.91:8080/problem/9
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 45
#define maxs 2000005
using namespace std;
int n;
long long m;
long long a[maxn];
int lcnt; 
long long lans[maxs];
int rcnt; 
long long rans[maxs];
void dfs(long long *ans,int &size,int deep,int top,long long sum){
	if(sum>m) return;
	if(deep==top+1){
		ans[++size]=sum;
		return;
	}
	dfs(ans,size,deep+1,top,sum+a[deep]);
	dfs(ans,size,deep+1,top,sum);
}

int main(){
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(lans,lcnt,1,n/2,0);
	dfs(rans,rcnt,n/2+1,n,0);
	sort(lans+1,lans+1+lcnt);
	sort(rans+1,rans+1+rcnt);
	long long ans=0;
	for(int i=1;i<=lcnt;i++){
		ans+=upper_bound(rans+1,rans+1+rcnt,m-lans[i])-rans-1;
	} 
	printf("%lld\n",ans);
}
