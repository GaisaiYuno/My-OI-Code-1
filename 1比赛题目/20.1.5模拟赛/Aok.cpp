#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cctype>
#include<queue>
#define maxn 26
#define maxl 100000
#define mod 10000

using namespace std;
int n,s;


inline bool isAlpha(char c){
	return c>='A'&&c<='Z';
}
void get_nex(char *s,int n,int *nex) {
	nex[1]=0;
	for(int i=2,j=0; i<=n; i++) {
		while(j&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	}
}

int a[maxn+5][maxl+5];
int len[maxn+5];
char tp[maxn+5],lentp;
int nex[maxl+5];

int dp[maxn+5][maxl+5];
//dp[i][j]表示字符串i,当前还未匹配时末尾已经与模板串匹配了j位,
//记录j是处理跨过两个字符串的匹配 
//串i里包含模板串的个数 
int pos[maxn+5][maxl+5];//pos[i][j]表示匹配结束后KMP指针的位置 
int dfs(int i,int j){
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]=0;
	int x=j;
	for(int k=1;k<=len[i];k++){
		if(isAlpha(a[i][k])){
			int id=a[i][k]-'A'+1;
			dp[i][j]+=dfs(id,x);
			dp[i][j]%=mod;
			x=pos[id][x]; 
		}else{
			int p=x;
			while(p&&tp[p+1]!=a[i][k]) p=nex[p];
			if(tp[p+1]==a[i][k]) p++;
			x=p;
			if(x==lentp){
				dp[i][j]++;
				dp[i][j]%=mod;
			} 
		}
	}
	pos[i][j]=x;
	return dp[i][j];
}

char in[maxl+5];
int main() {
	scanf("%d",&n);
	scanf("%s",in+1);
	s=in[1]-'A'+1;
	for(int i=1; i<=n; i++) {
		scanf("%s",in+1);
		int l=strlen(in+1);
		for(int j=3; j<=l; j++) a[in[1]-'A'+1][j-2]=in[j];
		len[i]=l-2;
	}
	scanf("%s",tp+1);
	lentp=strlen(tp+1); 
	get_nex(tp,lentp,nex);
	memset(dp,0xff,sizeof(dp));
	dfs(s,0); 
	printf("%d\n",dp[s][0]);
}

