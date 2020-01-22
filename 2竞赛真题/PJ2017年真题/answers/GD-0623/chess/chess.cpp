#include<cstdio>
#include<cstring>
using  namespace  std;
struct  node
{
	int  x,y,k,next;
}a[100000];
int  last[20000],n,m,len,list[5000000],st,ed,d[20000],b[200][200],head=1,tail=1;
int  dx[4]={-1,0,1,0};
int  dy[4]={0,1,0,-1};
bool  v[20000];
void  bt(int  x,int  y,int  k)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].k=k;
	a[len].next=last[x];last[x]=len;
}
int  main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(v,true,sizeof(v));v[1]=false;
	scanf("%d%d",&n,&m);
	st=1;ed=n*n;
	for(int  i=1;i<=m;i++)
	{
		int  x,y,z;scanf("%d%d%d",&x,&y,&z);
		z++;
		b[x][y]=z;
	}
	for(int  x=1;x<=n;x++)
	{
		for(int  y=1;y<=n;y++)
		{
			if(b[x][y]>0  &&  b[x][y]!=3)
			{
				for(int  j=0;j<=3;j++)
				{
					int  tx=x+dx[j],ty=y+dy[j];
					if(tx>=1  &&  tx<=n  &&  ty>=1  &&  ty<=n  &&  b[tx][ty]!=3)
					{
						if(b[x][y]==b[tx][ty])bt((x-1)*n+y,(tx-1)*n+ty,0);
						else  if(b[tx][ty]>0  &&  b[x][y]!=b[tx][ty])bt((x-1)*n+y,(tx-1)*n+ty,1);
						else  if(b[tx][ty]==0)
						{
							for(int  i=0;i<=3;i++)
							{
								int  ttx=tx+dx[i],tty=ty+dy[i];
								if(ttx>=1  &&  ttx<=n  &&  tty>=1  &&  tty<=n)
								{
									if(b[x][y]==b[ttx][tty])
									{
										bt((tx-1)*n+ty,(ttx-1)*n+tty,0);
										bt((ttx-1)*n+tty,(tx-1)*n+ty,2);
									}
									else  if(b[ttx][tty]>0  &&  b[x][y]!=b[ttx][tty])
									{
										bt((tx-1)*n+ty,(ttx-1)*n+tty,1);
										bt((ttx-1)*n+tty,(tx-1)*n+ty,2);
									}
								}
							}
							b[tx][ty]=3;
						}
					}
				}
			}	
		}
	}
	for(int  i=2;i<=n*n;i++)d[i]=999999999;
	list[tail]=1;
	while(head<=tail)
	{
		int  x=list[head];
		for(int  k=last[x];k>0;k=a[k].next)
		{
			int  y=a[k].y;
			if(d[x]+a[k].k<d[y])
			{
				if(v[y]==true)
				{
					list[++tail]=y;
					v[y]=false;
				}
				d[y]=d[x]+a[k].k;
			}
		}
		v[x]=true;
		head++;
	}
	if(d[n*n]==999999999)printf("-1\n");
	else  printf("%d\n",d[n*n]);
	return  0;
}
