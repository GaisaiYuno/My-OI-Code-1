#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int map[150][150];//地图的颜色
int m,n,ans = 3000000;
//建立行走方向坐标改变    上  下 左 右 
int wayx[5] = 			{0,-1,1,0,0},//行坐标 
	wayy[5] = 			{0,0,0,-1,1};//列坐标

bool flag = 0;//退出搜索标志 
bool check[150][150];

void dfs(int xx,int yy,int coin,bool use)
{
	if(xx == m && yy == m)//到达终点
	{
		ans = min(ans,coin);
		flag = 1;
	}
	else
	{
		int gox,goy;
		for(int i=1;i<=4;i++)//浏览四个方向
		{
			gox = xx+wayx[i];//目标行坐标
			goy = yy+wayy[i];//目标列坐标
			if(check[gox][goy] == 0 && gox <= m && gox >= 1 && goy <= m && goy >= 1)//没走过，没越界 
			{
				
				if(map[gox][goy] == map[xx][yy])//不花钱
				{
					check[gox][goy] = 1;
					dfs(gox,goy,coin,0);
					check[gox][goy] = 0;
				}
					
				else if(map[gox][goy] == 1 && map[xx][yy] == 0)//花1元
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
				else if(use == 0 && map[gox][goy] == -1)//花2元
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
	
	memset(map,-1,sizeof(map));//-1代表没有颜色
	memset(check,0,sizeof(check));//0代表没走过该格，1代表走过该格，不走重复路
	
	scanf("%d%d",&m,&n);
	
	for(int i=1;i<=n;i++)//n个有颜色的格子 
	{
		scanf("%d%d%d",&x,&y,&c);
		map[x][y] = c;//1代表黄色，0代表红色
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
