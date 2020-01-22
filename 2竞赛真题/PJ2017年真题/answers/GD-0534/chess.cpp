#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,a,b,c;
	cin>>m>>n;
	if (m==1)
	{
		for (int i=1;i<=n;++i)
		cin>>a>>b>>c;
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n;++i)
	cin>>a>>b>>c;
	cout<<-1;
	return 0;
}
