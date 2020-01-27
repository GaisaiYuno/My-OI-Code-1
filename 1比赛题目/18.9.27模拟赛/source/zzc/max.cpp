#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;

namespace Solution_Max
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
	int num[200001];
	int upper[1000001];
	int div1[1000];
	int div2[1000];
	int ndiv1,ndiv2;
	int upperbound(int *from,int *to,int x)
	{
		return upper[x];//?upper[x]:upper[x]=std::upper_bound(from,to,x)-from;
	}
	int main()
	{
		int n,ans=0;
		read(n);
	/*	for(int i=1;i<n;i++)
		{
			cout<<n%i<<endl;
		}*/
		for(int i=0;i<n;i++)
		{
			read(num[i]);
		}
		sort(num,num+n);
		n=unique(num,num+n)-num;
		for(int j=1000000;j>=num[n-1];j--)
		{
			upper[j]=n;
		}
		for(int i=n-1;i>0;i--)
		{
			for(int j=num[i]-1;j>=num[i-1];j--)
			{
				upper[j]=i;
			}
		}
		for(int i=n-1;i>0;i--)
		{
			if(num[i]<=ans)break;
			//cout<<"i="<<i<<endl;
			ndiv1=0,ndiv2=0;
			int tmp=num[i];
			int j;
			for(j=1;j*j<tmp;j++)
			{
				if(tmp%j==0)
				{
					div1[ndiv1]=j;
					div2[ndiv2]=tmp/j;
					++ndiv1,++ndiv2;
				}
			}
			if(j*j==tmp)div1[ndiv1++]=j;
			//cout<<"div1="<<ndiv1<<",div2="<<ndiv2<<endl;
			for(int j=0;j<ndiv2;j++)
			{
				int p=upper[div2[j]];
			//	printf("i=%d,p=%d,div=%d\n",i,p,div2[j]);
				if(p>=i)continue;
				if(ans>num[p])goto endfor;
				ans=max(ans,num[i]%num[p]);
			}
			for(int j=ndiv1-1;~j;j--)
			{
				int p=upper[div1[j]];
			//	printf("i=%d,p=%d,div=%d\n",i,p,div1[j]);
				if(p>=i)continue;
				if(ans>num[p])goto endfor;
				ans=max(ans,num[i]%num[p]);
			}
			endfor:;
		}
		cout<<ans<<endl;
		return 0;
	}
}

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	return Solution_Max::main();
}
