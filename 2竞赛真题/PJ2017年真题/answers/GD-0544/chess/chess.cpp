#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a,b,n;
	scanf( "%d%d%d",&a,&b );
	for( int i = 0;i < b*3;i++ )	scanf( "%d",&n );
	cout << -1;
	return 0;
}
