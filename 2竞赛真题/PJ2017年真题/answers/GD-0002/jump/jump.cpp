#include<cstdio>
#include<iostream>
using namespace std;
int n,d,s[100005],x[100005];
long long k,dp[100005];
//bool tf[100005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%lld",&n,&d,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&s[i],&x[i]);
//	for(int g=0;g<=s[n]-d;g++)
//	{
//		memset(dp,0,sizeof(dp));
//		memset(tf,0,sizeof(tf));
//		int p1=d-g,p2=d+g;
//		if(p1<1)p1=1;
//		if(p2>s[n])p2=s[n];
//		tf[0]=true;
////		printf("%d %d\n",p1,p2);
//		for(int i=0;i<=s[n];i++)
//		{
//			if(tf[i]==true)
//			{
//				for(int j=p1;j<=p2;j++)
//				{
//					if(tf[i+j]==false){dp[i+j]=dp[i]+x[s[i+j]];tf[i+j]=true;}
//					  else dp[i+j]=max(dp[i+j],dp[i]+x[s[i+j]]),
//					printf("%d %d %d\n",i+j,s[i+j],x[s[i+j]]);
//				}
//			}
//		}
////		for(int i=0;i<=s[n];i++)printf("%d ",dp[i]);
////		printf("\n");
////		for(int i=0;i<=s[n];i++)printf("%d ",tf[i]);
////		printf("\n");
//		for(int i=0;i<=s[n];i++)
//		if(dp[i]>=k)
//		{
//			printf("%d",g);
//			return 0;
//		}
//	}
	printf("-1");
	return 0;
}
