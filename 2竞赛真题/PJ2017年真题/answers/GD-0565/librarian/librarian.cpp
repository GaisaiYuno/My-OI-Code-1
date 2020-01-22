#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,q,a[1015],len[1015],num[1015];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<=1015;i++) a[i]=0;
	for(int i=0;i<=1015;i++) num[i]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++) cin>>len[i]>>num[i];
	for(int i=1;i<=q;i++)
	{
		int minn=2147483647;
		for(int j=1;j<=n;j++)
		{
			int k=0;
			int sum1,sum2,a1=a[j],num1=num[i];
			int b=1;
			while(k<len[i])
			{
				sum1=a1%10;
				a1/=10;
				sum2=num1%10;
				num1/=10;
				if(sum1==sum2) k++;
				else
				{
					b=0;
					break;
				} 
			}
			if(b==1)
			  minn=min(minn,a[j]);
			else continue;
		}
		if(minn==2147483647) cout<<"-1"<<endl;
		else cout<<minn<<endl;
	}
	return 0;
}
