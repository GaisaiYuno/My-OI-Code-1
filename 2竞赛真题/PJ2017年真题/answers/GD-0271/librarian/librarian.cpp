#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int n,q;
int b[1001],du[1001];

void input()
{
	cin >>n >>q;
	for(int i=1;i<=n;i++)
		cin >>b[i];
	for(int i=1;i<=q;i++)
	{
		int x;
		cin >>x >>du[i];	
	}	
	sort(b+1,b+n+1);
}

void zhao()
{
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int z=du[i],z1=b[j];
			for(;z>0&&z1>0;z/=10,z1/=10)
				if(z%10!=z1%10) break;
			if(z>0 ) ans++;	
			else {cout<<b[j]<<endl;break;}
		}
		if(ans==n) cout<<-1<<endl;
	}
	
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	input();
	zhao();
	
	return 0;
}
