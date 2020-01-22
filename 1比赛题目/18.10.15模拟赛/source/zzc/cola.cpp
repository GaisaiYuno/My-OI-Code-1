#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

namespace Solution_Cola
{

const long long mod=2017;

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

struct matrix
{
	matrix operator+(const matrix &b)const
	{
		matrix c;
		for(int i=0;i<30;i++)
		{
			for(int j=0;j<30;j++)
			{
				c.d[i][j]=(d[i][j]+b.d[i][j])%mod;
			}
		}
		return c;
	}
	matrix operator*(const matrix &b)const
	{
		matrix c;
		for(int i=0;i<30;i++)
		{
			for(int j=0;j<30;j++)
			{
				c.d[i][j]=0;
				for(int k=0;k<30;k++)
				{
					c.d[i][j]=(c.d[i][j]+d[i][k]*b.d[k][j])%mod;
				}
			}
		}
		return c;
	}
	int d[30][30];
};

matrix p,one,start;

matrix pow(matrix p,int b)
{
	matrix ans;
	memcpy(ans.d,one.d,sizeof(ans.d));
	while(b)
	{
		if(b&1)ans=ans*p;
		p=p*p;
		b>>=1;
	}
	return ans;
}

//p^0+p^1+...+p^t-1
matrix getsum(int t)
{
//	printf("getsum(%d)\n",t);
	if(t==1)return one;
	int mid=t/2;
	matrix tmp=getsum(mid);
	if(mid==t-mid)return tmp+tmp*pow(p,mid);
	else return tmp+(tmp+pow(p,mid))*pow(p,mid);
}

int main()
{
	for(int i=0;i<30;i++)one.d[i][i]=1,p.d[i][i]=1;
	start.d[0][0]=1;
	int n,m;
	read(n);
	read(m);
	for(int i=0;i<m;i++)
	{
		int from,to;
		read(from);read(to);
		from--,to--;
		p.d[from][to]=1;
		p.d[to][from]=1;
	}
	int t;
	read(t);
	matrix p2=start*getsum(t+1);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans=(ans+p2.d[i][j])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}

}

int main()
{
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	return Solution_Cola::main();
}
