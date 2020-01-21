## [校内OJ #482] 基因序列相似性问题(DP+KMP)

### 题面

找出给定序列X和Y带有不包含子串P约束的最长公共子序列。 

### 分析

一般的LCS问题用的是二维dp,表示X串的前i位和Y串前j位的LCS长度,这里还需要不包含P约束，可以记录第三个状态k表示当前子序列匹配了字串P的前k位

那么可以推导状态转移方程:

$dp[i][j][k]=\max(dp[i][j][k],dp[i][j-1][k],dp[i-1][j][k])$

这种情况没有在公共子序列后面添加新的字符，故k不变

若$a[i]=b[j]$,公共子序列长度可以+1

$dp[i][j][f(a[i],k)]=\max(dp[i][j][k],dp[i-1][j-1][k]+1)$

其中$f(a[i],k)$表示加入$a[i]$后的匹配位数，可以用KMP的next数组求出

### 代码

```cpp
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
```



