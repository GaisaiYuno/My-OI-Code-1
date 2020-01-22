#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;

const int xxxx[5]={-2,1,0,-1,0},yyyy[5]={-2,0,1,0,-1};

struct node
{
	int x;
	int y;
	bool colorchange;
	int money;
	int wait;
	int lastcolor;
}tmp,temp;

queue <node> q;

int n,m;
int a[1010][1010];
bool pc[1010][1010];
int mapcolor;

inline bool check_go(int xxx,int yyy)
{
	if(xxx<=0||xxx>n||yyy<=0||yyy>n||pc[xxx][yyy]==false)
	{
		return false;
	}
	
	return true;
}

int main(void)
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	memset(a,-1,sizeof(a));
	memset(pc,true,sizeof(pc));
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;++i)
	{
		int x,y,color;
		
		scanf("%d%d%d",&x,&y,&color);
		
		a[x][y]=color;
	}
	
	tmp.x=1;tmp.y=1;tmp.money=0;tmp.wait=0;tmp.colorchange=false;pc[1][1]=false;
	q.push(tmp);
	
	while(!q.empty())
	{
		tmp=q.front();q.pop();
		if(tmp.wait>0)
		{
			--tmp.wait;
			q.push(tmp);
			continue;
		}
		
		if(tmp.x==n&&tmp.y==n)
		{
			printf("%d\n",tmp.money);
			
			return 0;
		}
		
		
		if(tmp.colorchange==true)
		{
			mapcolor=a[tmp.x][tmp.y];
			a[tmp.x][tmp.y]=tmp.lastcolor;
		}
		
		
		for(int i=1;i<=4;++i)
		{
			temp=tmp;
			
			temp.x=tmp.x+xxxx[i];temp.y=tmp.y+yyyy[i];
			if(check_go(temp.x,temp.y)==false) continue;
			if(a[temp.x][temp.y]==a[tmp.x][tmp.y]) temp.wait=0;//相同颜色 
			if(a[tmp.x][tmp.y]==-1)//白色转入 
			{
				temp.wait=1;
				temp.money=tmp.money+1;
			}
			if( ((a[temp.x][temp.y]==0)&&(a[tmp.x][tmp.y]==1)) || ((a[temp.x][temp.y]==1)&&(a[tmp.x][tmp.y]==0)) )
			{ 
				temp.wait=1;
				temp.money=tmp.money+1;
			}//不同颜色 
			temp.colorchange=false;
			if(a[temp.x][temp.y]==-1)
			{ 
				if(tmp.colorchange!=false)
				{
					continue;
				}
				temp.wait=2;
				temp.money=tmp.money+2;
				temp.colorchange=true;
				temp.lastcolor=a[tmp.x][tmp.y];
			}//白色 
			
			pc[temp.x][temp.y]=false;
			//cout<<tmp.x<<" "<<tmp.y<<"->"<<temp.x<<" "<<temp.y<<" Cost:"<<temp.money<<endl; //DEBUG
			q.push(temp); 
		}
		
		if(tmp.colorchange==true)
		{
			a[tmp.x][tmp.y]=mapcolor;
		}
	}
	
	printf("-1\n");
	
	return 0;
}
