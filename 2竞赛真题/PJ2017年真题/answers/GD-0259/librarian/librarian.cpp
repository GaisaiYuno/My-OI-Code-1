//GD-259 ¿Ó÷ŸÔ« 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int book[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>book[i];
	sort(book,book+n);
	for(int i=0;i<q;i++)
	{
		int read,lon,minl;
		bool find=true;
		cin>>lon>>read;
		for(int j=0;j<n;j++)
		{
			int a=book[j]-read,count=0;
			if(a==0)
			{
				find=false;
				minl=book[j];
				break;
			}
			if(a>0)
			{
				while(a!=0)
				{
					if(a%10==0)
						count++;
					else
						break;
					a/=10;
				}
				if(count==lon)
				{
					minl=book[j];
					find=false;
					break;
				}
			}
		}
		if(find==false)
			cout<<minl<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
