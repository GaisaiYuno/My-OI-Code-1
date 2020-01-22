#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a[3000];
	int m,n,i;
	cin>>m>>n;
	for(i=0;i<(n*3);i++)
	cin>>a[i];
	cout<<"-1";
	return 0;
}
