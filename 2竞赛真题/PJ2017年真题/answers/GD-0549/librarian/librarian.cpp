#include<iostream>
#include<cstdio>
using namespace std;
int p,k,n,m,o,s,q,t,mi,f,a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>p>>k;mi=10000001;f=0;
		for(int j=1;j<=n;j++)
		{
		   s=a[j];t=1;
		   do
		   {
			  o++;if(o>p)break;
			  q=q+(s%10)*t;t*=10;
			  s=s/10;
	 	   }while(s!=0);
	 	   if(q==k){f=1;mi=min(mi,a[j]);}
	 	   q=0;o=0;
	    }
	    if(f==1)cout<<mi<<endl;
	    else cout<<-1<<endl;
	}
	return 0;
}
