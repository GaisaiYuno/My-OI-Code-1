#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,m,a,b,c,s[105][105],f[105][105],z[105][105],w[105][105],mi,v[5];
int xx[5]={0,1,0,-1,0},yy[5]={0,0,1,0,-1};
void d(int x,int y)
{
  if(x<1||y<1||x>n||y>n||w[x][y]==1) return;
  if(x==n&&y==n) 
  {
    mi=min(mi,f[n][n]);
    return;
  }
  w[x][y]=1;
  for(int i=1;i<=2;i++)
  {
  	int p=1;
    if(s[x+xx[i]][y+yy[i]]==0&&z[x][y]==1) {continue;}
	else if(s[x+xx[i]][y+yy[i]]==0&&z[x][y]==0) {f[x+xx[i]][y+yy[i]]=f[x][y]+2;z[x+xx[i]][y+yy[i]]=1;s[x+xx[i]][y+yy[i]]=s[x][y];p=0;}
  	else if(s[x+xx[i]][y+yy[i]]==s[x][y]) {f[x+xx[i]][y+yy[i]]=f[x][y];}
    else if(s[x+xx[i]][y+yy[i]]!=s[x][y]&&s[x+xx[i]][y+yy[i]]!=0) {f[x+xx[i]][y+yy[i]]=f[x][y]+1;}
	d(x+xx[i],y+yy[i]);
	if(xx[i]>=0&&yy[i]>=0)
	{
	  f[x+xx[i]][y+yy[i]]=0;
	  z[x+xx[i]][y+yy[i]]=0;
	  if(p==0)s[x+xx[i]][y+yy[i]]=0;  
	}
  }
  w[x][y]=0;
  return;
}
int main()
{
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
  cin>>n>>m;
  mi=2000000000;
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b>>c;
    s[a][b]=c+1;
  }
  d(1,1);
  if(mi==2000000000) {cout<<-1;return 0;}
  cout<<mi;
  return 0;
}
