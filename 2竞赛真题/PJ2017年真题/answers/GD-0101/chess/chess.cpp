#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,chess[101][101],ans=0;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	  cin>>m>>n;
	  memset(chess,-1,sizeof(chess));
	for (int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		chess[x][y]=z;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if ((chess[i][j+1]==-1)&&(chess[i][j+2]==-1)&&(chess[i+1][j]==-1)&&(chess[i+1][j+1]==-1)&&(chess[i+1][j+2]==-1)&&(chess[i+2][j]==-1)&&(chess[i+2][j+1]==-1)&&(chess[i+2][j+2]==-1))
			  {
			  	 cout<<-1;
			  	 return 0;
			  }
			  else
			  {
			  	 ans++;
			  }
		}
	}
      cout<<-1<<endl;
	return 0;		
}
