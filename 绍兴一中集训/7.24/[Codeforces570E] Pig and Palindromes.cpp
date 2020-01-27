#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500
#define mod 1000000007 
using namespace std;
typedef long long ll;
int n,m;
char a[maxn+5][maxn+5];
ll dp[2][maxn+5][maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	if(a[1][1]!=a[n][m]){
		printf("0\n");
		return 0;
	}
	int now=0;
	dp[0][1][n]=1;
	for(int i=2;i<=(n+m)/2;i++){
		now^=1;
		memset(dp[now],0,sizeof(dp[now]));
		for(int x1=1;x1<=i;x1++){
			for(int x2=n;x2>=n-i+1;x2--){
				int y1=i+1-x1;
				int y2=n+m+1-i-x2;
				if(x1<=x2&&y1<=y2&&a[x1][y1]==a[x2][y2]){
					dp[now][x1][x2]+=dp[now^1][x1][x2];
					dp[now][x1][x2]+=dp[now^1][x1-1][x2];
					dp[now][x1][x2]+=dp[now^1][x1][x2+1];
					dp[now][x1][x2]+=dp[now^1][x1-1][x2+1];
					dp[now][x1][x2]%=mod;
//					printf("step=%d x1=%d y1=%d x2=%d y2=%d dp=%d\n",i,x1,y1,x2,y2,dp[now][x1][x2]);
				}
			}
		}
		
	}
	ll ans=0;
	if((n+m-1)%2==0){//×ßÅ¼Êý²½ 
		for(int i=1;i<=n;i++){
	 		ans+=dp[now][i][i]+dp[now][i][i+1];
			ans%=mod;	
		}	
	}else{
		for(int i=1;i<=n;i++){
			ans+=dp[now][i][i];
			ans%=mod;
		}
	}
	printf("%I64d\n",ans);
}
