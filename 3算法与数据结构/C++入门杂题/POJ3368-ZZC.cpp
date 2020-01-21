#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
	if(f)x=-x;
}

inline void read(unsigned int &x)
{
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
}

inline void read(short &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
	if(f)x=-x;
}

inline void read(unsigned short &x)
{
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
}

inline void read(long &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
	if(f)x=-x;
}

inline void read(unsigned long &x)
{
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
}

inline void read(long long &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-') f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
	if(f)x=-x;
}

inline void read(unsigned long long &x)
{
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){x=(((x<<2)+x)<<1)+ch-48;ch=getchar();}
}

inline void read(char &x)
{
	x=getchar();
	while(x<' ')x=getchar();
}

int number[131072];
int dp[131072];
int st[131072][18];

int log_2(long long x)
{
	int ans=-1;
	while(x)
	{
		ans++;
		x>>=1;
	}
	return ans;
}

void init(int n)
{
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(number[i]==number[i-1]) dp[i]=dp[i-1]+1;
		else dp[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		st[i][0]=dp[i];
	}
	for(int j=1;j<=17;j++)
	{
		for(int i=1<<j;i<=n;i++)
		{
			st[i][j]=max(st[i][j-1],st[i-(1<<(j-1))][j-1]);
		}
	}
}

int query(int l,int r)
{
	int len=log_2(r-l+1);
	return max(st[r][len],st[l+(1<<len)-1][len]);
}

int main()
{
	int n,m,l,r;
	while(true)
	{
		memset(number,0,sizeof(number));
		memset(dp,0,sizeof(dp));
		memset(st,0,sizeof(st));
		read(n);
		if(n==0) return 0;
		read(m);
		for(int i=1;i<=n;i++)
		{
			read(number[i]);
		}
		init(n);
		while(m--)
		{
			read(l);read(r);
			if(r<l) swap(r,l);
			int t;
			for(t=l;t<=r&&number[t]==number[t-1];t++);
			cout<<max(query(t,r),t-l)<<endl;
		}
	}

	return 0;
}//
