#include<iostream>
#include<cstdio>
using namespace std;
int n,m,i,a,b,c,s[105][105],w[105][105],ans=1000000,k;
void q(int x,int y,int o,int l,int k)
{
	if (x<1||x>m||y<1||y>m||w[x][y]==1) return;
	if (x==m&&y==m) {ans=min(ans,o);return;}
	w[x][y]=1;
	c=s[x][y];
	if (l!=3) {s[x][y]=l;} 
	if (s[x][y+1]==0) {if (k==0)q(x,y+1,o+2,s[x][y],1);} else if (s[x][y+1]!=s[x][y]) q(x,y+1,o+1,3,0); else q(x,y+1,o,3,0);
	if (s[x+1][y]==0) {if (k==0)q(x+1,y,o+2,s[x][y],1);} else if (s[x+1][y]!=s[x][y]) q(x+1,y,o+1,3,0); else q(x+1,y,o,3,0);
	if (s[x][y-1]==0) {if (k==0)q(x,y-1,o+2,s[x][y],1);} else if (s[x][y-1]!=s[x][y]) q(x,y-1,o+1,3,0); else q(x,y-1,o,3,0);
	w[x][y]=0;
	if (x!=1&&y!=1) s[x][y]=c;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=n;++i)
	{
	 scanf("%d%d%d",&a,&b,&c);
	 s[a][b]=c+1;	
	}
	q(1,1,0,3,0);
	if (ans!=1000000)
	cout<<ans; else cout<<-1;
	return 0;
}
