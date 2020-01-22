#include<cstdio>
#include<cstdlib>
#include<cstring>

int n,k,min_ans=2147483647,minf;
int a[110][110];
struct node
{
	int x,y,d,f;
	bool tf=true;
}q[10010];
bool b[110][110];
int fx[4]={-1,0,1,0};
int fy[4]={0,1,0,-1};

int min(int x,int y) {return x<y?x:y;}

void bfs()
{
	int head=1,tail=2;
	q[head].x=1;q[head].y=1;q[head].d=0;q[head].f=0;
	while (head!=tail)
	{
		for (int k=0;k<4;k++)
		{
			int xx=q[head].x+fx[k];
			int yy=q[head].y+fy[k];
			if (xx<=0 || xx>n || yy<=0 || yy>n || b[xx][yy]==false) continue;
			if (a[xx][yy]==a[q[head].x][q[head].y] && a[xx][yy]!=-1)
			{
				q[tail].y=yy;
				q[tail].x=xx;
				q[tail].d=q[head].d;
				if (q[head].tf==false) a[q[head].x][q[head].y]=-1;
				q[tail].tf=true;
				q[tail].f=head;
				b[xx][yy]=false;
				if (xx==n && yy==n) min_ans=min(min_ans,q[tail].d),minf=q[tail].f;
				tail++;
				continue;
			}
			else if (a[xx][yy]!=-1)
			{
				q[tail].y=yy;
				q[tail].x=xx;
				q[tail].d=q[head].d+1;
				if (q[head].tf==false) a[q[head].x][q[head].y]=-1;
				q[tail].tf=true;
				q[tail].f=head;
				b[xx][yy]=false;
				if (xx==n && yy==n) min_ans=min(min_ans,q[tail].d),minf=q[tail].f;
				tail++;
				continue;
			}
			else if (q[head].tf && a[xx][yy]==-1)
			{
				q[tail].y=yy;
				q[tail].x=xx;
				q[tail].d=q[head].d+2;
				a[xx][yy]=a[q[head].x][q[head].y];
				q[tail].tf=false;
				q[tail].f=head;
				b[xx][yy]=false;
				if (xx==n && yy==n) min_ans=min(min_ans,q[tail].d),minf=q[tail].f;
				tail++;
				continue;
			}
		}
		head++;
	}
	if (min_ans!=2147483647) printf("%d",min_ans);
	else printf("-1");
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,-1,sizeof(a));
	memset(b,true,sizeof(b));
	scanf("%d %d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c;
	}
	bfs();
	return 0;
}
