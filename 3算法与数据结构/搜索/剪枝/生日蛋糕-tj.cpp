#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 10000
#define INF 2147483647
using namespace std;
int ans=INF;
int n,m;
void dfs(int last_h,int last_r,int nows,int leftv,int level){
//	printf("%d %d %d\n",nows,n-leftv,m-level);
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
			if(nows+s>ans) continue;
			if(leftv-v<0) continue;
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
