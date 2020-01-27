#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long dp[20][10];//dp[i][j]表示第i位j个非零数字 方法数 
int digit[20];
long long dfs(int pos,int cnt,bool jud){
	//pos当前位置,cnt非零数字个数,jud是否和边界一样 
	if(pos<=0) return 1;
	if(!jud&&dp[pos][cnt]!=-1&&cnt<=3){//满足条件 
		return dp[pos][cnt];
	}
	int num=jud?digit[pos]:9;
	long long ans=0;
	for(int i=0;i<=num;i++){
		if(i!=0&&cnt==3) continue;
		if(i!=0&&cnt<3){
			ans+=dfs(pos-1,cnt+1,jud&&i==num);//都是数位DP的模板套路 
		}
		if(i==0){
			ans+=dfs(pos-1,cnt,jud&&i==num);
		}
	}
	if(!jud) dp[pos][cnt]=ans;
	return ans;
}
long long solve(long long n){
	int len=0;
	memset(dp,-1,sizeof(dp));
	while(n){
		digit[++len]=n%10;
		n/=10;
	}
	return dfs(len,0,1);
}
int t;
int main(){
	long long l,r;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d %I64d",&l,&r);
		printf("%I64d\n",solve(r)-solve(l-1));
	}
}
