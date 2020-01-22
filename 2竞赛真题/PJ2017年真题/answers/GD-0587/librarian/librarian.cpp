#include<fstream>
#include<cstring>
#include<string.h>
using namespace std;
ifstream cin("librarian.in");
ofstream cout("librarian.out");
long a[1001],minbm;
bool check(long a1,long a2)
{
	while((a1>0)&&(a2>0)&&(a1%10==a2%10))
	{
		a1=a1/10;
		a2=a2/10;
	}
	if(a1==0)
		return(true);
	else
		return(false);
}
int main()
{
	long n,q,find1,wl;
	bool b;
	cin>>n>>q;
	for(long x=1;x<=n;x++)
		cin>>a[x];
	for(long x=1;x<=n;x++)
	{
		cin>>wl>>find1;	
		b=false;
		minbm=2147483647;
		for(long y=1;y<=n;y++)
		{
			if(check(find1,a[y]))
			{
				minbm=min(a[y],minbm);
				b=true;
			}
		}
		if(b)
			cout<<minbm<<endl;
		else
			cout<<-1<<endl;
	}
	return(0);
	cin.close();
	cout.close();
}
