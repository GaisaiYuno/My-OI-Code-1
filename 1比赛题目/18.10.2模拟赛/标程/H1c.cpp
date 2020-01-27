//{f,g,g-f,-f,-g,f-g}
//pulaishi
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
const long long INF=0x3f3f3f3f3f3f3f3f;
using namespace std;

namespace SolutionP3
{
void read(int &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

void read(long long &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

long long arr[6][50001];
long long sum[6][50001];
int size[6];
int n;

long long getsum(int i,long long f)
{
//	cout<<"getsum"<<i<<" "<<f<<endl;
	int &n=size[i];
	if(n==0)return 0;
	if(n==1)return std::abs(f-arr[i][0]);
	int p=lower_bound(arr[i],arr[i]+size[i],f)-arr[i];
//	cout<<"p="<<p<<endl;
	if(p>=n)return n*f-sum[i][n-1];
	if(p<=0)return sum[i][n-1]-n*f;
	return p*f-sum[i][p-1]+sum[i][n-1]-sum[i][p-1]-(n-p)*f;
}

long long check(long long f,long long g)
{
	return getsum(0,f)+getsum(1,g)+getsum(2,g-f)
		+getsum(3,-f)+getsum(4,-g)+getsum(5,f-g);
}

int main()
{
	read(n);
	for(int i=0;i<n;i++)
	{
		int tmp=i%6;
		read(arr[tmp][size[tmp]++]);
	}
	for(int i=0;i<6;i++)
	{
		sort(arr[i],arr[i]+size[i]);
	}
/*	for(int i=0;i<6;i++)
	{
		for(int j=0;j<size[i];j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0;i<6;i++)
	{
		sum[i][0]=arr[i][0];
		for(int j=1;j<size[i];j++)
		{
			sum[i][j]=sum[i][j-1]+arr[i][j];
		}
	}
/*	long long f,g;
	while(cin>>f>>g)
	{
		cout<<getsum(f,g)<<endl;
		//cout<<check(f,g)<<endl;
	}
	return 0;*/
/*	for(long long f=-2;f<=20;f++)
	{
		for(long long g=-2;g<=20;g++)
		{
			if(f==7&&g==2)putchar('{');
		//	printf("%10lld",check(f,g));
		//	if(check(f,g)<=23563)cout<<f<<" "<<g<<endl;
		}
		cout<<endl;
	}*/
	long long l=-2e9,r=2e9,other=0;
	bool flag=false;
	while(true)
	{
		
		if(flag)
		{
			while(true)
			{
				long long mid=l+r>>1;
			//	cout<<"["<<l<<","<<r<<"]";
			//	cout<<mid<<","<<other<<endl;
				long long valm=check(mid,other);
				long long vall=check(mid-1,other);
				long long valr=check(mid+1,other);
				if(r-l==1)
				{
					long long checkl=check(l,other),checkr=check(r,other);
					if(checkl<checkr)
					{
						if(checkl<=check(l,other-1)&&checkl<=check(l,other+1))
						{
							cout<<checkl<<endl;
							return 0;
						}
						other=l;
						flag=false;
						l=-2e9,r=2e9;
						break;
					}
					else
					{
						if(checkr<=check(l,other-1)&&checkr<=check(l,other+1))
						{
							cout<<checkr<<endl;
							return 0;
						}
						other=r;
						flag=false;
						l=-2e9,r=2e9;
						break;
					}
				}
				if(valm<=vall&&valm<=valr)
				{
					if(valm<=check(mid,other+1)&&valm<=check(mid,other-1))
					{
						cout<<valm<<endl;
						return 0;
					}
					flag=false;
					l=-2e9,r=2e9;
					other=mid;
					break;
				}
				if(vall<=valm)r=mid;
				else l=mid;
			}
		}
		else
		{
			while(true)
			{
				long long mid=l+r>>1;
			//	cout<<"["<<l<<","<<r<<"]";
			//	cout<<other<<","<<mid<<endl;
				long long valm=check(other,mid);
				long long vall=check(other,mid-1);
				long long valr=check(other,mid+1);
				if(r-l==1)
				{
					long long checkl=check(other,l),checkr=check(other,r);
					if(checkl<checkr)
					{
						if(checkl<=check(other-1,l)&&checkl<=check(other+1,l))
						{
							cout<<checkl<<endl;
							return 0;
						}
						other=l;
						flag=true;
						l=-2e9,r=2e9;
						break;
					}
					else
					{
						if(checkr<=check(other-1,r)&&checkr<=check(other+1,r))
						{
							cout<<checkr<<endl;
							return 0;
						}
						other=r;
						flag=true;
						l=-2e9,r=2e9;
						break;
					}
				}
				if(valm<=vall&&valm<=valr)
				{
					if(valm<=check(other+1,mid)&&valm<=check(other-1,mid))
					{
						cout<<valm<<endl;
						return 0;
					}
					flag=true;
					l=-2e9,r=2e9;
					other=mid;
					break;
				}
				if(vall<=valm)r=mid;
				else l=mid;
			}
		}	
	}
	
	return 0;
}
}

int main()
{
	freopen("c.in","r",stdin); 
	freopen("c.out","w",stdout);
	return SolutionP3::main();
}
/*
4
1 2 0 0

12
1 2 3 4 7 8 9 10 11 12 13 15

11 5
*/
