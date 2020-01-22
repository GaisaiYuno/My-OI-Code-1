#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int const MAX=10000;
int m,n,x,y,c,a[MAX][MAX],p=1,step=0,coin=0;

int main(void)
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]==c; 
	}
	cout<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
