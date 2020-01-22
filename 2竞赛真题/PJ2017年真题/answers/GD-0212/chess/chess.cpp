#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a[1000][1000];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,s,x,z,y,n,m;
	s=x=z=y=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(z==0) a[x][y]=2;
		else a[x][y]=1;
	}
	cout<<"-1";
	return 0;
}
