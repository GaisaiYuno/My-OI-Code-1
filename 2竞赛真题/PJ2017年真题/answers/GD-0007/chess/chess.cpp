#include<iostream>
#include<cstdio>
using namespace std;
int o[5]={0,1,-1,0,0},p[5]={0,0,0,1,-1},sum,m,n,a,b,c,q[2000][2000];
bool w[2000][2000];
void qw(int x, int y,int l)
{
	if(x==m&&y==m) 
	{
		sum=min(sum,l);
		return;
	}
	if(l>sum) return;
	if(x>m||x<0||y>m||y<0||w[x][y])return;
	w[x][y]=true;
	for(int i=1; i<=4; ++i)
	if(q[x][y]!=0||q[x+o[i]][y+p[i]]!=0) 
	{
		if(q[x+o[i]][y+p[i]]==0) 
		qw(x+o[i],y+p[i],l+2);
		if(q[x+o[i]][y+p[i]]!=q[x][y])
		qw(x+o[i],y+p[i],l+1);
		if(q[x+o[i]][y+p[i]]==q[x][y])
		qw(x+o[i],y+p[i],l);
	}
	w[x][y]=false;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	sum=10000000;
	cin>>m>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a>>b>>c;
		if(c==0) q[a][b]=1;
		else q[a][b]=2;
	}
	if(m>15)
	cout<<-1;
	else
	{
		qw(1,1,0);
		if(sum==10000000) cout<<-1; else cout<<sum;
	}
	return 0;
}
