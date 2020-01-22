#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,q,a[100005],d,cheng=1,k,c;
struct shu
{
	int cha,bian;
}b[10005];
bool cmp(shu a,shu b)
{
  	 return a.bian>b.bian;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=q;i++)
	  cin>>b[i].cha>>b[i].bian;
	 for(int i=1;i<=q;i++)
	 {  
	    cheng=1;
	   for(int j=1;j<=b[i].cha;j++)
	     cheng=cheng*10;
//	    cout<<cheng<<endl;
	 	int mind=999999999;
	 	for(int j=1;j<=n;j++)
	 	{	
		    c=cheng;
	 		if(a[j]!=0)
	 		{		
	 			d=a[j];
	 			while(c>0)
	 			{
				   if(d==b[i].bian)
	 			   break;
	 				d=d%c;
	 				c=c/10;
	 			}
	 			if(d==b[i].bian)
	 		      mind=min(a[j],mind);
	 		}
//	 		cout<<a[j]<<' ';	
	 	}
	 	for(int j=1;j<=n;j++)
	 		if(a[j]!=0)
	 		  if(mind==a[j])
	 		  {
	 		    a[j]=0;
	 		    break;
	 		   }
//	 	cout<<endl;
	 	if(mind!=999999999)
	 	  cout<<mind<<endl;
	 	else
	 	  cout<<-1<<endl;
	 }
	 return 0;
}
