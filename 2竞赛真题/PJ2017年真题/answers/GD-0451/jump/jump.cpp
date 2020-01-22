#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dis[100010],sc[1000010],f[100010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,sum=0,plus=0;
	bool flag=false;
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&dis[i]);
		scanf("%d",&sc[i]);
		if(sc[i]>0) sum+=sc[i];
	}
	if(sum<k) 
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}
