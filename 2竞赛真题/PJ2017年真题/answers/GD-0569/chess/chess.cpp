#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int hs,sl,ys[110][110][5],ysg[1010][5],dis[110][110],zx[12]={1,-1,0,0,1,1,-1,-1,2,-2,0,0},zy[12]={0,0,1,-1,1,-1,1,-1,0,0,2,-2},my=0,cf[110][110];
void xz(int x,int y)
{
	int i,zlj,xx,xy;
	if(x==1&&y==1)
	{
		my=1;
		return;
	}
	else if(!ys[x][y][1])
	{
		for(i=0;i<=2;i+=2)
		{
			xx=x+zx[i];
			xy=y+zx[i];
			if(xx>=1&&xy>=1&&xx<=hs&&xy<=hs&&ys[xx][xy][1]&&!cf[xx][xy])
			{
				if(abs(xx)+abs(xy)==1)
					  zlj=0;
				else zlj=2;
				if(ys[x][y][1]!=ys[xx][xy][1])
					zlj++;
				if(ys[xx][xy][1]==0)
					zlj++;
				if(zlj+dis[x][y]<dis[xx][xy])
					dis[xx][xy]=zlj+dis[x][y];
				cf[xx][xy]=1;
				xz(xx,xy);
				cf[xx][xy]=0;
			}
		}
	}
	else for(i=0;i<12;i++)
	{
		xx=x+zx[i];
		xy=y+zx[i];
		if(xx>=1&&xy>=1&&xx<=hs&&xy<=hs&&ys[xx][xy][1]&&!cf[xx][xy])
		{
			if(abs(xx)+abs(xy)==1)
				  zlj=0;
			else zlj=2;
			if(ys[x][y][1]!=ys[xx][xy][1])
				zlj++;
			if(ys[xx][xy][1]==0)
				zlj++;
			if(zlj+dis[x][y]<dis[xx][xy])
				dis[xx][xy]=zlj+dis[x][y];
			cf[xx][xy]=1;
			xz(xx,xy);
			cf[xx][xy]=0;
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i=1,j,x,y;
	memset(dis,0x7fffffff,sizeof(dis));
	cin>>hs>>sl;
	dis[hs][hs]=0;
	for(i=1;i<=sl;i++)
	{
		cin>>x>>y;
		cin>>ys[x][y][1];
		ys[x][y][1]++;
		ysg[i][1]=x;
		ysg[i][2]=y;
		ysg[i][3]=ys[x][y][1];
		ys[x][y][2]=i;
	}
	xz(hs,hs);
	if(!my)
	{
		cout<<-1;
		return 0;
	}
	cout<<dis[1][1];
	fclose(stdin);
	fclose(stdout);
}
