#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 17 //2^17>100000
#define maxm 11//3^11>100000
#define maxv 100005
#define mod 1000000001
using namespace std;
int n;
int a[maxn+5][maxm+5];
int b[maxn+5];
int used[maxv+5];
long long dp[maxn+5][(1<<maxm)+5];
long long work_dp(int x){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(dp,0,sizeof(dp));
	a[1][1]=x;
	for(int i=2;i<=maxn;i++){
		if(a[i-1][1]*2<=n) a[i][1]=a[i-1][1]*2;
		else a[i][1]=n+1;
	} 
	for(int i=1;i<=maxn;i++){
		for(int j=2;j<=maxm;j++){
			if(a[i][j-1]*3<=n) a[i][j]=a[i][j-1]*3;
			else a[i][j]=n+1;
		}
	}
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=maxm;j++){
			if(a[i][j]<=n){
				b[i]|=(1<<(j-1));
				used[a[i][j]]=1;
			}
		}
	}
	dp[0][0]=1;
	for(int i=0;i<=maxn;i++){
		for(int j=0;j<=b[i];j++){
			if(dp[i][j]==0) continue;
			for(int k=0;k<=b[i+1];k++){
				if((j&k)==0&&(k&(k>>1))==0){
					dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
				}
			}
		}
	}
	return dp[maxn+1][0];
}
int main(){
//	freopen("set.in","r",stdin);
//	freopen("set.out","w",stdout);
	scanf("%d",&n);
	long long ans=1;
	long long tmp=0;
	for(int i=1;i<=n;i++){
		if(!used[i]){
			tmp=work_dp(i);
//			cout<<tmp<<endl;
			ans=ans*tmp%mod;
		}
	}
	cout<<ans;
	return 0;
}
