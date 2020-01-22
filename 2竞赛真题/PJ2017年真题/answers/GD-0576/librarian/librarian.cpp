#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,a[1010],s,x,k[15];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	k[0]=1;
	for(int i=1; i<=9; i++) k[i]=k[i-1]*10;
	sort(a+1,a+n+1);
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&s,&x);
		for(int j=1; j<=n; j++)
		{
			if(a[j]%k[s]==x)
			{
				cout<<a[j]<<endl;
				break;
			}
			else if(j==n)
			{
				cout<<-1<<endl;
				break;
			}
		}
	}
	return 0;
}
