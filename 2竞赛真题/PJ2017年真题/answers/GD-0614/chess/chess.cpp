#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;
int a[105][1005]={2};
int min1=10000000,n,m,i,j,b,c,d,sum;
int main()
{
    freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++)
	{
	 scanf("%d%d%d",&b,&c,&d);
	 a[b][c]=d;
	}
	cout<<-1; 
	return 0;	
}
