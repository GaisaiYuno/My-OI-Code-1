#include<cstdio>
using namespace std;
int n,m,x,y,c,clo[1005][1005],v[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int min_(int a,int b)
{
	if(a>b)return b;
	  else return a;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		if(c==0)clo[x][y]=1;
		if(c==1)clo[x][y]=2;
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		v[i][j]=100000;
	v[1][1]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(clo[i][j]>0)
		{
			for(int k=0;k<4;k++)
			{
				int px=i+dx[k];
				int py=j+dy[k];
				if(px>=1&&px<=n&&py>=1&&py<=n)
				{
					if(clo[px][py]==0)
					{
						for(int o=0;o<4;o++)
						{
							int qx=px+dx[o];
							int qy=py+dy[o];
							if(qx>=1&&qx<=n&&qy>=1&&qy<=n&&clo[qx][qy]>0)
							{
								if(clo[qx][qy]==clo[i][j])v[qx][qy]=min_(v[qx][qy],v[i][j]+2);
								if(clo[qx][qy]!=clo[i][j])v[qx][qy]=min_(v[qx][qy],v[i][j]+3);
							}
						}
					}
					else
					{
						if(clo[i][j]==clo[px][py])v[px][py]=min_(v[px][py],v[i][j]);
						if(clo[i][j]!=clo[px][py])v[px][py]=min_(v[px][py],v[i][j]+1);
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		  if(v[i][j]>=100000)printf("_ ");else printf("%d ",v[i][j]);
//		printf("\n");
//	}
	if(v[n][n]==100000)printf("-1");
	  else printf("%d",v[n][n]);
	return 0;
}
