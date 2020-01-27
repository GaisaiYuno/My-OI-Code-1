#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxk 20
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
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];
int dp[maxn+5][maxk+5][2];//dp[i][j][0/1],前i个数分j段最大和，0/1表示i不选/选 
int solve(int l,int r,int k){
	for(int i=l-1;i<=r;i++){
		for(int j=0;j<=k;j++) dp[i][j][0]=dp[i][j][1]=0;
	}
	for(int i=l;i<=r;i++){
		for(int j=1;j<=k;j++){
			dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0]);
			dp[i][j][1]=max(dp[i-1][j][1]+a[i],dp[i][j][1]);
			dp[i][j][1]=max(dp[i-1][j-1][0]+a[i],dp[i][j][1]);
			dp[i][j][1]=max(dp[i-1][j-1][1]+a[i],dp[i][j][1]);
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++){
		ans=max(ans,max(dp[r][i][0],dp[r][i][1])); 
	}

	return ans;
}
int main(){
#ifndef LOCAL
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
#endif
	int op,x,val,l,r,k;
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(op);
		if(op==0){
			qread(x);
			qread(val);
			a[x]=val;
		}else{
			qread(l);
			qread(r);
			qread(k);
			qprint(solve(l,r,k));
			putchar('\n');
		} 
	}
}
