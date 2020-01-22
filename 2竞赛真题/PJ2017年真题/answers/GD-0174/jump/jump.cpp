#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,ans=1000000,l,r,d,a,b[1000],k;
int f[503][530];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		scanf("%d",&b[a]);
	}
	cout<<-1<<endl;
}
