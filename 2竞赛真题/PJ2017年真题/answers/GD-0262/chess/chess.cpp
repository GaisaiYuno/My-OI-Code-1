#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define next next1
struct node{
	int x,y,c;
}point[1010];
struct edge{
	int to,next,vale;
}f[100010];
bool cmp(node x,node y)
{
	if (x.y==y.y) return x.x<y.x; 
	return x.y<y.y;
}
bool mp[110][110];
int n,m,tot,head[1010];
int rd()
{
	int f=1,y; char c;
	while ((c=getchar())>'9'||c<'0') if (c=='-') f=-1; y=c-'0';
	while ((c=getchar())<='9'&&c>='0') y=(y<<1)+(y<<3)+c-'0';
	return y*f;
}
void add(int x,int y,int c)
{
	f[++tot].to=y; 
	f[tot].vale=c;
	f[tot].next=head[x];
	head[x]=tot;
}
void spfa()
{
	queue<int>Q;
	int arr[1010],inq[1010];
	memset(arr,0x7f,sizeof(arr));
	memset(inq,false,sizeof(inq));
	Q.push(1); arr[1]=0; inq[1]=true;
	while (!Q.empty())
	{
		int now=Q.front();
		for (int i=head[now];~i;i=f[i].next)
		{
			int nex=f[i].to;
			if (arr[now]+f[i].vale<arr[nex]) 
			{
				arr[nex]=arr[now]+f[i].vale;
				if (!inq[nex])
				{
					Q.push(nex);
					inq[nex]=true;
				}
			}
		}
		inq[now]=false;
		Q.pop();
	}
	if (arr[m]==2139062143) puts("-1");
	else printf("%d",arr[m]);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	n=rd(); m=rd();
	memset(head,-1,sizeof(head));
	for (int i=1;i<=m;i++) 
	{
		int x=rd(),y=rd(),c=rd();
		point[i].x=x;
		point[i].y=y;
		point[i].c=c;
		mp[x][y]=true;
	}
	sort(point+1,point+1+m,cmp);
	if (!(point[m].x==n&&point[m].y==n)) 
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<m;i++)
		for (int j=i+1;j<=m;j++)
		{
			int c1=abs(point[i].x-point[j].x);
			int c2=abs(point[i].y-point[j].y);
			if (c1+c2==1) add(i,j,(point[i].c!=point[j].c)),add(j,i,(point[i].c!=point[j].c));
			if (c1+c2==2)
			{
				if (c1==2||c2==2)
				{
					int mx=(point[i].x+point[j].x)>>1,my=(point[i].y+point[j].y)>>1;
					if (!mp[mx][my]) 
						add(i,j,2+(point[i].c!=point[j].c)),add(j,i,2+(point[i].c!=point[j].c));
				}
				else
				{
					if (!mp[point[i].x][point[j].y]||!mp[point[i].y][point[j].x]) 
						add(i,j,2+(point[i].c!=point[j].c)),add(j,i,2+(point[i].c!=point[j].c));
				}
			}
		}
	spfa();
}
