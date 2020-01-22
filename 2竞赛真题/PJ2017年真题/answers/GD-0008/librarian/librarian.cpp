#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[1001];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,lt;
	long long t,t1;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	int j;
	bool p;
	int p1;
	for(int i=1;i<=q;i++)
	{
		cin>>lt>>t;
		p1=0;
		for(int j=1;j<=n;j++)
		{
			t1=1;
			for(int k=1;k<=lt;k++)
			t1*=10;
			p=false;
			if(a[j]%t1==t)
			{
				p1=j;
				break;
			}
		}
		if(p1)
		cout<<a[p1]<<endl;
		else
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
