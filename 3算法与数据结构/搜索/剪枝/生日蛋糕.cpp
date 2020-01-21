#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define INF 0x7fffffff
using namespace std;
const double pi=acos(-1);
int n,m;
long long ans;
void dfs(int deep,int top,long long sumv,long long suma,int last_r,int last_h){
	printf("d=%d v=%lld s=%lld lr=%d lh=%d\n",deep,sumv,suma,last_r,last_h);
	if(suma>ans) return;
	if(sumv>n) return;
	if(deep==top+1){
		if(sumv==n) ans=min(ans,suma);
		return;
	}
	long long maxr=min((int)sqrt(n-sumv),last_r-1);
	long long maxh;
	for(long long i=last_r-1;i>=deep;i--){
//		maxh=min((n-sumv)/(i*i),last_h-1);
		for(long long j=last_h-1;j>=deep;j--){
			long long v=i*i*j;
			long long s=2*i*j;
			if(deep==1) s+=i*i; 
			if(suma+2*(n-sumv)/i>ans) continue;
			if(sumv+v>n) continue;
			if(suma+s>=ans) continue;
			dfs(deep+1,top,sumv+v,suma+s,i,j); 
		}
	}
} 

int main(){
	scanf("%d %d",&n,&m); 
	ans=INF;
	dfs(1,m,0,0,10000,100);
	if(ans==INF){
		printf("0\n");
	}else{
		printf("%d\n",ans);
	}
}
