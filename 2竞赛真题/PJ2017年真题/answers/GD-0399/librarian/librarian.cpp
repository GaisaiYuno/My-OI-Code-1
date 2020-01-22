#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int n,q;

struct librarian
{
	string book;
	int len;
}a[1005];

bool cmp(librarian x,librarian y)
{
	if (x.len!=y.len) return x.len<y.len;
	return x.book<y.book;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf ("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].book;
		a[i].len=a[i].book.size();
	}	
	sort(a+1,a+1+n,cmp);
	while (q--)
	{
		int Len;
		string reader,ans="-1";
		cin >> Len >> reader;
		for (int i=1;i<=n;i++)
		{	
			bool check=0;
			for (int j=Len-1,k=a[i].len-1;j>=0;j--,k--)
				if (a[i].book[k]!=reader[j])
				{
					check=1;
					break;
				}
			if (!check)
			{
				ans=a[i].book;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
