#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f,maxn=200005;
int n,m,a[maxn],dp[21][1<<20];
char s[21];
int pre(int S,int i) {
	return S>>(m-i);
}
int suf(int S,int i) {
	return S&((1<<i)-1);
}
int deal(int S,int T) {
	for(int i=m; i; i-- )
		if(suf(S,i)==pre(T,i))return i;
	return 0;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%s",s);
		m=strlen(s);
		for(int j=0; j<m; j++)a[i]=2*a[i]+s[j]-'0';
	}
	int res=0;
	memset(dp,INF,sizeof(dp));
	dp[0][0]=m;
	for(int i=2; i<=n; i++) {
		int l=m-deal(a[i-1],a[i]);
		res+=l;
		int mn=INF;
		for(int j=0; j<=m; j++)mn=min(mn,dp[j][pre(a[i],j)]+m-j-l);
//另一个序列的末尾接上a[i],a[i-1]变成另一个序列末尾
		for(int j=0; j<=m; j++)dp[j][suf(a[i-1],j)]=min(dp[j][suf(a[i-1],j)],mn);
	}
	printf("%d\n",dp[0][0]+res);
	return 0;
}
