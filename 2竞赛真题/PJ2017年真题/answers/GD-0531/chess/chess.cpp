#include<iostream>
#include<cstdio>
int m,n,x,y,cc;
bool col[101][101],vis[101][101];
int coll[101][101];
int q[100001][2];
int c[101][101];
int hd=1,tl=1;
using namespace std;
int chan(int x1,int y1,int x2,int y2)
{
	if(col[x1][y1]) 
	{
		if(coll[x2][y2]==coll[x1][y1]) return 0;
		else return 1;
	}
	else
	{
		if(!col[x2][y2]) return 99999999;
		else 
		{
			coll[x1][y1]=coll[x2][y2];
			return 2;
		} 
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			coll[i][j]=-1;
			col[i][j]=0;
			c[i][j]=99999999;
			vis[i][j]=0;
		}
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d%d",&x,&y,&cc);
		col[x][y]=1;
		coll[x][y]=cc;
	}
	c[1][1]=0;
	q[hd][0]=1;q[hd][1]=1;
	while(hd<=tl)
	{
		vis[q[hd][0]][q[hd][1]]=0;
		if(q[hd][0]>1) 
		{
			int tmp=chan(q[hd][0]-1,q[hd][1],q[hd][0],q[hd][1]);
			if(tmp+c[q[hd][0]][q[hd][1]]<c[q[hd][0]-1][q[hd][1]]) 
			{
				c[q[hd][0]-1][q[hd][1]]=tmp+c[q[hd][0]][q[hd][1]];
				if(!vis[q[hd][0]-1][q[hd][1]])
				{
					tl++;
					q[tl][0]=q[hd][0]-1;q[tl][1]=q[hd][1];
					vis[q[hd][0]-1][q[hd][1]]=1;
				}
			}
		}
		if(q[hd][1]>1) 
		{
			int tmp=chan(q[hd][0],q[hd][1]-1,q[hd][0],q[hd][1]);
			if(tmp+c[q[hd][0]][q[hd][1]]<c[q[hd][0]][q[hd][1]-1]) 
			{
				c[q[hd][0]][q[hd][1]-1]=tmp+c[q[hd][0]][q[hd][1]];
				if(!vis[q[hd][0]][q[hd][1]-1])
				{
					tl++;
					q[tl][0]=q[hd][0];q[tl][1]=q[hd][1]-1;
					vis[q[hd][0]][q[hd][1]-1]=1;
				}
			}
		}
		if(q[hd][1]<m) 
		{
			int tmp=chan(q[hd][0],q[hd][1]+1,q[hd][0],q[hd][1]);
			if(tmp+c[q[hd][0]][q[hd][1]]<c[q[hd][0]][q[hd][1]+1]) 
			{
				c[q[hd][0]][q[hd][1]+1]=tmp+c[q[hd][0]][q[hd][1]];
				if(!vis[q[hd][0]][q[hd][1]+1])
				{
					tl++;
					q[tl][0]=q[hd][0];q[tl][1]=q[hd][1]+1;
					vis[q[hd][0]][q[hd][1]+1]=1;
				}
			}
		}
		if(q[hd][0]<m) 
		{
			int tmp=chan(q[hd][0]+1,q[hd][1],q[hd][0],q[hd][1]);
			if(tmp+c[q[hd][0]][q[hd][1]]<c[q[hd][0]+1][q[hd][1]]) 
			{
				c[q[hd][0]+1][q[hd][1]]=tmp+c[q[hd][0]][q[hd][1]];
				if(!vis[q[hd][0]+1][q[hd][1]])
				{
					tl++;
					q[tl][0]=q[hd][0]+1;q[tl][1]=q[hd][1];
					vis[q[hd][0]+1][q[hd][1]]=1;
				}
			}
		}
		if(!col[q[hd][0]][q[hd][1]]) coll[q[hd][0]][q[hd][1]]=-1;
		hd++;
	}
	if(c[m][m]>=99999999) printf("-1\n");
	else printf("%d\n",c[m][m]);
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",col[i][j]);
		printf("\n");
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",coll[i][j]);
		printf("\n");
	}
	/*for(int i=48;i<=50;i++)
		for(int j=48;j<=50;j++)
			cout<<col[i][j]<<" "<<coll[i][j]<<" "<<c[i][j]<<endl;*/
			fclose(stdin);fclose(stdout);
	return 0;
}
