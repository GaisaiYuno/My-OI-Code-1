#include<cstdio>
#include<queue>

using namespace std;

struct position
{
	int x, y;
	position(int a ,int b)
	{
		x = a;
		y = b;
	}
};

queue<position> searchlist;
int m, n, x, y, pointcolor;
int color[105][105];
bool full[105][105];
int destition[105][105];
int way[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void search()
{
	position point = searchlist.front();
	searchlist.pop();
	for (int i = 0 ; i < 4 ; i++)
	{
		int money = 0;
		int nextx = point.x + way[i][0] ,nexty = point.y + way[i][1];
		
		if (full[point.x][point.y] == false && full[nextx][nexty] == false) continue;
		if (full[nextx][nexty] == false) 
		{
			if (destition[nextx][nexty] > destition[point.x][point.y] + 2)
			{
				destition[nextx][nexty] = destition[point.x][point.y] + 2;
				color[nextx][nexty] = color[point.x][point.y];
				searchlist.push(position(nextx, nexty));
			}
			continue;
		}
		
		if (color[nextx][nexty] != color[point.x][point.y]) money = 1;
		
		if (destition[nextx][nexty] > destition[point.x][point.y] + money)
		{
			destition[nextx][nexty] = destition[point.x][point.y] + money;
			searchlist.push(position(nextx, nexty));
		}
	}	
	if (searchlist.empty()) return;
	else search();
}

//无可奈何的手动初始化 
void init(int a)
{
	for (int i = 0 ; i <= a + 1; i++)
	 for (int j = 0 ; j <= a + 1; j++)
	  destition[i][j] = -1;
	for (int i = 1 ; i <= a; i++)
	 for (int j = 1 ; j <= a; j++)
	 {
	 	destition[i][j] = 9999999;
	 }
	  
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d %d",&m,&n);	
	init(m);	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &pointcolor);
		color[x][y] = pointcolor;
		full[x][y] = true;
	}
	
	destition[1][1] = 0;
	searchlist.push(position(1, 1));
	search();	
	
	if (destition[m][m] == 9999999) printf("-1");
	else printf("%d",destition[m][m]); 
	
	return 0;
}
