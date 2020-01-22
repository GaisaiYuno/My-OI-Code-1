#include<cstdio>
typedef struct point{
	int x,y,c;
}P;
P *p;
int g[100][100];
int side1[2][2]={{0,1},{1,0}};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,i,j,sum=0;
	scanf(" %d %d",&m,&n);
	p=new P[n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			g[i][j]=-1;
		}
	}
	for(i=0;i<n;i++)
	{
		scanf(" %d %d %d",&p[i].x,&p[i].y,&p[i].c);
		g[p[i].x-1][p[i].y-1]=p[i].c;
	}
	i=0;j=0;
	while(i<m&&j<m)
	{
		int s,t;
		for(s=0;s<2;s++)
		{
			if(g[i+side1[s][0]][j+side1[s][1]]==g[i][j])
			{
				i+=side1[s][0];
				j+=side1[s][1];
				break;
			}
		}
		if(s!=2)
		{
			continue;
		}
		for(s=0;s<2;s++)
		{
			if(g[i+side1[s][0]][j+side1[s][1]]>=0)
			{
				i+=side1[s][0];
				j+=side1[s][1];
				sum++;
				break;
			}
		}
		if(s!=2)
		{
			continue;
		}
		sum+=2;
		if(g[i+1][j+1]==g[i][j])
		{
			i++;j++;continue;
		}
		if(g[i+1][j+1]>=0)
		{
			i++;j++;sum++;continue;
		}
		printf("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
