//http://119.29.55.79/contest/86/problem/2
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100 
#define maxsuma 1000
using namespace std;
typedef long long ll;
int n,W;
int a[maxn+5],b[maxn+5],w[maxn+5],v[maxn+5];
ll dp[maxn+5][maxsuma+5];
int maxb=0; 
void split(int &a,int &b,int x){
	for(int i=0;i<=30;i++){
		if(x&(1<<i)){
			a=x/(1<<i);
			b=i;
			break; 
		}
	}
}
int main(){
	int wgh,val;
	while(scanf("%d %d",&n,&W)!=EOF){
		if(n==-1&&W==-1) break;
		memset(dp,0,sizeof(dp));
		ll ans=0;
		maxb=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&wgh,&val);
			split(a[i],b[i],wgh);
			for(int j=min(maxsuma,W>>b[i]);j>=a[i];j--){
				dp[b[i]][j]=max(dp[b[i]][j],dp[b[i]][j-a[i]]+val);
				ans=max(ans,dp[b[i]][j]);
			}
			v[i]=val;
			maxb=max(maxb,b[i]);
			
		}
		for(int i=1;i<=maxb&&(1<<i)<=W;i++){
			for(int j=min(maxsuma,W>>i);j>=0;j--){
				for(int k=j;k>=0;k--){
					int x=2*(j-k)+((W>>(i-1)&1));
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[i-1][min(x,maxsuma)]);
				}
				ans=max(ans,dp[i][j]);
			}
		}
#ifdef DEBUG
		printf("ans=");
#endif
		printf("%lld\n",ans);
	}
}
