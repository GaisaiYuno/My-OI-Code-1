#include<iostream>
#include<cstdio>
#include<algorithm> 
#define maxn 100005
using namespace std;
int n,m;
int b[maxn];
int g[maxn];
int cmp(int x,int y){
	return x>y;
}
int main(){
	long long sum=0;
	long long ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&g[i]);
		sum+=g[i];
	} 
	sort(b+1,b+1+n,cmp);
	sort(g+1,g+1+m);
	if(b[1]>g[1]){
		printf("-1\n"); 
	}else if(b[1]==g[1]){
		//男1向女i送g[i],由于g从小到大，min(a[1,i])=min(g[i])=g[1]=b[1] 
		//男i(i=2...n)向所有女生送b[i] 
		ans=sum;
		for(int i=2;i<=n;i++){
			ans+=(long long)b[i]*m; 
		} 
		printf("%I64d\n",ans);
	} else if(b[1]<g[1]){
		//男1向女1送b[1],向其他送g[i] min(a[1,i])=min(b[1],g[2..n]),由于b[1]<g[1]<g[2...n],原式=b[1] 
		//男2向女1送g[1],向其他送b[2],min(a[1,i])
//		男i(i=3...n)向所有女生送b[i] 
		ans=sum-g[1]+b[1];
		ans+=g[1]+(long long)b[2]*(m-1);
		for(int i=3;i<=n;i++){
			ans+=(long long)b[i]*m;
		} 
		printf("%I64d\n",ans); 
	} 
}

