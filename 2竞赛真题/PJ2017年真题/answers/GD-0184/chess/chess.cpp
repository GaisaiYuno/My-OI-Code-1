#include<iostream>
#include<cstdio> 
#include<cstring>
#include<cmath>
using namespace std;
int a[1006][1006],s;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,ans=0;
	cin>>m>>n;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;++i)
	{
		int x,y,c;
	cin>>x>>y>>c;
a[x][y]=c;
}
s=a[1][1];
for(int i=1;i<=m;++i)
for(int j=1;j<=m;++j)
{
	if(a[i][i]==-1)
	{
		cout<<"-1";
		cout<<endl;
		return 0;
	}
}
} 
