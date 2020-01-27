#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h> 
#include <math.h>
using namespace std;

string num[16];
long double px[16],py[16];

long double gain[16][16];
long double dp[65536][16];
int lcs[1001][1001];

long double pow2(long double x)
{
	return x*x;
}
//用LCS获得两给数字的相似度 
int getsim(string,string);

int main()
{
	freopen("bug.in","r",stdin);
	freopen("bug.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>num[i]>>px[i]>>py[i];
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i==j)continue;
			gain[i][j]=getsim(num[i],num[j])/sqrtl(pow2(px[i]-px[j])+pow2(py[i]-py[j])); 
		}
	}
	for(int i=0;i<65536;++i)
	{
		for(int j=0;j<16;++j)
		{
			dp[i][j]=1e100;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<(1<<n);++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				if(j==k) continue;
				if(i&(1<<k))
				{
					dp[i][k]=min(dp[i][k],dp[i&~(1<<k)][j]+gain[j][k]);
				}
			}
		}
	}
	long double ans=dp[(1<<n)-1][0];
	for(int i=1;i<n;++i)
	{
		ans=min(ans,dp[(1<<n)-1][i]+gain[i][0]);
	}
	printf("%.10Lf",ans);
	return 0;
}

int table[6][6]=
{
	{-100,-1,-2,-8,-16,-32},
	{-1,6,-2,-4,-1,-2},
	{-2,-2,7,2,3,-7},
	{-8,-4,2,8,1,5},
	{-16,-1,3,1,9,2},
	{-32,-2,-7,5,2,15}
};

int getsim(string s1,string s2)
{
	int len1=s1.length(),len2=s2.length();
	s1=" "+s1,s2=" "+s2;
	memset(lcs,0xB0,sizeof(lcs));
	lcs[0][0]=0;
	//第一次dp的关键在初始化 
	for(int i=1;i<=len1;++i)
	{
		lcs[i][0]=lcs[i-1][0]+table[0][s1[i]-48];
	}
	for(int j=1;j<=len2;++j)
	{
		lcs[0][j]=lcs[0][j-1]+table[s2[j]-48][0];
	}
	for(int i=1;i<=len1;++i)
	{
		for(int j=1;j<=len2;++j)
		{
			lcs[i][j]=max(max(lcs[i-1][j]+table[s1[i]-48][0],
			lcs[i][j-1]+table[0][s2[j]-48]),
			lcs[i-1][j-1]+table[s1[i]-48][s2[j]-48]);
		}
	}
	return max(0,lcs[len1][len2]);
}
