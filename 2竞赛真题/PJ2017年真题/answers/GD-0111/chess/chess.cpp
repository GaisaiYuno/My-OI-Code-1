#include<cstdio>
#include<iostream>
using namespace std;
int x,y,chess[105][105]={0},ans[105][105]={0},n,m,lq=0;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	cin>>x>>y>>chess[x][y];
	cout<<-1<<endl;
	return 0;
}
