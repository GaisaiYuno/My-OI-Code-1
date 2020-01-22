#include<cstdio>
#include<iostream>
using namespace std;
struct data{int x,y,m,last,z;};
data opens[1000005];
int xx[4]={0,0,-1,1},yy[4]={-1,1,0,0},n,m,x,y,z,a[105][105],b[105][105],Min=2147483647;
void find()
{
	int head=0,tail=0;
	opens[0].x=opens[0].y=b[1][1]=1;opens[0].m=0;opens[0].last=a[1][1];
	while (head<=tail)
	{
		int n1=opens[head].x,m1=opens[head].y,x,y;
		for (int i=0;i<4;i++)
		{
			x=opens[head].x+xx[i];y=opens[head].y+yy[i];
			if (x<1||y<1||x>n||y>n||b[x][y]==1)continue;
			if (a[x][y]==-1&&opens[head].z==-1)continue;
			tail++;b[x][y]++;
			opens[tail].x=x;opens[tail].y=y;opens[tail].last=a[x][y];
			if (opens[head].last!=a[x][y])
			 {
			 	if (a[x][y]!=-1){opens[tail].m=opens[head].m+1;}else
				 {
				   opens[tail].m=opens[head].m+2;
				   opens[tail].z--;
				   opens[tail].last=opens[head].last;
				}
			 }else opens[tail].m=opens[head].m;
			 if (x==n&&y==n){Min=min(opens[tail].m,Min);}
		}
		head++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)a[i][j]=-1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	find();
	if (Min==2147483647)Min=-1;
	printf("%d\n",Min);
	return 0;
}
