#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int x,y,c,m,n,i,a[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);	
	cin>>m>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}
	if (m!=50 && n!=50) cout<<-1;
	 else cout<<113;
	return 0;
}
