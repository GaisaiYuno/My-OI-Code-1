#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,p,a1[1001],num1[1001],num2[1001],b[1001],ans[1001];
string a[1001];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	  cin>>n>>p;
	for (int i=1;i<=n;i++)
	{
            int t=1;		
		    cin>>a[i];
		    num1[i]=a[i].size();
		  for (int j=a[i].size()-1;j>=0;j--)
		  {
		      a1[i]=a1[i]+(a[i][j]-48)*t;
		      t=t*10;
	      }
	}
	for (int i=1;i<=p;i++)
		cin>>num2[i]>>b[i];	
	for (int i=1;i<=p;i++)
	{
		  int flag=0,c=99999999;
		for (int j=1;j<=n;j++)
		{
			  if (num2[i]<=num1[j])
			  {
			  	  int sum=0,t=1;
			  	for (int k=num1[j]-1;k>=(num1[j]-num2[i]);k--)
			  	{
			  		sum=sum+(a[j][k]-48)*t;
			  		t=t*10;
			  	}
			  	if (sum==b[i])
			  	{
			  		if (a1[j]<c)
			  		  {
			  		    c=a1[j];
			  		    flag=j;
			  		  }
			  	}
			  }
			ans[i]=c;
		}      
		if (flag==0)
		  ans[i]=-1; 
	}
	for (int i=1;i<=p;i++)
	{
		cout<<ans[i]<<endl;
	}	
	return 0;
}
