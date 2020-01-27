//For my love Selina
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn],b[maxn];
namespace baoli {//O(n^2)±©Á¦
	int dp[5005][5005];
	int solve() {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dp[i][j]=max(dp[i][j],dp[i][j-1]);
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if(abs(a[i]-b[j])<=4)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
		return dp[n][n];
	}
}

namespace luangao {//O(nlogn)ÂÒ¸ã
	int pos[maxn];
	int c[maxn*8];
	int s[maxn*8];
	int m;
	int cmp(int x,int y){
		return x>y;
	}
	int solve() {
		for(int i=1; i<=n; i++) {
			int t=m+1;
			for(int j=1; j<=4; j++) {
				if(b[i]+j<=n) c[++m]=pos[b[i]+j];
				if(b[i]-j>=1) c[++m]=pos[b[i]-j];
			}
			sort(c+t+1,c+m+1,cmp);
		}
		int top=0;
		for(int i=1; i<=m; i++) {
			if(c[i]>s[top]) {
				s[++top]=c[i];
			} else {
				int tmp=lower_bound(s+1,s+1+top,c[i])-s;
				s[tmp]=c[i];
			}
		}
		return top;
	}
}
int main() {
	freopen("nocross.in","r",stdin);
	freopen("nocross.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
	}
//	printf("%.3f\n",1.0*(sizeof(a)+sizeof(b)+sizeof(baoli::dp))/1024/1024);
	if(n<=10000){
		printf("%d\n",baoli::solve());
	}else{
		printf("%d\n",luangao::solve());
	}
}
