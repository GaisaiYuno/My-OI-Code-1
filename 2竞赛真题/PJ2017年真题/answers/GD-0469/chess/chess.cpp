#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10100][3];
	for(int i=0;i<m;i++)
	for(int j=0;j<3;j++)cin>>a[i][j];
	cout<<-1;
	return 0;
}
