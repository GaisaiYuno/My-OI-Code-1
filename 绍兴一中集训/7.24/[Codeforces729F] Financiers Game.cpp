#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<unordered_map>
#define maxn 4000
#define maxk 100
#define maxhash 30000000
#define mod 13131313
using namespace std;
typedef long long ll;
int n;
int a[maxn+5];
ll sum[maxn+5],dp[maxhash+5];
inline ll get_sum(int l,int r){
	return sum[r]-sum[l-1];
}
inline int get_hash(int l,int r,int k,int type){
	return (((1ll*l*maxn+r)*maxk+k)*2+type)%mod;
}

ll dfs(int l,int r,int k,int type){
	if(r-l+1<k) return 0;
	if(r-l+1==k){
		if(type==1) return -get_sum(l,r);
		else return get_sum(l,r); 
	}
	int hs=get_hash(l,r,k,type);
	if(dp[hs]!=-1) return dp[hs];
	if(type==0){
		ll s1,s2;
		s1=dfs(l+k,r,k,1)+get_sum(l,l+k-1);//第1个人取k个 
		if(l+k<=r) s2=dfs(l+k+1,r,k+1,1)+get_sum(l,l+k);//第1个人取k+1个 
		dp[hs]=max(s1,s2);
	}else{
		ll s1,s2;
		s1=dfs(l,r-k,k,0)-get_sum(r-k+1,r);//第2个人取k个
		if(l+k<=r) s2=dfs(l,r-k-1,k+1,0)-get_sum(r-k,r);//第2个人取k+1个
		dp[hs]=min(s1,s2); 
	} 
	return dp[hs];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	} 
	memset(dp,-1,sizeof(dp));
	printf("%I64d\n",dfs(1,n,1,0));
}

