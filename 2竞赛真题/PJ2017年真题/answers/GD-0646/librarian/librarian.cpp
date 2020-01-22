#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long n,q,min1=10000005;
string s[1005],s1,s2;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for (int i=0;i<q;i++)
	{
		cin>>s1>>s2;
		int dd=0;
		min1=10000005;
		for (int j=0;j<n;j++)
		{
			if (s2.size()<=s[j].size())
			{
				int d=0;
				for (int k=s2.size()-1,k1=s[j].size()-1;k>=0;k--,k1--)
				{
					if (s2[k]!=s[j][k1]){d=1;break;}
				}
				if (d==0)
				{
					int ss=0;
					for (int k=0;k<s[j].size();k++)
					{
						ss=ss*10+int(s[j][k]-'0');
					}
					if (ss<min1){min1=ss;dd=1;}
				}
			}
		}
		if (dd==1) cout<<min1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
