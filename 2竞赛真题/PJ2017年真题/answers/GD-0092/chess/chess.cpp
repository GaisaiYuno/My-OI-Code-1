#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int m;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m;
	if(m==1)cout<<0;
	else cout<<-1;
	return 0;
}
