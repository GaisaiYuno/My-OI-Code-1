#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500000
#define maxs 1000000
using namespace std;

int S,n,m;
int a[maxn+5];
namespace brute_force{
//	int sum=0;
//	int b[maxn+5];
//	int vis[maxn+5];
//	int dp[2][maxs+5];
//	int last[maxs+5];
//	void solve(){
//		for(int i=1;i<=n;i++){
//			sum+=a[i];
//			vis[a[i]]=1;
//		}
//		sum-=n;
//		for(int i=1;i<=S;i++){
//			if(!vis[i]) b[++m]=S-i;
//		}
//		sort(b+1,b+1+m);
//		
//		int now=0;
//		memset(dp,0x3f,sizeof(dp));
//		dp[1][0]=1;
//		for(int i=1;i<=m;i++){
//			for(int j=sum;j-b[i]>=0;j--){
//				if(dp[now^1][j-b[i]]+1<=dp[now][j]&&dp[now^1][j-b[i]]!=0){
//					dp[now][j]=dp[now^1][j-b[i]]+1;
//					last[j]=i;
//				}
//			}
//			now^=1;
//		}
//		printf("%d\n",dp[now][sum]);
//	}
}

namespace test{
	int ans[maxn+5];
	int vis[maxs+5];
	void solve(){
		for(int i=1;i<=n;i++){
			vis[a[i]-1]=1;
		}
		int m=0;
		for(int i=1;i<=n;i++){
			if(!vis[S-a[i]+1]){
				ans[++m]=S-a[i]+1;
			}
		}
		if(m!=n) printf("0\n");
		else{
			printf("%d\n",m);
			for(int i=1;i<=m;i++){
				printf("%d ",ans[i]);
			}
		}
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d %d",&S,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	test::solve();
	return 0;
}
