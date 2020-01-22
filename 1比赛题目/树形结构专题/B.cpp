#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 55
using namespace std;
int n;
char a[maxn];
int dp[maxn][maxn][2];//区间[l,r]内，1/0是否有M，长度 
int is_div(int l,int r){
	int mid=(l+r)/2;
	for(int i=0;i<mid-l+1;i++){
		if(a[l+i]!=a[mid+i+1]) return 0;
	}
	return 1;
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
//	printf("%d\n",n);
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			dp[i][j][0]=dp[i][j][1]=j-i+1;
			for(int k=i;k<j;k++) dp[i][j][0]=min(dp[i][j][0],dp[i][k][0]+j-k);//直接加
			for(int k=i;k<j;k++) dp[i][j][1]=min(dp[i][j][1],min(dp[i][k][0],dp[i][k][1])+1+min(dp[k+1][j][0],dp[k+1][j][1]));//放M ,枚举M放的位置k 
			if((j-i+1)%2==0&&is_div(i,j)) dp[i][j][0]=dp[i][(i+j)/2][0]+1;//可分为相等两半，中间放R 
		}
	}
	printf("%d\n",min(dp[1][n][0],dp[1][n][1]));
}

