#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 40005
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign; 
}
inline void qread(long long &x){
	x=0;
	long long sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign; 
}

int n,m;
long long a[maxn];
inline void update(int i,long long v){
	a[i]=v;
}
long long dp[maxn][2];
inline long long query(){
//	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=dp[i-1][0]+a[i];
	}
	return max(dp[n][0],dp[n][1]);
}
int main(){
	int x;
	long long y;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
	}
	long long ans=0,now=0;
	for(int i=1;i<=m;i++){
		qread(x);
		qread(y);
		update(x,y);
		now=query();
		ans+=now;
		printf("%d: %d\n",i,now);
	}
	printf("%lld\n",ans);
}
