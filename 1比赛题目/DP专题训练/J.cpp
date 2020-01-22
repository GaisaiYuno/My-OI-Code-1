#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10005
#define maxk 505
using namespace std;
int n,k,maxx;
int a[maxn];
inline int lowbit(int x) {
	return x&(-x);
}
int dp[maxn][maxk];
int query(int x,int y){
	int ans=0;
	for(int i=x;i;i-=lowbit(i)){
		for(int j=y;j;j-=lowbit(j)){
			ans=max(dp[i][j],ans);
		}
	}
	return ans; 
}
void update(int x,int y,int v){
	for(int i=x;i<=6005;i+=lowbit(i)){
		for(int j=y;j<=505;j+=lowbit(j)){
			dp[i][j]=max(dp[i][j],v);
		}
	}
}

int main() {
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	int ans=1;
	for(int i=1;i<=n;i++) {
		for(int j=k+1;j;j--) {
			int tmp=query(a[i]+j,j)+1;
			ans=max(ans,tmp);
			update(a[i]+j,j,tmp);
		}
	}
	printf("%d\n",ans);
}
