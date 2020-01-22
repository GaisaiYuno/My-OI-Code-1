/*我相信暴力出奇迹*/
/*O()过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register int
#define fast static int
using namespace std;
typedef long long ll;
typedef const int cint;
int read()
{
	re x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
static cint Size=100005;
static cint MapSize=2005;
static cint INF=0x3f3f3f3f;
int h,w,p,q,cnt,head[Size];
int x[Size],y[Size];
char a[MapSize][MapSize];
int id[MapSize][MapSize];
void init()
{
	h=read();
	w=read();
	p=read();
	q=read();
	for(int i=1; i<=h; i++)
	{
		gets(a[i]+1);
	}
	for(int i=1; i<=p; i++)
	{
		x[i]=read();
		y[i]=read();
		id[x[i]][y[i]]=i;
	}
}
static cint dx[] = {1,0,0,-1};
static cint dy[] = {0,1,-1,0};
struct node
{
	int x,y,t,maxt;
} Queue[MapSize*MapSize];
int Qhead,Qtail,ans=INF,dist[MapSize][MapSize];
void PushQueue(int x,int y,int t)
{
	Qtail++;
	Queue[Qtail].x=x;
	Queue[Qtail].y=y;
	Queue[Qtail].t=t;
}
void bfs(int spos,int tpos)
{
	memset(dist,0x3f,sizeof(dist));
	Qhead=Qtail=0;
	PushQueue(x[spos],y[spos],0);
	while(Qhead<=Qtail)
	{
		int x=Queue[++Qhead].x;
		int y=Queue[Qhead].y;
		int t=Queue[Qhead].t;
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nt=t+1;
			if(id[nx][ny])	nt=0;
			if(nx>0 && ny>0 && nx<=h && ny<=w && a[nx][ny]!='#' && nt<dist[nx][ny])
			{
				PushQueue(nx,ny,nt);
				Queue[Qtail].maxt=max(Queue[Qhead].maxt,nt);
				if(id[nx][ny]==tpos && Queue[Qtail].maxt<ans)
				{
					ans=Queue[Qtail].maxt;
				}
				dist[nx][ny]=Queue[Qtail].maxt;
			}
		}
	}
}
int main()
{
	freopen("kettle.in","r",stdin);
	freopen("kettle.out","w",stdout);
	init();
	for(int i=1; i<=q; i++)
	{
		int s=read();
		int t=read();
		ans=INF;
		bfs(s,t);
		printf("%I64d\n",ans);
	}
	return 0;
}
/*
5 5 4 4
.....
..##.
.#...
..#..
.....
1 1
4 2
3 3
2 5

1 2
2 4
1 3
3 4
*/
