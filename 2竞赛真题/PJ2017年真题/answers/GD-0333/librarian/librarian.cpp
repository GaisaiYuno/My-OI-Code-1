#include<iostream>
#include<cstdio>
using namespace std;
int n,m,l,t,f,s,minn;
char st[1000][8],st2[8];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>st[i];
	for (int i=1;i<=m;i++) 
	{
		minn=10000001;
		cin>>l>>st2;
		for (int j=1;j<=n;j++)
		{          
			f=0;
			for (int k=0;k<l;k++)
		      if (st[j][k+strlen(st[j])-l]!=st2[k]) 
		      {		     
		      	    f=1;
		        	break;
		      }
		    if (f==0)
			{
				t=1;
				s=0;
				for (int k=strlen(st[j])-1;k>=0;k--)
				{
					s+=(st[j][k]-48)*t;
					t=t*10;
					
				} 
				if (s<minn) minn=s;
			} 
		}
		if (minn==10000001) cout<<-1<<endl; else cout<<minn<<endl;
	}
	return 0;
}
