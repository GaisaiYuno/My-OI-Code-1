//HDU 1565 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define size 20005
using namespace std;
int n;
int ans=0;
int a[maxn][maxn];
int dp[maxn][size];
struct node{
	int kind;//方案情况 
	int sum;//方案对应的和 
};
int cnt=0,front_cnt=0;
node r[size],front_r[size];
inline int read(){
	int x=0;
	char c=getchar();
	int sign=1;
	while(c<'0'||c>'9') {
		c=getchar();
		if(c=='-') sign=-1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void dfs(int h,int deep,int k,int sum){//行 列 每一行的情况  和 
    /*状态压缩: 
    用20位的二进制数（小于整型32位）
	表示每一行状态，1表示选，0表示不选 */ 
	if(deep>n){
		cnt++;
		r[cnt].kind=k;
		r[cnt].sum=sum;
		return;
	}
	dfs(h,deep+1,k,sum);
	/*这一列不选,deep直接+1 */
	dfs(h,deep+2,(1<<(deep-1))|k,sum+a[h][deep]);
	/* 这一列选，并跳过一列，所以deep+2 
	   这一列选 k的第deep位为1 
	   1<<deep-1|k 相当于将1加到k前面
	   如：deep=3 k=11 1<<deep-1=100 100|k=111 
	   注意：每一个情况是倒过来的
	   如110 75 21 10 选的是21，10 
	*/
} 
int main(){
    while(cin>>n){
    	memset(r,0,sizeof(r));
    	memset(front_r,0,sizeof(front_r));
    	memset(dp,0,sizeof(dp));
    	cnt=0;
    	ans=0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++) a[i][j]=read();
		}
		for(int i=1;i<=n;i++){
			cnt=0;
			dfs(i,1,0,0); 
			for(int j=1;j<=cnt;j++){
				for(int t=1;t<=front_cnt;t++){
					if((r[j].kind&front_r[t].kind)==0) dp[i][j]=max(dp[i][j],front_r[t].sum);
				}
				dp[i][j]+=r[j].sum;
				r[j].sum=dp[i][j];
			}	
			front_cnt=cnt;		
			for(int j=1;j<=cnt;j++){
				front_r[j].kind=r[j].kind;
				front_r[j].sum=r[j].sum;
			}
		}
		for(int i=1;i<=cnt;i++) ans=max(ans,dp[n][i]);
		//debug();
		cout<<ans<<endl;
	}
}
/*
压缩：用20位的二进制数（小于整型32位）表示每一行状态，1表示选，0表示不选  
子状态：dp[i][j]代表第0~i行，并且第i行的第j个状态得到的最大和 
状态转移方程dp[i][j]=max(dp[i][j],dp[i-1][t]) 其中dp[i][j].k&dp[i-1][t].k==0（为了不相邻）,并且t为i-1行的每个状态 
*/
