#include<iostream>
#include<cstdio>
using namespace std;
int ss(int m,int x,int y,int a[105][105],int min,int sum)
{
	if ((x==m)&&(y==m)&&(sum<min)) return sum;
	else if ((x==m)&&(y==m)&&(sum>=min)) return min;
	if (a[x+1][y]!=-1)
	{
		if (a[x+1][y]==a[x][y]) min=ss(m,x+1,y,a,min,sum);
		else min=ss(m,x+1,y,a,min,sum+1);
	}
	if (a[x][y+1]!=-1)
	{
		if (a[x][y+1]==a[x][y]) min=ss(m,x,y+1,a,min,sum);
		else min=ss(m,x,y+1,a,min,sum+1);
	}
	if (a[x+1][y+1]!=-1)
	{
		if (a[x+1][y+1]==a[x][y]) min=ss(m,x+1,y+1,a,min,sum+2);
		else min=ss(m,x+1,y+1,a,min,sum+3);
	}
	if (a[x+2][y]!=-1)
	{
		if (a[x+2][y]==a[x][y]) min=ss(m,x+2,y,a,min,sum+2);
		else min=ss(m,x+2,y,a,min,sum+3);
	}
	if (a[x][y+2]!=-1)
	{
		if (a[x][y+2]==a[x][y]) min=ss(m,x,y+2,a,min,sum+2);
		else min=ss(m,x,y+2,a,min,sum+3);
	}
	return min;
}

int main()
{
	int n,m,x,y,c;
	int a[105][105];
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=0;i<=m+1;++i)
	for (int j=0;j<=m+1;++j) 
    a[i][j]=-1;
	for (int i=1;i<=n;++i)
	{
		cin>>x>>y>>c;
		a[x][y]=c;
	}
    c=ss(m,1,1,a,1000000,0);
    if (c!=1000000) cout<<c;
    else cout<<-1;
	fclose(stdin);
    fclose(stdout);
}
