#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,d,k,g,zh,j1;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int max=0,min=1e9;
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		int j,l;
		scanf("%d%d",&j,&l);
		if(l>0&&i>1)
		{
			if(j-j1>max)max=j-j1;
			if(j-j1<min)min=j-j1;
		}
		if(l>0)
		{
			zh+=l;
			j1=j;
		}
	}
	if(zh<k)
	{
		cout<<-1;
		return 0;
	}
	cout<<-1;
	return 0;	
}
