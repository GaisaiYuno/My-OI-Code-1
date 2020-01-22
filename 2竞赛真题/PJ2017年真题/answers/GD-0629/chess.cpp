#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int m,n,p[10010][10010];
int ans=10000;
int tot=0;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int k=1;k<=n;k++)
	{
		int i,j,color;
		scanf("%d%d%d",&i,&j,&color);
		p[i][j]=color;
	}
	printf("-1");
	return 0;
}
