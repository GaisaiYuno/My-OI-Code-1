#include <iostream>
#include <cstdio>
#include <algorithm>

#define MaxN 100+5

#define InpF "chess.in"
#define OutF "chess.out"

int min(int x,int y)
{
	if(x<y) return x;
	return y;
}

int main()
{
	freopen(InpF,"r",stdin);
	freopen(OutF,"w",stdout);
	int Bac[MaxN][MaxN];
	int Map[MaxN][MaxN];
	int f[MaxN][MaxN];
	f[1][1]=0;
	
	int m,n;
	scanf("%d%d",&m,&n);

	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
		{
			Map[i][j]=-1;
			Bac[i][j]=-2;			
		}

	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		Map[x][y]=z;
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i==1)&&(j==1)) continue;
			int colorPrice[2];
			if(Map[i][j]!=-1)
			{
				if(Map[i][j]==Map[i-1][j]) colorPrice[0]=0;
				else if((Map[i-1][j]==-1)&&(Bac[i-1][j]==Map[i][j])) colorPrice[0]=0;
				else colorPrice[0]=1;
				if(Map[i][j]==Map[i][j-1]) colorPrice[1]=0;
				else if((Map[i][j-1]==-1)&&(Bac[i][j-1]==Map[i][j])) colorPrice[1]=0;
				else colorPrice[1]=1;
			}
			else if(Map[i][j]==-1)
			{
				if(Map[i-1][j]==-1) colorPrice[0]=-1;
				else colorPrice[0]=2;
				if(Map[i][j-1]==-1) colorPrice[1]=-1;
				else colorPrice[1]=2;
			}
			if(((colorPrice[0]==-1)||(f[i-1][j]==-1))&&((colorPrice[1]==-1)||(f[i][j-1]==-1)))
			{
				f[i][j]=-1;
				continue;
			}
			else if(Map[i][j]==-1)
			{
				if((colorPrice[0]==-1)||(f[i-1][j]==-1))
				{
					Bac[i][j]=Map[i][j-1];
					f[i][j]=f[i][j-1]+colorPrice[1];
				}
				else if((colorPrice[1]==-1)||(f[i][j-1]==-1))
				{
					Bac[i][j]=Map[i-1][j];
					f[i][j]=f[i-1][j]+colorPrice[0];
				}
				else if(f[i-1][j]+colorPrice[0]<=f[i][j-1]+colorPrice[1])
				{
					Bac[i][j]=Map[i-1][j];
					f[i][j]=f[i-1][j]+colorPrice[0];
				}
				else
				{
					Bac[i][j]=Map[i][j-1];
					f[i][j]=f[i][j-1]+colorPrice[1];
				}
			}
			else if((colorPrice[0]==-1)||(f[i-1][j]==-1)) f[i][j]=f[i][j-1]+colorPrice[1];
			else if((colorPrice[1]==-1)||(f[i][j-1]==-1)) f[i][j]=f[i-1][j]+colorPrice[0];
			else f[i][j]=min(f[i-1][j]+colorPrice[0],f[i][j-1]+colorPrice[1]);
		}
	}
	printf("%d\n",f[m][m]);
	return 0;
}
