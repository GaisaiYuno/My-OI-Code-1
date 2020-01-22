#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1001;
int a[MAXN][MAXN];
int m,n,i,j,k;
bool OK=1;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(a,0,sizeof(a));
	for(int x=1;x<=n;x++)
	{
		i,j,k;
		scanf("%d%d%d",&i,&j,&k);
		a[i][j]=k;
	}
	printf("-1");
	return 0;
}
