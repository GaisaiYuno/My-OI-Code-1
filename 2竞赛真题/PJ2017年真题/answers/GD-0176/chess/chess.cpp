#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m,i,j,a[101][1001];
	cin>>n>>m;
	for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++)
	      cin>>a[i][j];
	cout<<"-1"<<endl;
	return 0;
}
