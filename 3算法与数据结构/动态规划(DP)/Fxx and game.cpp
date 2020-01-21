//HDU 5945
//无优化O(nx) 
#include<iostream>
#include<cstring>
#define maxn 1000020
using namespace std;
int c,x,k,t;
int dp[maxn];
int main() {
	cin>>c;
	while(c--) {
		cin>>x>>k>>t;
		memset(dp,0x7f,sizeof(dp));
		dp[1]=0;
		int ans=0;
		if(t==0) { //特判
			while(x!=1) {
				x/=k;
				ans++;
			}
		}else if(k==0) {
			if((x-1)%t==0) ans=(x-1)/t;
			else ans=(x-1)/t+1;
		} else {
			for(int i=2; i<=x; i++) {
				if(i%k==0) dp[i]=min(dp[i],dp[i/k]+1);
				else {
					for(int j=1; j<=t; j++) {
						dp[i]=min(dp[i],dp[i-j]+1);
					}
				}
			}
			ans=dp[x];
		}
		cout<<ans<<endl;
	}
}
//dp[i]=min(min(dp[i-t]~dp[i-1])+1,dp[i/k]+1)
