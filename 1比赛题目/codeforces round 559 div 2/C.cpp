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
		//��1��Ůi��g[i],����g��С����min(a[1,i])=min(g[i])=g[1]=b[1] 
		//��i(i=2...n)������Ů����b[i] 
		ans=sum;
		for(int i=2;i<=n;i++){
			ans+=(long long)b[i]*m; 
		} 
		printf("%I64d\n",ans);
	} else if(b[1]<g[1]){
		//��1��Ů1��b[1],��������g[i] min(a[1,i])=min(b[1],g[2..n]),����b[1]<g[1]<g[2...n],ԭʽ=b[1] 
		//��2��Ů1��g[1],��������b[2],min(a[1,i])
//		��i(i=3...n)������Ů����b[i] 
		ans=sum-g[1]+b[1];
		ans+=g[1]+(long long)b[2]*(m-1);
		for(int i=3;i<=n;i++){
			ans+=(long long)b[i]*m;
		} 
		printf("%I64d\n",ans); 
	} 
}

