#include<fstream>
#include<cmath>
using namespace std;
int mapa[110][110],mapb[110][110],mapc[110][110];
int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int m,n;
bool fw(int x,int y)
{
	bool a=0;
	if(x<=m&&x>0&&y<=m&&y>0)
	 a=1;
	return a;
}
int main()
{
	ifstream fin("chess.in");
	ofstream fout("chess.out");
	fin>>m>>n;
	int x,y,c;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  mapb[i][j]=1e9;
	for(int i=1;i<=n;i++)
	{
	  fin>>x>>y>>c;
	  mapa[x][y]=c+1;
	}
	mapb[1][1]=0;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	 {
	   if(mapa[i][j]==0)
	    mapc[i][j]=1;
	   for(int k=0;k<4;k++)
	   {
	   	 x=i+fx[k][0],y=j+fx[k][1];
	   	 if(fw(x,y))
	   	 {
	   	   int dif=max(mapa[x][y],mapa[i][j])-min(mapa[x][y],mapa[i][j]);
		   if(mapa[x][y]!=0)
	   	     mapb[x][y]=min(mapb[i][j]+dif,mapb[x][y]);
	   	   else
		   {
		   	 if(mapc[i][j])
		   	  continue;
		   	 else
		   	  {
		   	  	mapb[x][y]=min(mapb[x][y],mapb[i][j]+2);
		   	  	mapa[x][y]=mapa[i][j];
		   	  	mapc[x][y]=1;
		   	  }
		   }
	   	 }
	   }
	 }
	if(mapb[m][m]!=1e9)
	 fout<<mapb[m][m];
	else 
	 fout<<-1;
	fin.close();
	fout.close();
	return 0;
}
