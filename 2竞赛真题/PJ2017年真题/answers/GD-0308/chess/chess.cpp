#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int map[150][150];//��ͼ����ɫ
int m,n,ans = 3000000;
//�������߷�������ı�    ��  �� �� �� 
int wayx[5] = 			{0,-1,1,0,0},//������ 
	wayy[5] = 			{0,0,0,-1,1};//������

bool flag = 0;//�˳�������־ 
bool check[150][150];

void dfs(int xx,int yy,int coin,bool use)
{
	if(xx == m && yy == m)//�����յ�
	{
		ans = min(ans,coin);
		flag = 1;
	}
	else
	{
		int gox,goy;
		for(int i=1;i<=4;i++)//����ĸ�����
		{
			gox = xx+wayx[i];//Ŀ��������
			goy = yy+wayy[i];//Ŀ��������
			if(check[gox][goy] == 0 && gox <= m && gox >= 1 && goy <= m && goy >= 1)//û�߹���ûԽ�� 
			{
				
				if(map[gox][goy] == map[xx][yy])//����Ǯ
				{
					check[gox][goy] = 1;
					dfs(gox,goy,coin,0);
					check[gox][goy] = 0;
				}
					
				else if(map[gox][goy] == 1 && map[xx][yy] == 0)//��1Ԫ
				{
					check[gox][goy] = 1;
					dfs(gox,goy,coin+1,0);
					check[gox][goy] = 0;
					
				}	
				else if(map[gox][goy] == 0 && map[xx][yy] == 1)
				{
					check[gox][goy] = 1;
					dfs(gox,goy,coin+1,0);
					check[gox][goy] = 0;
				}	
				else if(use == 0 && map[gox][goy] == -1)//��2Ԫ
				{
					if(map[xx][yy] == 1)
					{
						map[gox][goy] = 1;
						dfs(gox,goy,coin+2,1);
					
						map[gox][goy] = 0;
						dfs(gox,goy,coin+3,1);
					}
					if(map[xx][yy] == 0)
					{
						map[gox][goy] = 1;
						dfs(gox,goy,coin+3,1);
					
						map[gox][goy] = 0;
						dfs(gox,goy,coin+2,1);
					}
					map[gox][goy] = -1;
				}
				
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int x,y,c;
	
	memset(map,-1,sizeof(map));//-1����û����ɫ
	memset(check,0,sizeof(check));//0����û�߹��ø�1�����߹��ø񣬲����ظ�·
	
	scanf("%d%d",&m,&n);
	
	for(int i=1;i<=n;i++)//n������ɫ�ĸ��� 
	{
		scanf("%d%d%d",&x,&y,&c);
		map[x][y] = c;//1�����ɫ��0�����ɫ
	}
	
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%3d ",map[i][j]);
		printf("\n");
	}*/
		
	check[1][1] = 1;
	dfs(1,1,0,0);
	
	if(flag)
		printf("%d",ans);
	else
		printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
