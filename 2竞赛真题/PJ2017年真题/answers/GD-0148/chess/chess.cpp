#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int j1[4]={1,0,-1,0};
const int j2[4]={0,1,0,-1};
bool k[103][103],j[103][103],aa1,z1[103][103],qqqqq;
int n,m,l[103][103],xx,yy,x,y,c,z,qqq,qqqq,add;
void dfs(int x1,int y1,bool k1)
{
	if(x1==m&&y1==m)
	{
		add=l[m][m];
	}
	else
	{
		for(int i=0;i<=3;i++)
		{
			xx=j1[i];
			yy=j2[i];
			if(x1+xx<=m&&x1+xx>=1&&y1+yy<=m&&y1+yy>=1)
			{
				if(k1)
				{
					if(k[x1+xx][y1+yy])
					{
						if(j[x1+xx][y1+yy]==j[x1][y1])
						z=0;
						else
						z=1;
						if(l[x1+xx][y1+yy]>l[x1][y1]+z||l[x1+xx][y1+yy]==0)
						{
							l[x1+xx][y1+yy]=l[x1][y1]+z;
							dfs(x1+xx,y1+yy,true);
						}
					}
					else
					{
						if(l[x1+xx][y1+yy]>l[x1][y1]+2||l[x1+xx][y1+yy]==0)
						{
							l[x1+xx][y1+yy]=l[x1][y1]+2;
							dfs(x1+xx,y1+yy,0);
						}
					}
				}
				else
				{
					if(k[x1+xx][y1+yy]&&(l[x1+xx][y1+yy]>l[x1][y1]||l[x1+xx][y1+yy]==0))
					{
						l[x1+xx][y1+yy]=l[x1][y1];
						dfs(x1+xx,y1+yy,true);
					}
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(k,0,sizeof(k));
	memset(z1,0,sizeof(z1));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		k[x][y]=1;
		j[x][y]=c;
	}
	aa1=0;
	for(int i=1;i<=m;i++)
		for(int q=1;q<=m;q++)
			if(k[i][q])
			{
				z1[i][q]=1;
				z1[i-1][q]=1;
				z1[i+1][q]=1;
				z1[i][q-1]=1;
				z1[i][q+1]=1;
			}
	for(int i=1;i<=2*m-1;i++)
	{
		qqqqq=0;
		qqq=i;
		qqqq=1;
		while(qqq)
		{
			if(z1[qqq][qqqq]==1)
			{
				qqqqq=1;
				break;
			}
			qqq--;
			qqqq++;
		}
		if(qqqqq==0)
		{
			aa1=1;
			break;
		}
	}
	if(!aa1)
	{
		dfs(1,1,true);
		printf("%d",add);
	}
	else
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
