#include<iostream>
#include<fstream>
using namespace std;
int n,p,a[1005][9],b[1005][9],c[1005];
void mp(int a[],int n)
{
	int i=1,bo,t;
	do
	{
		bo=0;
		int j=1;
		while(j<=n-i)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				bo=1;
			}
			j++;
		}
		i++;
	}while(bo);
}
void sr(int a[],int j)
{
	int i=1;
	while(j)
	{
		a[i]=j%10;
		i++;
		j=j/10;
	}
	a[0]=i-1;
}
int pd(int a[],int b[],int c)
{
	int i;
	for(i=1;i<=c;i++)
	if(a[i]!=b[i])
	return 0;
	return 1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int i,j,l,k=0;
	cin>>n>>p;
	for(i=1;i<=n;i++)
	cin>>c[i];
	mp(c,n);
	for(i=1;i<=n;i++)
	sr(a[i],c[i]);
	for(i=1;i<=p;i++)
	{
		cin>>c[i]>>j;
		sr(b[i],j);
	}
	for(i=1;i<=p;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(pd(a[j],b[i],c[i]))
			{
				l=a[j][0];
				while(l>0)
				{
					cout<<a[j][l];
					l--;
				}
				cout<<endl;k=1;
				break;
			}
		}
		if(!k)
		cout<<-1<<endl;
		k=0;
	}
	return 0;
	fclose(stdin);fclose(stdout);
}
