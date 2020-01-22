//大样例单调递增->最后一个数字一定会影响答案！
// 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;

namespace Solution_Nmax
{
	void read(int &x)
	{
		char ch=getchar();bool f=0;x=0;
		while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
		if(f)x=-x;
	}
	
	void read(long long &x)
	{
		char ch=getchar();bool f=0;x=0;
		while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
		if(f)x=-x;
	}
	long long sum[500001];
	long long num[500001];
	double lastans;
	int main()
	{
		int Q,n=0;
		read(Q);
		{
			while(Q--)
			{
				int type;
				read(type);
				if(type==1)
				{
					read(num[++n]);
					sum[n]=sum[n-1]+num[n];
					lastans=-1e5;
				}
				else
				{
					if(lastans>-1e4)
					{
						printf("%.10f\n",lastans);
						continue;
					}
					if(n==1)
					{
						lastans=0;
						puts("0.0000000000");
						continue;
					}
					int l=1,r=n-1;
					while(true)
					{
						if(r==l)
						{
							lastans=(double)num[n]-(double)(sum[l]+num[n])/(l+1);
							printf("%.10f\n",lastans);
							break;
						}
						if(r-l==1)
						{
							lastans=(double)num[n]-min((double)(sum[l]+num[n])/(l+1),(double)(sum[r]+num[n])/(r+1));
							printf("%.10f\n",lastans);
							break;
						}
						int mid=l+r>>1;
						double al=(double)(sum[mid-1]+num[n])/(mid),
						am=(double)(sum[mid]+num[n])/(mid+1),
						ar=(double)(sum[mid+1]+num[n])/(mid+2);
						if(am<al&&am<ar)
						{
							lastans=(double)num[n]-am;
							printf("%.10f\n",lastans);
							break;
						}
						if(al>am&&am>ar)
						{
							l=mid+1;
						}
						else
						{
							r=mid-1;
						}
					}
				}
			}
		}
/*		for(int i=1;i<=n;i++)
		{
			printf("%.10f\n",((double)sum[i]+num[n])/(i+1));
		}*/
		return 0;
	}
}

int main()
{
	freopen("nmax.in","r",stdin);
	freopen("nmax.out","w",stdout);
	return Solution_Nmax::main();
} 
/*
6 
1 3
2
1 4
2 
1 8
2
*/
