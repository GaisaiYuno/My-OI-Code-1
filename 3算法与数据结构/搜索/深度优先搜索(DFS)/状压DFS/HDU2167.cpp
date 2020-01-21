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
bool judge(int a,int b){
	if(a&b) return false;
	if(a<<1&b) return false;
	if(a>>1&b) return false;
	return true;
}
void dfs(int h,int deep,int k,int sum){//行 列 每一行的情况  和 
	if(deep>n){
		cnt++;
		r[cnt].kind=k;
		r[cnt].sum=sum;
		return;
	}
	dfs(h,deep+1,k,sum);
	dfs(h,deep+2,(1<<(deep-1))|k,sum+a[h][deep]);
} 
int main(){
	char c;
    while(1){
    	memset(r,0,sizeof(r));
    	memset(front_r,0,sizeof(front_r));
    	memset(dp,0,sizeof(dp));
    	cnt=0;
    	ans=0;
    	n=16;
    	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(scanf("%d%c",&a[i][j],&c)!=2) return 0;
				//printf("%d %d\n",i,j);
			    if(c=='\n') {
			    	n=j;
			    	break; 
				}	 
			}
		}
		for(int i=1;i<=n;i++){
			cnt=0;
			dfs(i,1,0,0); 
			for(int j=1;j<=cnt;j++){
				for(int t=1;t<=front_cnt;t++){
					if(judge(r[j].kind,front_r[t].kind)) dp[i][j]=max(dp[i][j],front_r[t].sum);
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
		cout<<ans<<endl;
	}
}
/*
71 24 95 56 54
85 50 74 94 28
92 96 23 71 10
23 61 31 30 46
64 33 32 95 89
*/
