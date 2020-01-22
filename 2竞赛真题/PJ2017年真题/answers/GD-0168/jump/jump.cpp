#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
#define ll long long
#define in(a) scanf("%d",&a)
#define out(a) printf("%d\n",a);
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define maxn 500010
int x[maxn],s[maxn];
int n,d;
int dp[maxn];
int check(int a){
	memset(dp,-127,sizeof(dp));
	dp[0]=0;
	int ans=0;
	FOR(i,1,n){
		for(int j=i-1;j>=0;j--){
			if(x[j]<x[i]-d-a)break;
			 else {
			 	if(x[j]<=x[i]-d+a)dp[i]=max(dp[i],dp[j]+s[i]);
			 }
		}
		ans=max(ans,dp[i]);
	}
	return ans;
}
int main(){ 
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int k;
	in(n);in(d);in(k);
	int sum=0;
	x[0]=0;
	FOR(i,1,n){
		in(x[i]),in(s[i]);
		if(s[i]>0)sum+=s[i];
	}
	if(sum<k){
		out(-1);
		return 0;
	}
	int l=0,r=1000000001;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)>=k)r=mid;
		 else l=mid;
	}
	out(r);
	fclose(stdin);fclose(stdout);
	return 0;
}
