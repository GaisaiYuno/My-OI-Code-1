#include<fstream>
using namespace std;
ifstream fin("chess.in");
ofstream fout("chess.out");
int a[105][105];
int f[105][105];
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool map[105][105];
int ans=1e9;
int m,n;
int bj;						
void dfs(int x,int y)
{
	for (int i=0;i<4;i++)
    	{
    		if (x==m&&y==m) 
		      ans=min(ans,f[x][y]);
    		bj=0;
    		if (x<=0||y<=0||x>m||y>m)
    		  return;
		    if (a[x+fx[i][0]][y+fx[i][1]]!=0&&a[x+fx[i][0]][y+fx[i][1]]==a[x][y])
		    {
		    	f[x+fx[i][0]][y+fx[i][1]]=f[x][y];
		    	bj=1;
		    }
		    if (a[x+fx[i][0]][y+fx[i][1]]!=0&&a[x+fx[i][0]][y+fx[i][1]]!=a[x][y])
		      {
		      	f[x+fx[i][0]][y+fx[i][1]]=f[x][y]+1;
		      	bj=1;
		      }
		    if (a[x+fx[i][0]][y+fx[i][1]]==0&&(x+fx[i][0]>=1&&y+fx[i][1]>=1)&&a[x][y]!=0)
		      {
		      	f[x+fx[i][0]][y+fx[i][1]]=f[x][y]+2;
		      	bj=1;
		      }
		    if (bj==1&&map[x+fx[i][0]][y+fx[i][1]]==0)
		    {
		    	map[x+fx[i][0]][y+fx[i][1]]=1;
		    	dfs(x+fx[i][0],y+fx[i][1]);
		    	map[x+fx[i][0]][y+fx[i][1]]=0;
		    }
		    else return;
    	} 	
}
int main ()
{
	fin>>m>>n;
	int x,y,s;
	for (int i=1;i<=n;i++)
	{
		fin>>x>>y>>s;
		a[x][y]=s+1;
	}
	f[1][1]=0;
	map[1][1]=1;
	dfs(1,1);
	if (ans==1e9)
	fout<<-1;
	else fout<<ans-1;
	fin.close();
	fout.close();
	return 0;
}
