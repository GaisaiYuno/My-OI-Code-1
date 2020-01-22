#include<bits/stdc++.h>
using namespace std;
ifstream fin("librarian.in");
ofstream fout("librarian.out");
struct s
{
	int b,c,d;
};
int a[1005],x,y,i,j,k,f,g;
s A[1005];
int main()
{
	fin>>x>>y;
	for(i=0;i<x;i++)
	{
		fin>>a[i];
	}
	for(i=0;i<y;i++)
	{
		fin>>A[i].b>>A[i].c;
		A[i].d=100000001;
	}
	
	for(i=0;i<y;i++)
	{
	    f=1;
	    for(j=0;j<A[i].b;j++)
	    {
	    	f=f*10;
	    }
	for(k=0;k<x;k++)
	 {
		if(a[k]%f==A[i].c)
		{
			if(a[k]<A[i].d)
			{
			A[i].d=a[k];
			}
		}
	 }
    }
    for(i=0;i<y;i++)
    {
    	g=-1;
    	if(A[i].d!=100000001)
    	fout<<A[i].d<<endl;
    	else
    	fout<<g<<endl;
    }
	return 0;
}
