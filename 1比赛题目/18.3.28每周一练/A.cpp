//为什么v正着搜不行？ 
#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 10000
#define INF 2147483647
using namespace std;
int ans=INF;
const double pi=3.14;
int n,m;
void dfs(int last_h,int last_r,int nows,int leftv,int level){
	if(nows>ans) return;
	if(leftv<0) return;
	if(level==0&&leftv==0){
		ans=min(ans,nows);
		return;
	}
	if(level<=0) return; 
	for(int i=last_r-1;i>=level;i--){
		for(int j=last_h-1;j>=level;j--){
			int v=i*i*j;
			int s=2*i*j;
			if(level==m) s+=i*i;
			if(nows+2*leftv/i>ans) continue;
			dfs(j,i,nows+s,leftv-v,level-1); 
		}
	}
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		ans=INF;
		dfs(10000,100,0,n,m);
		if(ans==INF) ans=0;
		printf("%d\n",ans);
	}
} 
