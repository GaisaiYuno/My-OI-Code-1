#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int m,n,chess[1005][1005],total=0;

bool back_test(int x,int y,bool m_s,int t_cost,int d=1)
{
	int tc=t_cost,tms=m_s;
	if(x==m&&y==m)
	{
		total=t_cost;
		return true;
	}
	else if(x==1&&y==1);
	else if(d==1)
	{
		if(!m_s&&chess[x][y]==-1)
		{
			return false;
		}
		else if(m_s&&chess[x][y]==-1)
		{
			tms=false;
			tc+=2;
		}
		else if(chess[x][y]==chess[x-1][y])
		{
			tms=true;
		}
		else if(chess[x][y]!=chess[x-1][y])
		{
			tms=true;
			tc+=1;
		}
	}
	else if(d==2)
	{
		if(!m_s&&chess[x][y]==-1)
		{
			return false;
		}
		else if(m_s&&chess[x][y]==-1)
		{
			tms=false;
			tc+=2;
		}
		else if(chess[x][y]==chess[x][y-1])
		{
			tms=true;
		}
		else if(chess[x][y]!=chess[x][y-1])
		{
			tms=true;
			tc+=1;
		}
	}
	else
	{
		return false;
	}
	if(!back_test(x+1,y,tms,tc,d))
	{
		d++;
		if(!back_test(x,y+1,tms,tc,d))
		{
			return false;
		}
	}
}

int main(void)
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int i=0;i<1005;i++)
	{
		for(int j=0;j<1005;j++)
		{
			chess[i][j]=-1;
		}
	}
	int tpx,tpy,c;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",tpx,tpy,c);
		chess[tpx][tpy]=c;
	}
	if(!back_test(1,1,1,0))total=-1;
	cout<<total;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
