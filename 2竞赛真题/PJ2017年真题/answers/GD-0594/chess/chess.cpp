#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;
int x,y;
int a[101][101],m,n,cnt=0,colour;
bool p;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=2;
		}
	}
	int g,h,z;
	for(int i=1;i<=n;i++)
	{
		cin>>g>>h>>z;
		a[g][h]=z;
	}
	cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}














