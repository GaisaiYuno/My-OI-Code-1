#include<cstdio>
using namespace std;
int ch[105][105],ans=2e9,m,n;
int zl[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool v[105][105];
void dfs(int x,int y,int mon,int k)
{
	int i,j;
	if (x==m && y==m)  
	{
		if (mon<ans) ans=mon;
		return;
	}
	else
	{
		for (i=0;i<=3;i++)
		{
			if (v[x+zl[i][0]][y+zl[i][1]]==false)
			{
				if (ch[x+zl[i][0]][y+zl[i][1]]==ch[x][y] && mon<ans) 
				{
					v[x+zl[i][0]][y+zl[i][1]]=true;
					dfs(x+zl[i][0],y+zl[i][1],mon,0);
					v[x+zl[i][0]][y+zl[i][1]]=false;
				} 
				if (ch[x+zl[i][0]][y+zl[i][1]]!=-1 && ch[x+zl[i][0]][y+zl[i][1]]!=ch[x][y] && mon+1<ans)
				{
					v[x+zl[i][0]][y+zl[i][1]]=true;mon++;
					dfs(x+zl[i][0],y+zl[i][1],mon,0);
					v[x+zl[i][0]][y+zl[i][1]]=false;mon--;
				}
				if (ch[x+zl[i][0]][y+zl[i][1]]==-1 && k==0)
				{
					for (j=0;j<=1;j++)
					{
						if (ch[x][y]==j && mon+2<ans)
						{
						  v[x+zl[i][0]][y+zl[i][1]]=true;mon=mon+2;
						  ch[x+zl[i][0]][y+zl[i][1]]=j;
					      dfs(x+zl[i][0],y+zl[i][1],mon,1);
					      v[x+zl[i][0]][y+zl[i][1]]=false;mon=mon-2;
					      ch[x+zl[i][0]][y+zl[i][1]]=-1;
					    }
					    if (ch[x][y]!=j && mon+3<ans)
					    {
					      v[x+zl[i][0]][y+zl[i][1]]=true;mon=mon+3;
						  ch[x+zl[i][0]][y+zl[i][1]]=j;
					      dfs(x+zl[i][0],y+zl[i][1],mon,1);
					      v[x+zl[i][0]][y+zl[i][1]]=false;mon=mon-3;
					      ch[x+zl[i][0]][y+zl[i][1]]=-1;
					    }
				     }
			    }   
		    }
		}
	if (k==1) ch[x][y]=-1;
    }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,x,y,c;
	scanf("%d %d",&m,&n);
	for (i=0;i<=m+1;i++)
	  for (j=0;j<=m+1;j++)
	  {
	  	  if (i==0 || i==m+1 || j==0 || j==m+1) v[i][j]=true;
		  else v[i][j]=false;
		  ch[i][j]=-1;
	  }
	for (i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		ch[x][y]=c;
	}
	v[1][1]=true;
	dfs(1,1,0,0);
	if (ans==2e9) printf("-1");
	else printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
