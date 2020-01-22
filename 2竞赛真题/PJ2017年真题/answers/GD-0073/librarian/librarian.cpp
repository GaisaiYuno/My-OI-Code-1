#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,q,Len;
string a[2000];
string mark;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=q; i++)
	{
		scanf("%d",&Len);
		cin>>mark;
		string ans="-1";
		for(int j=1; j<=n; j++)
		{
			bool fl=true;
			int tmp=a[j].size();
			for(int k=Len-1; k>=0; k--)
				if(mark[k]!=a[j][--tmp])
				{
					fl=false;
					break;
				}
			if(fl)
			{
				ans=a[j];
				break;
			}			
		}
		cout<<ans;
	}
	return 0;
}
