#include<iostream>
#include<fstream>
#include<string>
using namespace std;
long long size[10001],b[10001],o[10001];
string a[10001];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	long long n,q,x=0,min=99999,u=0;
	string s;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i];
	  s=a[i];
	  for(int j=0;j<s.size();j++)
		  	     {
		  	     	o[i]=o[i]*10;
		  	     	o[i]+=s[j]-'0';	
		  	     }
	}
	for(int i=1;i<=q;i++)
	  cin>>size[i]>>b[i];
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		  {
		  	s=a[j];
		  	for(int h=s.size()-size[i];h<s.size();h++)
		  	     {
		  	     	x=x*10;
		  	     	x+=s[h]-'0';
		  	     }
		  	if((b[i]==x)&&(o[j]<=min))
		  	{
		  		min=o[j];
		  	    u=1;
		  	}
		  	x=0;
		  }
		  if(u==1)
		    {
		    	cout<<min<<endl;
		    	u=0;
		    	min=999999;
		    }
		  else
		  cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
