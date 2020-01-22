#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,qp[101][101],x,y,c,money=0,hzb=1,zzb=1;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m+1;i++)
		for(int j=1;j<=m+1;j++)
			qp[i][j]=666;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		qp[x][y]=c;
	}
	if(m==1)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		do{
			if(hzb<m&&qp[hzb+1][zzb]==qp[hzb][zzb])
				hzb++;
			else
			{
				if(zzb<m&&qp[hzb][zzb+1]==qp[hzb][zzb])
					zzb++;
				else
				{
					if(hzb<m&&qp[hzb+1][zzb]<2)
					{
						hzb++;
						money++;
					}
					else
					{
						if(zzb<m&&qp[hzb][zzb+1]<2)
						{
							zzb++;
							money++;
						}
						else
						{
							if(hzb<m)
							{
								hzb++;
								if(qp[hzb+1][zzb]>2&&qp[hzb][zzb+1]>2)
								{
									hzb--;
									if(zzb<m)
									{
										zzb++;
										if(qp[hzb+1][zzb]>2&&qp[hzb][zzb+1]>2)
										{
											printf("-1");
											return 0;
										}
										qp[hzb][zzb]=qp[hzb][zzb-1];
									}
								}
								else
									qp[hzb][zzb]=qp[hzb-1][zzb];
							}
							else
							{
								if(zzb<m)
								{
									zzb++;
									if(qp[hzb][zzb+1]>2)
									{
										printf("-1");
										return 0;
									}
									qp[hzb][zzb]=qp[hzb][zzb-1];
								}
								else
								{
									printf("-1");
									return 0;
								}		
							}
							money+=2;
						}
					}
				}		
			}
			if(hzb==m&&zzb==m)
			{
				printf("%d",money);
				return 0;
			}	
		}while(hzb!=m||zzb!=m);
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
