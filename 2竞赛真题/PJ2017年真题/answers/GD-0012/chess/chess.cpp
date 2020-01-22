#include<fstream>
using namespace std;
int m,n,a[102][102],x,y,c,jb,mo,r;
bool mapp[102][102],mf,qs,ymf;
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
ifstream fin("chess.in");
ofstream fout("chess.out");
void dfs(int xx,int yy)
{
	if(xx==m&&yy==m) 
	{
		fout<<jb<<endl;
		qs=1;
		return;
    }
    if(mo!=xx&&r!=yy&&ymf==1) 
	{
		mf=0;
		a[mo][r]=-1;
    }
	mapp[xx][yy]=1;
	int x2,y2;
	for(int i=0;i<4;i++)
	{
		x2=xx+fx[i][0];
		y2=yy+fx[i][1];
		if(x2>=1&&x2<=m&&y2>=1&&y2<=m&&!mapp[x2][y2])
		{
			if(a[x2][y2]==a[xx][yy]&&qs==0) 
			{
			mf=0;
			dfs(x2,y2);
		    }
			if(a[x2][y2]!=a[xx][yy]&&a[x2][y2]!=-1&&qs==0)
			{
				mf=0;
				jb++;
				dfs(x2,y2);
				jb--;
	        }
	        if(a[x2][y2]==-1&&qs==0&&mf==0)
	        {
	        	jb+=2;
	        	mf=1;
	        	ymf=1;
	        	mo=x2;
	        	r=y2;
	        	a[x2][y2]=a[xx][yy];
	        	dfs(x2,y2);
	        	mo=0;
	        	r=0;
	        	ymf=0;
	        	a[x2][y2]=-1;
	        	mf=0;
	        	jb-=2;
	        }
		}
	}
}
int main()
{
	fin>>m>>n;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  a[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		fin>>x>>y>>c;
		a[x][y]=c;
	}
	dfs(1,1);
	if(qs==0) fout<<"-1"<<endl;
	return 0;
}
