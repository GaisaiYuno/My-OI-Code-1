#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int arthas(int n)
{
	int i,a=1;
	for(i=1;i<=n;i++)a*=10;
	return a;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int book[1010],lbook[1010],reader[1010],lreader[1010],i,n,q,o,well,happy,good,result[1010];
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>book[i];
		well=book[i];
		lbook[i]=0;
		while(well>0)
		{
			lbook[i]++;
			well=well/10;
		}
		if(book[i]==0)lbook[i]=1;
	}
	for(i=1;i<n;i++)
	{
		well=0;
		for(o=1;o<n;o++)
		{
			if(book[o]>book[o+1])
			{
				happy=book[o];book[o]=book[o+1];book[o+1]=happy;
				happy=lbook[o];lbook[o]=lbook[o+1];lbook[o+1]=happy;
				well++;
			}
		}
		if(well==0)break;
	}
	for(i=1;i<=q;i++)
	{
		cin>>lreader[i]>>reader[i];
		good=0;
		for(o=1;o<=n;o++)
		{
			if(lbook[o]>=lreader[i])
			{
				if(book[o]%arthas(lreader[i])==reader[i])
				{
					result[i]=book[o];
					good++;
					break;
				}
			}
		}
		if(good==0)result[i]=-1;
	}
	for(i=1;i<=q;i++)cout<<result[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
