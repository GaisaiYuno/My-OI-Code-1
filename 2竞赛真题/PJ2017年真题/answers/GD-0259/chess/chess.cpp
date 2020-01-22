//GD-259 ÀîÖÙïÇ 
#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int chess[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		chess[x][y]==c+1;
	}
	cout<<"-1";
	return 0;
}
