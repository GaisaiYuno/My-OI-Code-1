#include<fstream>
using namespace std;
ifstream cin("jump.in");
ofstream cout("jump.out");
struct st1
{
	long far,value;
};
struct st1	a[501];
long n,d,k;
bool b=false;
bool check(long wz)
{
	for(long x=1;x<=n;x++)
		if(a[x].far==wz)
			return(true);
	return(false);
}
void dg(long wz,long zd,long zx,long value)
{
	long k1;
	if(value>=k)
		b=true;
	if(!b)
	{
		for(long x=zx;x<=zd;x++)
		{
			if((wz+x<=a[n].far)&&(check(x+wz)))
			{
				k1=0;
				for(long y=1;y<=n;y++)
					if(a[y].far==wz+x)
						k1=a[y].value;
				dg(wz+x,zd,zx,value+k1);
			}
			if(b)
				break;
		}
	}
}
int main()
{
	long sum=0;
	bool RC=false;
	cin>>n>>d>>k;
	for(long x=1;x<=n;x++)
		cin>>a[x].far>>a[x].value;
	for(long x=0;x<=n;x++)
	{
		long zd=d+x,zx=d-x;
		if(zx<1)	
			zx=1;
		dg(0,zd,zx,0);
		if(b)
		{
			cout<<x<<endl;
			RC=true;
			break;
		}
	}
	if(!RC)
		cout<<-1<<endl;
	return(0);
	cin.close();
	cout.close();
}
