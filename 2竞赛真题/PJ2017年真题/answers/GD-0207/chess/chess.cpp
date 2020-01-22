#include<bits/stdc++.h>
using namespace std;
struct var
{
	int x,y,mo,f;
}q[50001];
int n,m,i,j,a[101][101],x,y,c,l,r,f[101][101],xx,yy,fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}},tmp,ans;
bool flag;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ans=2000000;
	cin>>m>>n;
	memset(f,0x7f,sizeof(f));
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}//2==yellow,1==red;
	l=r=1;
	q[1].x=1;
	q[1].y=1;
	q[1].mo=0;
	f[1][1]=0;
	while(r<=l)
	{
		for(i=0;i<4;i++)
		{
			xx=q[r].x+fx[i][0];
			yy=q[r].y+fx[i][1];
			if(xx>0&&yy>0&&xx<=m&&yy<=m&&(a[xx][yy]!=0||a[q[r].x][q[r].y]!=0))
			{
				tmp=q[r].mo;
				if(a[xx][yy]==0&&a[q[r].x][q[r].y]!=0)tmp+=2;
				else{
					if(a[q[r].x][q[r].y]!=0&&a[xx][yy]!=0&&a[q[r].x][q[r].y]!=a[xx][yy])tmp++;
				    else if(a[q[r].x][q[r].y]!=a[xx][yy]&&a[q[q[r].f].x][q[q[r].f].y]!=a[xx][yy])tmp++; 
				}
				if(tmp<f[xx][yy])
				{
					l++;
					q[l].x=xx;
					q[l].y=yy;
					q[l].mo=tmp;
					f[xx][yy]=tmp;
					if(a[xx][yy]==0)q[l].f=r;
					if(xx==m&&yy==m)flag=true;
				}
			}
		}
	r++;
	}
	if(flag)cout<<f[m][m];
	else cout<<"-1";
	return 0;
}
