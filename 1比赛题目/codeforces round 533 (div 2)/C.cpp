/*
[El Psy Congroo]
For Selina

Problem:C
Source:Codeforces round 533 (div 2)
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
#define mod 1000000007
using namespace std;
int n;
long long l,r;
long long cnt0,cnt1,cnt2;
long long dp[maxn][3];
int solve(int x,int k){
	int t;
	if(x%3==0) t=3;
	else t=x%3;
	return (x-t)/3+(x%3==k);
}
int main(){
	scanf("%d %I64d %I64d",&n,&l,&r);
	int l1,l2,l3;
	l1=l%3;
	l2=(r+1-l);
	l3=l2%3;
	l2=l2/3;
	cnt1=cnt2=cnt0=l2;
	if(l3==1){
		if(l1==1) cnt1++;
		else if(l1==2) cnt2++;
		else cnt0++;
	}
	if(l3==2){
		cnt1++,cnt2++,cnt0++;
		if(l1==1) cnt0--;
		else if(l1==2) cnt1--;
		else cnt2--;
	}
	dp[1][0]=cnt0;
	dp[1][1]=cnt1;
	dp[1][2]=cnt2;
	for(int i=2;i<=n;i++){
		dp[i][0]=(dp[i-1][0]*cnt0%mod+dp[i-1][1]*cnt2%mod+dp[i-1][2]*cnt1)%mod;
		dp[i][1]=(dp[i-1][1]*cnt0%mod+dp[i-1][2]*cnt2%mod+dp[i-1][0]*cnt1)%mod;
		dp[i][2]=(dp[i-1][2]*cnt0%mod+dp[i-1][0]*cnt2%mod+dp[i-1][1]*cnt1)%mod;
	}
	printf("%I64d\n",dp[n][0]);
}

