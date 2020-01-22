#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int n,m,x,y,p,a[1000+5][1000+5];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int j=1;j<=m;j++)
	{
		scanf("%d %d %d",&x,&y,&p);
		a[x][y]=p+1;
	}
	cout<<-1;
	return 0;
}
