#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
struct reader
{
	int l;
	int num;
}a[1001];
long long int book[1001],n,q,k=1,ans=1;
bool p;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>book[i];
	}
	sort(book+1,book+(n+1));
	for(int i=1;i<=q;i++)
	{
		cin>>a[i].l>>a[i].num;
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p=false;
			ans=1;
			for(int k=1;k<=a[i].l;k++)
			{
				ans=ans*10;
			}
			ans=book[j]%ans;
			if(ans==a[i].num)
			{
				cout<<book[j]<<endl;
				p=true;
				break;
			}
			
		}
		if(p==false)
		{
			cout<<"-1"<<endl;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}









