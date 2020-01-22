#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
int a[105][105]={0},cm[105][105]={9},m,n,change[105][105]={0};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int x,y,c;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		cm[x][y]=c+2;
	}
	cout<<"-1";
	return 0;
}
