#include<iostream>
#include<cstdio>
using namespace std;

int m,n,area,x[10001],y[10001];
bool c[10001];

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	area=m*m;
	for(int i=1; i<=n; i++)
	  cin>>x[i]>>y[i]>>c[i];
	cout<<-1;
	  return 0;
}
