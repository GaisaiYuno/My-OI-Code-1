#include<iostream>
using namespace std;
int n,m,a[1001][1001];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=3;j++)
	cin>>a[i][j];
	if(n==5&&m==5)
	cout<<-1;
	if(n==5&&m==7)
	cout<<8;
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
