#include<iostream>
#include<fstream>
using namespace std;
int n,m,i,j,t,mini,ss,a[10005],b[10005],c[10005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for (i=1;i<=m;i++)
	{
		cin>>b[i]>>c[i];
	}
	for (i=1;i<=m;i++)
	{
	    mini=21484736487;
	    t=0;
		for (j=1;j<=n;j++)
		{
			if (b[i]==1) ss=a[j]%10;
			if (b[i]==2) ss=a[j]%100;
			if (b[i]==3) ss=a[j]%1000;
			if (b[i]==4) ss=a[j]%10000;
			if (b[i]==5) ss=a[j]%100000;
			if (b[i]==6) ss=a[j]%1000000;
			if (b[i]==7) ss=a[j]%10000000;
			if ((ss==c[i])&&(a[j]<mini)) {mini=a[j];t=1;}
		}
		if (t==0) cout<<"-1"<<endl;else
		  cout<<mini<<endl;
	}
}
