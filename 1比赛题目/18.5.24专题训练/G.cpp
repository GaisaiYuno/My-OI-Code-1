#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 205
using namespace std;
char s1[maxn],s2[maxn],s3[maxn*2];
int dp[maxn][maxn];
int len1,len2,len3,t;
int main(){
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		memset(dp,0,sizeof(dp));
//		scanf("%s %s %s",s1+1,s2+1,s3+1);
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		scanf("%s",s3+1);
		len1=strlen(s1+1);
		len2=strlen(s2+1);
		len3=strlen(s3+1);
		for(int i=1;i<=len1;i++){
			if(s1[i]==s3[i]) dp[i][0]=1;
			else break;
		}
		for(int i=1;i<=len2;i++){
			if(s2[i]==s3[i]) dp[0][i]=1;
			else break;
		}
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(s1[i]==s3[i+j]&&dp[i-1][j]==1) dp[i][j]=1; 
				if(s2[j]==s3[i+j]&&dp[i][j-1]==1) dp[i][j]=1; 
			} 
		}
		printf("Data set %d: ",cas);
		if(dp[len1][len2]==1) printf("yes\n");
		else printf("no\n");
	} 
}
