#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
using namespace std;
int a[3]={1,-1,0},b[3]={1,-1,0},n,m,x,y,q=-1,t[1008][1008];
long long MIN=800000,sum;
bool l[1008][1008],B[1008][1008];
void Chess(int x,int y,bool o)
{
	if (l[x][y]==true||x<0||x>n||y<0||y>n)	return; 
	if (x==y&&x==n)
	{
		MIN=min(MIN,sum);q=0;return;
	}
	for (int i=0;i<=2;i++)
		for (int j=0;j<=2;j++)
			{
				if (a[i]!=b[j])
				if (o||B[a[i]+x][b[j]+y]) 
				{
					long long s=sum;bool p=true;
					if ( B[a[i]+x][b[j]+y]&&abs(a[i])!=abs(b[j]) ) 
					if (t[a[i]+x][b[j]+y]!=t[x][y])	sum++;
					if (!B[a[i]+x][b[j]+y]) 
					{
						p=false;sum+=2;t[a[i]+x][b[j]+y]==t[x][y];B[x][y]=true;
					}
					l[x][y]=true;
					Chess(a[i]+x,b[j]+y,p);
					if (!B[a[i]+x][b[j]+y]) 
					{
						t[a[i]+x][b[j]+y]=0;B[x+a[i]][y+b[j]]=false;
					}
					sum=s;
					l[x][y]=false;
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
		cin>>x>>y>>t[x][y];
		t[x][y]++;
		B[x][y]=true;
	}
	if (n<=20) Chess(1,1,true);
	if (q==0)	cout<<MIN; else cout<<q;
	return 0;
}
