#include<iostream>
#include<cstdio>
#include<cstring>
#define MYINF -2147483647
#define maxn 20
#define maxk 1<<16
using namespace std;
int t,n,ans;
struct node{
	int a;
	int p;
}num[maxn];
int dp[maxk][maxn];
int count[maxk];
void pre(){
	for(int i=0;i<maxk;i++){//预处理出每个二进制数中有几个1 
		if((i&1)==0) count[i]=count[i>>1];
		else count[i]=count[i>>1]+1;
	}
}
void ini(){//初始化 
	for(int i=0;i<(1<<n);i++){
	   for(int j=0;j<n;j++) dp[i][j]=MYINF; 
	} 
	for(int i=0;i<n;i++){
		if(num[i].p==0||num[i].p==-1) dp[1<<i][i]=0;
	}
}
int main(){
	pre();
	cin>>t;
	for(int u=1;u<=t;u++){
		cin>>n;
		for(int i=0;i<n;i++) cin>>num[i].a>>num[i].p;
		ini(); 
		for(int k=0;k<(1<<n);k++){
			for(int j=0;j<n;j++){
				if(dp[k][j]==MYINF) continue;
				//遍历k状态查看t是否可以插入到该位置 
				for(int t=0;t<n;t++){
					if(((k&(1<<t))==0/*判重*/)&&(num[t].p==-1||num[t].p==count[k]/*是否插入,若k中已有2个1,如果p=2(第三位)，则必须插入*/)) 
					    dp[k|(1<<t)][t]=max(dp[k][j]+num[t].a*num[j].a,dp[k|(1<<t)][t]);
				}
			}
		}
		ans=MYINF; 
		for(int i=0;i<n;i++) { 
            ans=max(ans,dp[(1<<n)-1][i]); 
		} 
		printf("Case #%d:\n%d\n",u,ans);
		//debug();
	}
}
/*状态转移方程 
i 开始位置，但可以由k推出，（即k中第一个1 的位置），可去掉不用 
k 二进制储存使用情况
j 为该状态最后一个位置 
for k=0;k<(1<<16) k++
    for j=0;j<16;j++ 
       dp[k|(1<<t)][t]=max(dp[k][j]+num[t].a*num[j].a,dp[k|(1<<t)][t]);    t=0~n 注意有数是固定的，并且t包含于k
        k|(1<<t)表示把k的第t位变成1 
*/ 
