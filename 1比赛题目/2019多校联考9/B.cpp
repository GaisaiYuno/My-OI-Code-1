#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define maxn 200000
#define maxm 20
#define INF 0x3f3f3f3f
using namespace std;
int n,m;

inline void bin_read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int len=0;
	while(c>='0'&&c<='9'){
		x=x*2+c-'0';
		c=getchar();
		len++;
	}
	m=max(m,len);
}
inline int pre(int x,int len){
	return x>>(m-len);
}
inline int suf(int x,int len){
	return x&((1<<len)-1);
}
inline int calc(int x,int y){
	int ans=0;
	for(int i=1;i<=m;i++){
		if(suf(x,i)==pre(y,i)) ans=i;
		//不单调,不能break 
//		else ans=i;
	}
	return ans;
//	for(int i=m;i>0;i--) if(suf(x,i)==pre(y,i)) return i;
//	return 0;
}

int a[maxn+5];
int dp[maxm+5][(1<<maxm)+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) bin_read(a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=m;
	int sum=0;
	for(int i=2;i<=n;i++){
		int tmp=m-calc(a[i-1],a[i]);
		sum+=tmp;
		int minv=INF;
		for(int j=0;j<=m;j++){
			minv=min(minv,dp[j][pre(a[i],j)]+m-j-tmp);
		} 
		for(int j=0;j<=m;j++){
			dp[j][suf(a[i-1],j)]=min(dp[j][suf(a[i-1],j)],minv);
		} 
		
	}
	printf("%d\n",dp[0][0]+sum);
}

