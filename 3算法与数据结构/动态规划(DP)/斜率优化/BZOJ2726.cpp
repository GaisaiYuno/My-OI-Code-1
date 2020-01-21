#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 300000 
using namespace std;
int n,s;
int t[maxn+5],c[maxn+5];
long long sumt[maxn+5],sumc[maxn+5];
//dp[i]=min(dp[j]+sumt[i]*(sumc[i]-sumc[j])+s*(sumc[n]-sumc[j])
//化成dp[j]=(s+sumt[i])*sumc[j]+dp[i]-sumt[i]*sumc[i]-s*sumc[n]
//斜率s+sumt[i],点(sumc[j],dp[j]) 
long long dp[maxn+5];

int head=1,tail=1;//这样写边界不容易错 
int q[maxn*2+5];
int bin_search(int k){
	if(head==tail) return head;
	int ans=tail;
	int l=head,r=tail;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(dp[q[mid+1]]-dp[q[mid]]<=k*(sumc[q[mid+1]]-sumc[q[mid]])){
			l=mid+1;
		}else{
			ans=mid;//找到第一个从点i到i+1直线斜率比k大的点i 
			r=mid-1;
		}
	}
	return ans;
}


int main(){
	scanf("%d %d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&t[i],&c[i]);
		sumt[i]=sumt[i-1]+t[i];
		sumc[i]=sumc[i-1]+c[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	q[head]=0;
	for(int i=1;i<=n;i++){
		int p=bin_search(s+sumt[i]);
		
		dp[i]=dp[q[p]]-(s+sumt[i])*sumc[q[p]]+sumt[i]*sumc[i]+s*sumc[n];
		
		while(head<tail&&(dp[q[tail]]-dp[q[tail-1]])*(sumc[i]-sumc[q[tail]])
							>=(dp[i]-dp[q[tail]])*(sumc[q[tail]]-sumc[q[tail-1]])) tail--;
		//tail->tail-1斜率>=i->tail斜率时出队 
		q[++tail]=i;
//		printf("dp[%d]=%d head=%d\n",i,dp[i],p);
	}
	printf("%lld\n",dp[n]);
}


