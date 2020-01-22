#include <iostream>
#include <cstdio>
using namespace std;

int dx[5],dy[5];
int mc[205][205],chess[205][205],n,m;
bool boo[205][205];
struct F
{
	int x,y,cost,c;
	bool um;
}f[100000];
void BFS()
{
	int w=0,num=1,c=0;
	f[num].x=1; f[num].y=1; f[num].cost=0; f[num].um=false,f[num].c=chess[1][1];
	do
	{
		w++;
		for (int i=0; i<4; i++)
		{
			int p=f[w].x+dx[i],q=f[w].y+dy[i];
			if (p>=1&&p<=n&&q>=1&&q<=m)
			{
				if (boo[p][q]==false)
				{
					int c=9999999; bool b=false;
					if (f[w].c==chess[p][q]&&chess[p][q]!=-1&&f[w].c!=-1) c=f[w].cost,b=true;
					  else 
					    if (chess[p][q]==-1&&f[w].um==false) c=f[w].cost+2,b=true;
					      else if (chess[p][q]!=-1&&f[w].c!=chess[p][q]) b=true,c=f[w].cost+1;
					if (b==true) mc[p][q]=c;
					if (b==true) num++,f[num].cost=c,f[num].x=p,f[num].y=q,f[num].um=false,f[num].c=chess[p][q];
					if (b==true&&chess[p][q]==-1) f[num].c=f[w].c; 
					if (chess[p][q]==-1) f[num].um=true;
					if (chess[p][q]!=-1&&chess[p][q]!=f[w].c&&f[num].um==false) num++,f[num].cost=c,f[num].x=q,f[num].y=q,f[num].um=true,f[num].c=(f[w].c+1)%2;
					if (b==true) boo[p][q]=true;
			    }
			    else
				if (boo[p][q]==true)
				{
					int c=9999999; bool b=false;
					if (f[w].c==chess[p][q]&&chess[p][q]!=-1&&f[w].c!=-1) c=f[w].cost,b=true;
					  else 
					    if (chess[p][q]==-1&&f[w].um==false) c=f[w].cost+2,b=true;
					      else if (chess[p][q]!=-1) b=true,c=f[w].cost+1;
					if (b==true&&c<mc[p][q])
					{
						mc[p][q]=c;
						for (int i=w; i<=num; i++)
						  if (f[i].x==p&&f[i].y==q&&f[i].um==false) f[i].cost=c;
					}
				}
			}
		}
	}while (w<num);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	dx[0]=1; dx[1]=0; dx[2]=-1; dx[3]=0;
	dy[0]=0; dy[1]=1; dy[2]=0; dy[3]=-1;
	memset(chess,-1,sizeof(chess));
	memset(boo,false,sizeof(boo));
	memset(f,0,sizeof(f));
	for (int i=1; i<=m; i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		chess[a][b]=c;
	}
	for (int i=1; i<=n; i++)
	  for (int j=1; j<=n; j++)
	    mc[i][j]=9999999;
	BFS();
	if (mc[n][n]!=9999999)cout<<mc[n][n]<<endl; else cout<<-1<<endl;
	/*for (int i=1; i<=n; i++)
	{
	  for (int j=1; j<=n; j++)
	    if (chess[i][j]!=-1) cout<<chess[i][j]<<' '; else cout<<3<<' ';
	cout<<endl;
	}
	cout<<(sizeof(mc)+sizeof(chess)+sizeof(f)+sizeof(boo))/(1024*1024);*/
	return 0;
}
