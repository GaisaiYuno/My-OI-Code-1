#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
int n,m;
int s[110][110];
int f[110][110][5];
int q[12000][2],front=1,tail=0;
int d[4][2]={0,1,1,0,0,-1,-1,0};
bool check (int x,int y)
{
	if (x*y==0||x>m||y>m) return 0;
	return 1;
}
void SPFA ()
{
	while (tail!=front-1)
	{
		int x=q[front][0],y=q[front][1];
		front++;
		if (front>11000) front=1;
		for (int i=0; i<4; i++)
		{
			int nx=x+d[i][0],ny=y+d[i][1];
			if (!check (nx,ny)) continue;
			int co=s[nx][ny];
			if (co!=0)
			{
				if (f[x][y][1]+bool(co!=1)<f[nx][ny][co])
				{
					f[nx][ny][co]=f[x][y][1]+bool(co!=1);
					tail++;
					if (tail>11000) tail=1;
					q[tail][0]=nx,q[tail][1]=ny;
				}
				if (f[x][y][2]+bool(co!=2)<f[nx][ny][co])
				{
					f[nx][ny][co]=f[x][y][2]+bool(co!=2);
					tail++;
					if (tail>11000) tail=1;
					q[tail][0]=nx,q[tail][1]=ny;
				}
			}
			else if (s[x][y])
			{
				co=1;
				if (f[x][y][1]+2<f[nx][ny][co])
				{
					f[nx][ny][co]=f[x][y][1]+2;
					tail++;
					if (tail>11000) tail=1;
					q[tail][0]=nx,q[tail][1]=ny;
				}
				co=2;
				if (f[x][y][2]+2<f[nx][ny][co])
				{
					f[nx][ny][co]=f[x][y][2]+2;
					tail++;
					if (tail>11000) tail=1;
					q[tail][0]=nx,q[tail][1]=ny;
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	memset (s,0,sizeof (s));
	memset (f,0x7f,sizeof (f));
	cin>>m>>n;
	for (int i=1; i<=n; i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		c++;
		s[x][y]=c;              //1为红，2为黄，0为无 
	}
	tail++;
	q[front][0]=q[front][1]=1;
	f[1][1][s[1][1]]=0;
	SPFA ();
	int ans=min (f[m][m][1],f[m][m][2]);
	if (ans==2139062143)
	cout<<-1;
	else cout<<ans;
	return 0;
}

