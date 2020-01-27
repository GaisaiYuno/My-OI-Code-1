#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 500
using namespace std;
char x[maxn+5],y[maxn+5],z[maxn+5];
int dp[2][maxn+5][maxn+5];
int lenx,leny,lenz;
int main(){
	scanf("%s",x+1);
	scanf("%s",y+1);
	scanf("%s",z+1);
	lenx=strlen(x+1);
	leny=strlen(y+1);
	lenz=strlen(z+1); 
	int now=0;
	for(int i=1;i<=lenx;i++){
		memset(dp[now],0,sizeof(dp[now]));
		for(int j=1;j<=leny;j++){
			for(int k=0;k<=lenz;k++){//记得从0开始，因为有不包含的情况 
				dp[now][j][k]=max(dp[now][j][k],max(dp[now^1][j][k],dp[now][j-1][k]));
				if(x[i]==y[j]){
					//因为必须要整个包含，所以要判前一个状态合不合法 
					if(k>0&&x[i]==z[k]&&(k==1||dp[now^1][j-1][k-1])) dp[now][j][k]=max(dp[now][j][k],dp[now^1][j-1][k-1]+1); 
					else if(k==0||dp[now^1][j-1][k]) dp[now][j][k]=max(dp[now][j][k],dp[now^1][j-1][k]+1); 
				}
			} 
		} 
		now^=1;
	}
	if(dp[now^1][leny][lenz]) printf("%d\n",dp[now^1][leny][lenz]);
	else printf("NO SOLUTION\n"); 
}

