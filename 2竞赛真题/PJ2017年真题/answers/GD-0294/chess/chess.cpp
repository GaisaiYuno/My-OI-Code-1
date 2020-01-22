#include <iostream>
#include <fstream>

using namespace std;

bool blocks[110][110]; /*Call the police when the array has blew up*/
bool colorful[110][110]; /*Has color or not*/
bool visit[110][110]={false};

int movex[]={1,0};
int movey[]={0,1};

int result=9999999;

bool mogic=false; /*Use the MOGIC or not (true = used)*/

int m,n;

inline void input()
{
	cin>>m>>n;
	for (int i=0;i<n;i++)
	{
		int xx,yy,tmp;
		cin>>xx>>yy>>tmp;
		blocks[xx][yy]=tmp;
		colorful[xx][yy]=true;
	}
	return ;
}

int min(int num[])
{
	int result=99999;
	for (int i=0;i<4;i++)
		if (num[i]<result) result=num[i];
	return result;
}

void money(int x,int y,int used) //Deep Dark Mogical Function
{
	//limits and return conditions 
	if (x==m and y==m)
	{
		if (used<=result) result=used;
		return ;
	}
	if (x>m or y>m) return ;
	if (x<1 or y<1) return ;
	int backup;
	
	//process
	for (int i=0;i<2;i++)
	{
		int nextx=x+movex[i];
		int nexty=y+movey[i];
		
		if (colorful[nextx][nexty] and blocks[x][y]==blocks[nextx][nexty])
		{
			mogic=false;
			money(nextx,nexty,used);
		}
		else if (colorful[x+movex[i]][y+movey[i]])
		{
			mogic=false;
			money(nextx,nexty,used+1);	
		}
		else if (mogic==false)	
		{
			mogic=true;
			colorful[nextx][nexty]=true;
			
			backup=blocks[nextx][nexty];
			blocks[nextx][nexty]=blocks[x][y];
			
			money(nextx,nexty,used+2);
			
			colorful[nextx][nexty]=false;
			blocks[nextx][nexty]=backup;
			mogic=false;
		}
	}
	return ;
}

int main()
{
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	
	input();
	money(1,1,0);
	
	if (result==9999999)
		cout<<-1;
	else
		cout<<result<<endl;
		
	return 0;
}
