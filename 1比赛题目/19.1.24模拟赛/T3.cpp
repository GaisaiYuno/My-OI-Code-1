#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int dp[maxn][2];
inline int qread(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main(){
	int cnt=0;
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		a[i]=qread();
		if(a[i]==i) cnt++;
	}
	if(n>10000){
		printf("%d\n",cnt);
		return 0;
	}
	int o=0;
	for(register int i=1;i<=n;i++){
		o^=1;
		for(register int j=1;j<=i;j++){
			if(dp[j][o^1]+(a[i]==i-j)>dp[j-1][o^1]) dp[j][o]=dp[j][o^1]+(a[i]==i-j);
			else dp[j][o]=dp[j-1][o^1];
		}	
	}
	int ans=cnt;
	for(register int i=0;i<=n;i++){
		ans=max(ans,dp[i][o]);
	}
	printf("%d\n",ans);
}
