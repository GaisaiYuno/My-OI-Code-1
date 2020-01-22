#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int a[1024],b[2048],c[1024];
	int n,q,i,j,k,l,t=1,e,x=0,y=0;
	long long s=10000001;
	memset(c,0,sizeof(c));
	cin>>n>>q;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<(q*2);i++)
	cin>>b[i];
	for(i=0,k=1,e=0;i<(q*2);i+=2,k+=2,e++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]>=b[k])
			{
				for(l=1;l<=b[i];l++)
				t*=10;
				if(b[k]==(a[j]%t))
				{
					if(a[j]<s)
					{
						s=a[j];
						c[e]=a[j];
						x=j;	
					}
				}
			}
			if(x!=y)
			a[x]=0;
			y=x;
		}
		if(c[e]==0)
		c[e]=c[e]-1;
	}
	for(i=0;i<q;i++)
	cout<<c[i]<<endl;
	return 0;
}
