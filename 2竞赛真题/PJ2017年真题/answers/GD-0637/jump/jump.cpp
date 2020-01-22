
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int f[50005]; int b[50005]; int c[100001];
int n,h,d,sum;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&h);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		scanf("%d",&c[b[i]]);
		sum+=c[b[i]];
	}
	if (sum<h) 
	{
		cout<<"-1";
		return 0;
	}
	for (int i=1;i<n;i++)
		for (int j=1;j<=n;j++)
		{
			if (!b[j]) continue;
			if (j+i<=n) 
			{
				for (int k=j;k<=j+i;k++)
				{
					{
						{if (b[k]==0) continue;}
						f[j]=max(f[j],f[k]+c[j]);
						{
						if (f[j]>h) 
							{
							cout<<i;
							return 0;
							}
						}
					}
				} 
			}
			else 
			{
				for (int k=j;k<=n;k++)
				{
					{
						{if (b[k]==0) continue;}
						f[j]=max(f[j],f[k]+c[j]);
						{
						if (f[j]>h) 
							{
							cout<<i;
							return 0;
							}
						}
					}
				} 
			}
			
		}
		cout<<"-1";
		fclose(stdin);
		fclose(stdout);
		return 0;
}
