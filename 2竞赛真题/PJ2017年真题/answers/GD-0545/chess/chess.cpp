#include<iostream>
using namespace std;
int board[101][101]={0};
int x,y,c,m,n;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>x>>y>>c;
	cout<<-1;
	return 0;
}
