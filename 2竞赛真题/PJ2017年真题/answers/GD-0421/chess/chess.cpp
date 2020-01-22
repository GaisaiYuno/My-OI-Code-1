#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;
const int dx[5]={0,0,1};
      int dy[5]={0,1,0};
int a[1005][1005],f[1005][1005],n,m,b,c,d,ans;
void find_(int x,int y,int k,int p,int s)
{
	if (x==n&&y==n) 
	 {ans=min(ans,k);return;}
	if (k>=f[x][y]) return;
	 else f[x][y]=k;
	for (int i=1;i<=2;i++)
	{
	 int xx=x+dx[i];
	 int yy=y+dy[i];
	 if (xx<1||xx>n||yy<1||yy>n) continue;
	 if (a[x][y]==0&&a[xx][yy]==0) return;
	 if (a[xx][yy]==s&&a[xx][yy]>0)
	  find_(xx,yy,k,0,s);
	 if (a[xx][yy]>0&&a[xx][yy]!=s)
	  find_(xx,yy,k+1,0,a[xx][yy]);
	 if (a[xx][yy]==0&&p==0)
	 {
	 	if (s==1) 
		 {find_(xx,yy,k+2,1,1);
		  find_(xx,yy,k+3,1,2);}
	 	if (s==2)
	 	{find_(xx,yy,k+2,1,2);
	 	 find_(xx,yy,k+3,1,1);}
     }
    }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
	 cin>>b>>c>>d;
	 a[b][c]=d+1;
    }
    for (int i=1;i<=n;i++)
     for (int j=1;j<=n;j++)
      f[i][j]=999999999;
    ans=99999999;
    find_(1,1,0,0,a[1][1]);
    if (ans==99999999) cout<<"-1";
     else cout<<ans;
	return 0;
}
