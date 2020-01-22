#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,q,i,j,k,z,v,a,b[100005],d[100005],c[100005],p,st,vv,l,m,pp;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(i=1;i<=q;i++)
	{
		cin>>a>>st;
		z=st;
		vv=0;
		while(z!=0)
		{
			k=z%10;
			z=z/10;
			vv++;
			d[vv]=k;
		}
		m=99999999;
		p=0;
		pp=0;
		for(j=1;j<=n;j++)
		{
	    	z=b[j];
	    	v=0;
	    	while(z!=0)
	    	{
	    		k=z%10;
	    		z=z/10;
	    		v++;
	    		c[v]=k;
	    	}
	    	if(v>=a)
	    	{
	    		l=a+1;
	    		p=0;
	    		for(k=a;k>=1;k--)
	    		{
	    			l--;
	    			if(d[l]!=c[k])
	    			{
	    				p=1;
	    				break;
	    			}
	    		}
	    		if(p==0) pp=1;
	    		if(pp==1&&p==0)
				{
					if(m>b[j]) m=b[j]; 
				} 
	    	}
	    }
	    if(pp==1) 
	    {
	    	cout<<m<<endl;
	    }else cout<<-1<<endl;
	}
	return 0;
}

