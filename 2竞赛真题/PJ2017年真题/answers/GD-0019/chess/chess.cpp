# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <string>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
struct data
{
	int x,y,mf,q,bs;
};
data map[1000000+5];
int h,t,p[1000+5][1000+5],n,m,a,b,c,r,o[1000+5][1000+5],w;
int  mi=50000000;
void se(int k)
{
   h++;
   t++;
   map[1].x=1;
   map[1].y=1;
   map[1].q=0;
   map[1].mf=0;
   map[1].bs=1;
   o[1][1]=1;
   while (h<=t)
   {
    for (int i=0; i<=3;i++)
    {
    	int x=map[h].x+dx[i];
    	int y=map[h].y+dy[i];
    	if (map[h].bs-1>w)  w++;
    	if (x<1||y<1||x>n|y>n||o[x][y]==w) continue;
    	if (p[x][y]==p[map[h].x][map[h].y]&&p[x][y]!=-1&&o[x][y]==-1)
    	{
    		if (x==n&&y==n) { mi=min(mi,map[h].q); r=1; continue; }
    		o[x][y]=map[h].bs+1;
    		t++;
    		map[t].x=x;
    		map[t].y=y;
    		map[t].q=map[h].q;
    		if (map[h].mf==1)
			{
			 map[t].mf=0;
			 p[map[h].x][map[h].y]=-1;
		   }
    		map[t].bs=map[h].bs+1;
    		continue;
    	}
    	if (p[x][y]!=-1&&p[x][y]!=p[map[h].x][map[h].y]&&o[x][y]==-1)
    	{
    		if (x==n&&y==n) {mi=min(mi,map[h].q+1);r=1; continue; } 
    		o[x][y]=map[h].bs+1;
			t++;
    		map[t].x=x;
    		map[t].y=y;
    		map[t].q=map[h].q+1;
    		if (map[h].mf==1)
			{
			 map[t].mf=0;
			 p[map[h].x][map[h].y]=-1;
		   }
    		map[t].bs=map[h].bs+1;
    		continue;
    	}
    	if (p[x][y]!=p[map[h].x][map[h].y]&&p[x][y]==-1&&map[h].mf==0&&o[x][y]==-1)
    	{
    		if (x==n&&y==n) {mi=min(mi,map[h].q+2);r=1; continue; } 
    		o[x][y]=map[h].bs+1;
    		t++;
    		map[t].x=x;
    		map[t].y=y;
    		map[t].q=map[h].q+2;
    		map[t].mf=1;
    		p[x][y]=p[map[h].x][map[h].y];
    		map[t].bs=map[h].bs+1;
    		continue;
    	}
    } 
   	h++;
   }
}
int main()
{
	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++)
	 for (int j=1; j<=n; j++)
	 {
	    p[i][j]=-1;
	    o[i][j]=-1;
	 }
	for (int i=1; i<=m; i++)
	{
        cin>>a>>b>>c;
        p[a][b]=c;
	}
	se(1);
	if (r==0) cout<<-1<<endl;
	else cout<<mi<<endl;
	return 0; 
}
