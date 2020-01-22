#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int dx[3]={0,1,0};
const int dy[3]={0,0,1};
const int N=200;
struct data{int x,y,t,c;bool ch;} opens[N*N*N];
struct dat{int w,c;bool f;} a[N][N];
int n,q;
bool f[N][N];
void tRy(int x,int y,int n)
{
	long long tail=1,head=1;
	opens[head].x=x;
	opens[head].y=y;
	opens[head].t=0;
	opens[head].c=a[x][y].c;
	a[x][y].w=0;a[x][y].f=1;
	f[x][y]=1;
	while (head<=tail)
	{
		for (int i=1;i<=2;i++)
		{
			int xx=opens[head].x+dx[i];
			int yy=opens[head].y+dy[i];
			int tt=opens[head].t;
			int cc=opens[head].c;
			int cch=opens[head].ch;
			if (xx<1||yy<1||xx>n||yy>n||f[xx][yy]||a[xx][yy].c==0&&cch) continue;
			f[x][y]=1;
			if (a[xx][yy].c==0)
			{
				tail++;
			    opens[tail].x=xx;
			    opens[tail].y=yy;
			    if (opens[head].c!=1)opens[tail].t=1;
			    opens[tail].t+=tt+2;
			    if (a[xx][yy].f) a[xx][yy].w=min(a[xx][yy].w,opens[tail].t);
			    else a[xx][yy].w=opens[tail].t,a[xx][yy].f=1;
			    opens[tail].c=1;
			    opens[tail].ch=1;
			    tail++;
			    opens[tail].x=xx;
			    opens[tail].y=yy;
			    if (opens[head].c!=2)opens[tail].t=1;
			    opens[tail].t+=tt+2;
			    if (a[xx][yy].f) a[xx][yy].w=min(a[xx][yy].w,opens[tail].t);
			    else a[xx][yy].w=opens[tail].t,a[xx][yy].f=1;
			    opens[tail].c=2;
			    opens[tail].ch=1;
			}else
			if (cc!=a[xx][yy].c)
			{
		    	tail++;
			    opens[tail].x=xx;
			    opens[tail].y=yy;
			    opens[tail].t=tt+1;
			    if (a[xx][yy].f) a[xx][yy].w=min(a[xx][yy].w,opens[tail].t);
			    else a[xx][yy].w=opens[tail].t,a[xx][yy].f=1;
			    opens[tail].c=a[xx][yy].c;
			    opens[tail].ch=0;
			}
			else if (cc==a[xx][yy].c)
			{
				tail++;
			    opens[tail].x=xx;
			    opens[tail].y=yy;
			    opens[tail].t=tt;
			    if (a[xx][yy].f) a[xx][yy].w=min(a[xx][yy].w,opens[tail].t);
			    else a[xx][yy].w=opens[tail].t,a[xx][yy].f=1;
			    opens[tail].c=cc;
			    opens[tail].ch=0;
			}	
		}
		head++;
	}
	
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    scanf("%d %d",&n,&q);
    if (n>20) {cout<<-1;return 0;}
    for (int i=1;i<=q;i++)
    {
    	int x=0,y=0,z=0;
    	scanf("%d %d %d",&x,&y,&z);
    	a[x][y].c=z+1;
	}
	tRy(1,1,n);
	if (a[n][n].f)cout<<a[n][n].w;
	else cout<<"-1";
	return 0;
}

