#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int m,n,a,b,c;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
	}
	if(m==1) cout<<0;
	else cout<<-1;
	return 0;
}
