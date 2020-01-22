#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,a[1000],numlong[1000],num[1000],min[1000];
	int i,j,m,ser=0,sur=0,fu,ck;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	   cin>>a[i];
	for(i=1;i<=q;i++)
	{
		cin>>numlong[i]>>num[i];
		min[i]=1000000;
	}
	for(i=1;i<=q;i++)
	{
		ser=num[i];
		for(j=1;j<=n;j++)
		{
			sur=a[j];
		  while(ser>0)
		  {
			  fu=ser%10;
			  ser/=10;
			  ck=sur%10;
			  sur/=10;
			  if(fu!=ck)
			  {
			      min[i]=-1;
			      break;
			  } 	  
		  }
		  if(a[j]<min[i])
		    min[i]=a[j]; 
		}
	}
	for(i=1;i<=q;i++)
	     cout<<min[i]<<endl;
	return 0;
}
