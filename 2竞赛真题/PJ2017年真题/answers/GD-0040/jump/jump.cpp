#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d,k,s[500005],w[500005],sum=0,maxs=-1,a=0,score=0,dp[500005],l,r,mid;
int dfs(int block){
	int maxn=0;
	if(dp[block]!=0)return dp[block];
	for(int i=block+1;i<n;i++){
		if(s[i]-s[block]>a+d)break;
		if(s[i]-s[block]>=d-a)maxn=max(maxn,dfs(i));
	}
	return w[block]+maxn;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d",&s[i],&w[i]);
		if(w[i]>=0)sum+=w[i];
	}
	if(sum<k){
		printf("-1");
		return 0;
	}
	l=0; r=s[n-1]-d;
	if(r<0)r*=-1;
	while(1){
		memset(dp,0,sizeof(dp));
		if(dfs(0)>=k)break;
		a++;
	}
	printf("%d",a);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
