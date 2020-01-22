#include<iostream>
#include<cstdio>
using namespace std;
int dx[12]={1,-1,0,0,1,1,-1,-1,2,-2,0,0};
int dy[12]={0,0,1,-1,1,-1,-1,1,0,0,2,-2};
int m,n,a[200][200],anss;
void bfs()
{
	int t,w,fx[20000],fy[20000],b[200][200];
	t=0;
	w=1;
	fx[1]=1;
	fy[1]=1;
	b[1][1]=1;
	int ans[20000]={0};
	do
	{
	   t++;
	   for(int i=0;i<=11;i++)
	   {
	     int x=fx[t]+dx[i],y=fy[t]+dy[i];
	   	if(b[x][y]==0&&x<=m&&y<=m&&x>=1&&y>=1&&a[x][y]!=-1&&a[fx[t]][fy[t]]!=-1)   //满足不越界，当前位置本来不是白色，去的位置不是白色,且没有走过 
		   {
		    b[x][y]=1;
		   	w++;                                                       
		   	if(i>3) ans[w]=ans[t]+2;                             //使用魔法，直接加2 
		   	else 
		   	if(a[x][y]==a[fx[t]][fy[t]])ans[w]=ans[t]+0;         //不使用魔法，同色加0，异色加1 
		   	else ans[w]=ans[t]+1;
			fx[w]=x;fy[w]=y; 
			if(x==m&&y==m&&ans[w]<anss) {anss=ans[w];b[m][m]=0;}   
	        }
	    }
	   
	}
	while(t<w);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    anss=2147483640;
	cin>>m>>n;
	for(int i=1;i<=199;i++)
	for(int j=1;j<=199;j++) a[i][j]=-1;
	 for(int i=1;i<=n;i++)
	 {
	 	int x,y,c;
	 	cin>>x>>y>>c;a[x][y]=c;
	 }
	 bfs();
	 if(anss==2147483640) cout<<-1; else cout<<anss;
	fclose(stdin);fclose(stdout);
}
