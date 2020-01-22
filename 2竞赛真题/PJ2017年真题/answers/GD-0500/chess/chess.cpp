#include<cstring>
#include<cstdio>

struct nod{int x,y,c,v;bool bj;}a[10010];
int mp[110][110];
bool tf[110][110];
int fx[5]={0,-1,1,0,0};
int fy[5]={0,0,0,-1,1};

int mymin(int x,int y){return x<y?x:y;}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m;scanf("%d %d",&n,&m);
	memset(mp,0,sizeof(mp));
	memset(tf,true,sizeof(tf));
	for(int i=1;i<=m;i++)
	{
		int x,y,c;scanf("%d %d %d",&x,&y,&c);
		mp[x][y]=c+1;
	}
	int st=1,ed=2,ans=999999999;
	a[st].x=1;a[st].y=1;a[st].c=0;a[st].v=mp[1][1];a[st].bj=false;tf[1][1]=false;
	while(st<ed)
	{
		if(a[st].x==n&&a[st].y==n)ans=mymin(ans,a[st].c);
		else
		{
			for(int i=1;i<=4;i++)
			{
				int xx=a[st].x+fx[i],yy=a[st].y+fy[i];
				
				if(xx<1||xx>n||yy<1||yy>n||(a[st].bj&&mp[xx][yy]==0)||!tf[xx][yy])continue;
				
				if(mp[xx][yy]==0){a[ed].c=a[st].c+2;a[ed].v=a[st].v;a[ed].bj=true;}
				else
				{
					a[ed].v=mp[xx][yy];a[ed].bj=false;
					if(mp[xx][yy]!=a[st].v)a[ed].c=a[st].c+1;
					else a[ed].c=a[st].c;
				}
				
				a[ed].x=xx;a[ed].y=yy;a[ed].c=a[st].c+1;
				ed++;
			}
		}
		st++;
	}
	if(ans==999999999)printf("-1");else printf("%d",ans);
	return 0;
}
