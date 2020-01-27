#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 55
#define maxx 205
#define INF 10000000
using namespace std;
int a[maxn],b[maxn];
int dp[maxn][maxx];
int t,n,X,Y;
void get_dp(int t){
	memset(dp,-0x3f,sizeof(dp));
	for(int i=0;i<=X;i++){
		if(a[1]*i>t) break;
		dp[1][i]=(t-a[1]*i)/b[1]; 
	} 
	for(int i=2;i<=n;i++){
		for(int j=0;j<=X;j++){
			for(int k=0;k<=j;k++){
				if((j-k)*a[i]>t) continue;
				dp[i][j]=max(dp[i][j],dp[i-1][k]+(t-(j-k)*a[i])/b[i]);
			}
		}
	}
}
int main(){
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d %d %d",&n,&X,&Y);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a[i],&b[i]);
		} 
		int l=0,r=a[n]*X+b[n]*Y;
        int ans=0; 
		while(l<=r){
			int mid=(l+r)>>1;
			get_dp(mid);
			if(dp[n][X]>=Y){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			} 
		}
		printf("Case %d: %d\n",cas,ans);
	}
	
} 
/*
1
2 2 2
1 1
10 10
*/
