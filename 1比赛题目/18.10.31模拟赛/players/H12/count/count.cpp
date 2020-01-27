#include <iostream>
#include <stdio.h>
#include <string.h> 
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
using namespace std;

namespace Solution
{
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

int maxn[524289][19];
int arr[300001];
int n;

int log_2(int x)
{
	int ans=-1;
	if(x&~65535)x>>=16,ans+=16;
	if(x&~255)x>>=8,ans+=8;
	if(x&~15)x>>=4,ans+=4;
	if(x&~3)x>>=2,ans+=2;
	if(x&~1)x>>=1,ans++;
	if(x)ans++;
	return ans;
}

void init()
{
	for(int i=1;i<=n;i++)
	{
		maxn[i][0]=arr[i];
	}
	for(int j=1;j<=18;j++)
	{
		for(int i=1;i<=n;i++)
		{
			maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int l,int r)
{
	int len=log_2(r-l+1);
	return max(maxn[l][len],maxn[r-(1<<len)+1][len]);
}

int main()
{
	int m,type;
	read(n);read(m);read(type);
	for(int i=1;i<=n;i++)read(arr[i]);
	init();
	int last=0;
	while(m--)
	{
		int l,r;
		read(l);read(r);
		if(type)l=(l+last-1)%n+1,r=(r+last-1)%n+1;
		if(l>r)swap(l,r);
		last=0;
		for(int i=l;i<r;i++)
		{
			last++;
			for(int j=i+2;j<=r;j++)
			{
				if(query(i+1,j-1)<min(arr[i],arr[j]))last++;
			}
		}
		cout<<last<<"\n";
	}
	return 0;
}
	
} 



int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	return Solution::main();
}
