#include <iostream>
#include <cstdio>
using namespace std;
int n,m,x,y,c,num,a[120][120],ans=0,flag;
const int oo=-1;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=105;i++)
		for (int j=1;j<=105;j++)
		a[i][j]=oo;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
	num=a[1][1];
	flag=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]!=oo)
			{
				if (a[i][j+1]==oo&&a[i+1][j]==oo)
				{
					if (flag==0) {cout<<"-1";return 0;}
					a[i][j+1]=a[i+1][j+1];
					ans+=2;
					flag=0;
				}
				else
				{
					if (a[i][j]!=num) ans++;
					else flag=1;
					num=a[i][j];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
