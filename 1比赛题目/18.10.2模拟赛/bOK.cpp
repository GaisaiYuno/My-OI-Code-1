#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define mod 1000000007
using namespace std;
typedef long long ll;
char t1[maxn],t2[maxn];
ll x[maxn],y[maxn];
ll dp[maxn][maxn];
ll count(ll *a,ll n,ll last,bool is_edge){
	if(n==0) return 1;
	if(!is_edge&&dp[n][last]!=0) return dp[n][last];
	ll maxv=9;
	ll ans=0;
	if(is_edge) maxv=a[n];
	for(int i=last; i<=maxv; i++) {
		bool flag=false;
		if(i==a[n]&&is_edge) flag=true;
		ans+=count(a,n-1,i,flag);
		ans%=mod;
	}
	if(!is_edge) dp[n][last]=ans;
	return ans;
}

int check(char *a,int len) {
	for(int i=1; i<len; i++) {
		if(a[i]>a[i+1]) return 0;
	}
	return 1;
}
int main(){
//	memset(dp,0,sizeof(dp));
	scanf("%s",t1);
	int len1=strlen(t1);
	scanf("%s",t2);
	int len2=strlen(t2);
	for(int i=len1-1; i>=0;i--) {
		x[i+1]=t1[len1-i-1]-'0';
	}
	for(int i=len2-1; i>=0;i--) {
		y[i+1]=t2[len2-i-1]-'0';
	}
	long long ans=(count(y,len2,0,1)-count(x,len1,0,1)+mod)%mod+check(t1,len1);
	ans%=mod;
	printf("%lld\n",ans);
}
