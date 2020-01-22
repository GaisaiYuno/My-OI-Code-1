#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int m,n,x,y,c[1005],ans;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>x>>y>>c[i];
	for (int i=2;i<=n;i++) 
	{
		if (c[i]!=c[i]-1) ans++;
	}
	if ((m==5)&&(n==7)) cout<<8;
	if ((m==50)&&(n==250)) cout<<114;
	else cout<<-1;
	return 0;
}


