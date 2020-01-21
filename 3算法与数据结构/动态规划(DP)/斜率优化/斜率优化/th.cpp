#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100100
#define M 111

using namespace std;

long long s[N],a[N],q[N],dp[M][N];
int h,t,n,m,p,i,j,d[N];
long long x;

double getdp(int k)
{
	return dp[i-1][k]+a[j]*(j-k)-s[j]+s[k];
}

long long Y(int k)
{
	return dp[i-1][k]+s[k];
}

long long X(int x)
{
	return x;
}

bool judge(int l,int k,int j)							//如果满足条件，则k比l更优
{
	return (Y(k)-Y(l))<=(X(k)-X(l))*a[j];
}

bool maintain(int k,int i,int j)
{
	return (Y(k)-Y(i))*(X(j)-X(k))>=(Y(j)-Y(k))*(X(k)-X(i));		//取三个点维护单调性
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	if (p>=m)
    {
        puts("0\n");
        return 0;
    }
	for(int i=2;i<=n;i++)
	{
        scanf("%d",&d[i]);
        d[i]+=d[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=(long long)y-d[x];
//		printf("%I64d ",a[i]);
	}
	for(int i=1;i<=m;i++) printf("%I64d ",a[i]);
	printf("\n");
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)
        s[i]=s[i-1]+a[i];
	for(int i=1;i<=m;i++) dp[0][i]=(long long)1e18;
	for(i=1;i<=p;i++)
	{
		h=t=0; q[0]=0;
		for(j=0;j<=m;j++)
		{
			while (h<t && judge(q[h],q[h+1],j)) h++;				//如果h+1比h更优，则继续往后找更优的
			dp[i][j]=getdp(q[h]);
			while (h<t && maintain(q[t],q[t-1],j)) t--;				//维护单调性
			q[++t]=j;
			printf("dp[%d][%d]=%I64d\n",i,j,dp[i][j]); 
		}
	}
	printf("%I64d\n",dp[p][m]);
	return 0;
}



