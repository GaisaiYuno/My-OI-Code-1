#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int dx[5]={0,-1,0,0,1};
int dy[5]={0,0,-1,1,0};
int v[110][110];
int m,n;
char qp[110][110];
int mins;
bool mofa=true;
void R(int x,int y,int sum)
{	
	if ((x==m)&&(y==m)) 
	{
		if (sum<mins) mins=sum;
		return;
	}
	if ((x==0)||(x>=m+1)||(y==0)||(y>=m+1)) return;
	if (v[x][y]) return;
	v[x][y]=1;
	for (int i=1;i<=4;i++)
	{
		if ((mofa==false)&&(qp[x+dx[i]][y+dy[i]]=='b'))
		{
			continue;
		}
		bool ok=mofa;
		if (qp[x+dx[i]][y+dy[i]]!='b') 
		{
			mofa=true;
			if (qp[x][y]==qp[x+dx[i]][y+dy[i]]) R(x+dx[i],y+dy[i],sum);
			else R(x+dx[i],y+dy[i],sum+1);
		}
		else
		{
			mofa=false;
			R(x+dx[i],y+dy[i],sum+2);
		}
		mofa=ok;
	}
	v[x][y]=0;
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=0;i<=m+1;i++)
		for (int j=0;j<=m+1;j++)
			qp[i][j]='b';
	for (int i=1;i<=n;i++)
	{
		int a,b,color;
		cin>>a>>b>>color;
		if (color==0) qp[a][b]='r';
		else qp[a][b]='y'; 
	}
	mins=100000;
	R(1,1,0);
	if (mins==100000) cout<<-1;
	else cout<<mins-1;
	return 0;
}
