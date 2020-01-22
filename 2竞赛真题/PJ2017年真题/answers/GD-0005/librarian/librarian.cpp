#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	if(a<b)
	  return 1;
	return 0;
}
int n,p;
int book[1005],line[1005],qu[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++)
	  cin>>book[i];
	sort(book,book+n,cmp);
	/*for(int i=0;i<+n;i++)
	  cout<<book[i]<<' ';
	cout<<endl;*/
	for(int i=0;i<p;i++)
	{
		cin>>line[i]>>qu[i];
		bool jj=1;
		for(int j=0;j<n;j++)
		{
			int bt=book[j],k=qu[i];bool kk=1;
			while(k!=0)
			{
				if(bt==0)
				{
					kk=0;
					break;
				}
				if(bt%10!=k%10)
				{
					kk=0;
					break;
				}
				bt/=10;
				k/=10;
			}
			if(kk)
			{
				cout<<book[j]<<endl;
				jj=0;
				break;
			}
		}
		if(jj)
		  cout<<"-1"<<endl;
	}
	return 0;
}

