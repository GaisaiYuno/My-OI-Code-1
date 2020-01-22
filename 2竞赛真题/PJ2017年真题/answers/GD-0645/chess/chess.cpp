#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1e9,qmove[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
struct node{
	int co,money,r;
	bool f;
}k[105][105];
struct nod{
	int u,v;
}s;
int M,N;
queue<nod> que;
queue<nod> qu2;
queue<nod> qu3;
void dfs(int x,int y)
{
	int m,n;k[x][y].r=2;
	for(int i=0;i<4;i++)
	{
		m=x+qmove[i][0];
		n=y+qmove[i][1];
		if(m>=0&&m<M&&n>=0&&n<M&&k[m][n].co==k[x][y].co&&k[x][y].r==0)
		{
		//	printf(">>%d %d\n",m,n);
			s.u=m;s.v=n;que.push(s);
			dfs(m,n);
		}
	}
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int a,b,c,count=0;
	scanf("%d %d",&M,&N);
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++) 
		{
			k[i][j].r=0;k[i][j].money=INF;k[i][j].co=-1;k[i][j].f=false;
		}
	while(N--)
	{
		scanf("%d %d %d",&a,&b,&c);
		k[a-1][b-1].co=c;
	}
	k[0][0].money=0;s.u=s.v=0;
	que.push(s);
	while(!(que.empty()&&qu2.empty()&&qu3.empty()))
	{
		if(que.empty())
		{
			count++;
			while(!qu2.empty()) 
			{
				que.push(qu2.front());
				qu2.pop();
			}
			while(!qu3.empty()) 
			{
				qu2.push(qu3.front());
				qu3.pop();
			}
		}
		a=que.front().u;b=que.front().v;que.pop();
		if(k[a][b].r==1) continue;//printf("%d %d %d %d\n",a,b,k[a][b].co,count);
		k[a][b].r=1;k[a][b].money=count;
		if(k[a][b].co<2)
		{
			dfs(a,b);
			for(int i=0;i<4;i++)
			{
				s.u=a+qmove[i][0];s.v=b+qmove[i][1];
				if(s.u>=0&&s.u<M&&s.v>=0&&s.v<M&&k[s.u][s.v].r==0)
				{
					if(k[s.u][s.v].co>=0) qu2.push(s);
					if(k[s.u][s.v].co==-1&&k[s.u][s.v].f==false)
					{
						k[s.u][s.v].co=k[a][b].co+2;
						k[s.u][s.v].f=true;
						qu3.push(s);
					}
				}
			}
		}
		else
		{
		//	printf("*\n");
			k[a][b].co-=2;
			for(int i=0;i<4;i++)
			{
				s.u=a+qmove[i][0];s.v=b+qmove[i][1];
				if(s.u>=0&&s.u<M&&s.v>=0&&s.v<M&&k[s.u][s.v].r==0&&k[s.u][s.v].co>=0)
				{
					if(k[s.u][s.v].co==k[a][b].co) que.push(s);
					else qu2.push(s);
				}
			}
			k[a][b].co=-1;
		}
		if(k[M-1][M-1].r!=0) 
		{
			printf("%d",count);
			break;
		}
	}
	if(k[M-1][M-1].r==0) printf("-1");
	fclose(stdin);fclose(stdout);
	return 0;
}
