#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int comp(const int &a,const int &b)
{
	return a<b;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,a[1000],b[1000][2];
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a+0,a+n,comp);
	for(int i=0;i<n;i++)cout<<a[i]<<' ';
	cout<<endl;
	for(int i=0;i<q;i++)cin>>b[i][0]>>b[i][1];
	for(int i=0;i<q;i++)//Ã¶¾Ùb[i][1]
	{
	     for(int j=0;j<n;j++)
	     {	
		      int nn=10;
	   	      while((b[i][1]!=(a[j]%nn))&&(a[j]/nn)!=0)nn*=10;
			   if(b[i][1]==a[j]%nn)
		      {
			   	cout<<a[j]<<endl;
			   	a[j]=0;	
			   	break;
			  }
			  else  if(j==n-1)
				cout<<"-1"<<endl;
	     }   
	}
	return 0;
}
