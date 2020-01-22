#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,q,len;
string a[1001],bm;

bool cmp(string c,string d)
{
	if(c.size()!=d.size()) return c.size()<d.size();
	return c<d;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=q;i++)
	{
		cin>>len>>bm;
		int m=0,checkk=0,pd=0;
		for(int j=1;j<=n;j++)
		{
			int p=a[j].size();
			if(p<len) continue;
			checkk=0,m=0;
			for(int k=p-len;k<p;k++)
			{
				if(a[j][k]!=bm[m]) checkk=1;
				else m++;
			}
			if(checkk==0) 
			{
				cout<<a[j]<<endl;
				pd=1;
				break;
			}
		}
		if(pd==0) cout<<-1<<endl;
	}
	return 0;
}
