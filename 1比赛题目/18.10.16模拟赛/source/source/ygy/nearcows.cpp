#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n,k;
int dp[100005][25];//zishu
vector<int>road[100005];
int ans[100005];
int arr[100005];
int par[100005];
void dfs(int x,int p){
	par[x]=p;
	for(int i=0;i<=k;i++)
		dp[x][i]=arr[x];
	for(int i=0;i<road[x].size();i++){
		if(road[x][i]==p)continue;
		dfs(road[x][i],x);
		for(int u=1;u<=k;u++){
			dp[x][u]+=dp[road[x][i]][u-1];
		}
	}
}
inline char gc(){
	static char bb[1000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,1000000,stdin),s==t)?EOF:*s++;
}
inline int read(){
	register int x=0;register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+ch-48,ch=gc();
	return x;
}
void write(int x){
	if(x>=10)write(x/10);
	putchar(x%10+48);
}
int main(){
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<n;i++){
		int x,y;
		x=read(),y=read();
		road[x].push_back(y);
		road[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		arr[i]=read();
	dfs(1,0);
	for(int i=1;i<=n;i++){
		ans[i]=dp[i][k];
		int son=i;
		int cnt=0;
		while(par[son]!=0&&cnt!=k){
			ans[i]+=dp[par[son]][k-cnt-1];
			if(cnt!=k-1)ans[i]-=dp[son][k-cnt-2];
			son=par[son];cnt++;
		}
	}
	for(int i=1;i<=n;i++)
		write(ans[i]),putchar('\n');
}
