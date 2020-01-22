#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream	fin("librarian.in");
ofstream    fout("librarian.out");
	int n,q,a[1001],b[1001],i,c[1001],j,min,d,k,m,s,ans[1001],l;
	fin>>n>>q;
	for (i=0;i<n;i++) fin>>a[i];
	for (i=0;i<q;i++) fin>>c[i]>>b[i];
	for (i=0;i<q;i++)
	{
		min=10000001;
		for (j=0;j<n;j++)
		{
		d=0;	
		s=a[j];
		k=1;
		m=c[i];
		while(m)
		{
			d=d+s%10*k;
			k=k*10;
			s=s/10;
			m--;
		}
		if (d==b[i]) if (a[j]<min) min=a[j];
	    }
	    if (min==10000001) ans[i]=-1;
	    else
	    {
	    	ans[i]=min;
	    	for (l=0;l<n;l++)
	    	    if (a[l]==min)
	    	    {
	    	        a[l]=-1;
					break;	
	    	    }
	    }
	}
	for (i=0;i<q;i++) fout<<ans[i]<<endl;
	return 0;
}
