#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int b,p,book[1005],peoplen[1005],people[1005],a[15];
bool flag=true;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>b>>p;
	for(int i=1;i<=b;i++)
	  cin>>book[i];
	for(int i=1;i<=p;i++)
	  cin>>peoplen[i]>>people[i];
	sort(book+1,book+b+1);
	for(int i=1;i<=p;i++)
	{
		flag=true;
		int num=peoplen[i];
		for(int j=1;j<=b;j++)
		{
			memset(a,0,sizeof(a));
			int bb=book[j],s=0;
			while(bb!=0)
			{
				s++;
				a[s]=bb%10;
				bb/=10;
			}
			int sum=0;
			for(int k=num;k>0;k--)
			  sum=sum*10+a[k];
			if(sum==people[i])
			{
				cout<<book[j]<<endl;
				flag=false;
				break;
			}
			if(j==b && flag==true)
			  cout<<"-1"<<endl;
		}
	}
	return 0;
}
