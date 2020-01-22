#include<iostream>

#include<cstdio>

using namespace std;
int cf(int l)
{
	int sum=1;
	for(int k=1;k<=l;k++)
	{
		sum*=10;
	}
	return sum;
}
int n,q,i,j,t;
bool pd;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>q;
	int a[1001],b[3][1001];
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		if(i>=1)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		
	}
	for(i=0;i<q;i++)//i=q×îºóÊä³ö 
	{
		if(i>=1)
		{
			pd=false;
		cin>>b[1][i]>>b[2][i];
		j=0;
		while(pd!=true&&j<n)
		{
			j++;
			if(a[j]%cf(b[1][i])==b[2][i])
			{
				cout<<a[j]<<endl;
				pd=true;
			}
		}
		if(pd==false)
		{
			cout<<"-1"<<endl;
		}
		}
		
	}
	pd=false;
	cin>>b[1][q]>>b[2][q];
	j=0;
	while(pd!=true&&j<n)
	{
		j++;
		if(a[j]%cf(b[1][q])==b[2][q])
		{
			cout<<a[j];
			pd=true;
		}
	}
	if(pd==false)
	{
		cout<<"-1";
    }
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
