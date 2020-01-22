#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

namespace Solution_Bed
{

template<typename type>
void read(type &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

int d[300001];
int st1[300001][18];//min
int st2[300001][18];//max
int n;

int log_2(int x)
{
	int ans=0;
	if(x&~65535)ans+=16,x>>=16;
	if(x&~255)ans+=8,x>>=8;
	if(x&~15)ans+=4,x>>=4;
	if(x&~3)ans+=2,x>>=2;
	if(x&~1)++ans,x>>=1;
	if(x)++ans;
	return ans-1;
}

void init()
{
	for(int i=1;i<=n;i++)
	{
		st1[i][0]=d[i];
		st2[i][0]=d[i];
	}
	for(int j=1;j<=18;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+(1<<(j-1))>n)break;
			st1[i][j]=min(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
}

int getmax(int l,int r)
{
	int len=log_2(r-l+1);
	return max(st2[l][len],st2[r-(1<<len)+1][len]);
}

int getmin(int l,int r)
{
	int len=log_2(r-l+1);
	return min(st1[l][len],st1[r-(1<<len)+1][len]);
}

int main()
{
	int k;
	read(n);read(k);
	for(int i=1;i<=n;i++)read(d[i]);
	init();
//	cout<<"init";
	int l=1,r;
	int ans=0;
	for(r=1;r<=n;r++)
	{
		while(getmax(l,r)-getmin(l,r)>k)l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

/*int test()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(d[i]);
	}
	init();
	for(int j=0;j<=3;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<st2[i][j]<<" ";
		}
		cout<<endl;
	}
	while(true)
	{
		int l,r;
		read(l);read(r);
		cout<<getmax(l,r)<<endl;
	}
	return 0;
}*/

}

int main()
{
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	return Solution_Bed::main();
}
