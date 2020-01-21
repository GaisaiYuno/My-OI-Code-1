#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200 
using namespace std;
int n,m,p;
char a[maxn+5],b[maxn+5],c[maxn+5];
int nex[maxn+5];
void get_nex(char *a){
	int len=strlen(a+1);
	for(int i=2,j=0;i<=len;i++){
		while(j>0&&a[j+1]!=a[i]) j=nex[j];
		if(a[j+1]==a[i]) j++;
		nex[i]=j; 
	}
} 

int dp[maxn+5][maxn+5][maxn+5];
int main(){
	scanf("%d %d %d",&n,&m,&p);
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",c+1);
	get_nex(c);
	dp[0][0][0]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<p;k++){//k为匹配到的位置 
				//刷表法 
				if(i+1<=n) dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
				if(j+1<=m) dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
				if(i+1<=n&&j+1<=m&&a[i+1]==b[j+1]){
					int h=k;
					while(h>0&&c[h+1]!=a[i+1]) h=nex[h];
					if(c[h+1]==a[i+1]) h++;
					dp[i+1][j+1][h]=max(dp[i+1][j+1][h],dp[i][j][k]+1); 
				}
			}
		}
	}
	int ans=0;
	for(int k=0;k<p;k++){
		ans=max(ans,dp[n][m][k]);
	} 
	printf("%d\n",ans);
} 
