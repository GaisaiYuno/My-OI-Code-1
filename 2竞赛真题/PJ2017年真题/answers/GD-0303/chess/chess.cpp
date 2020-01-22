#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<iomanip>
#include<fstream>
using namespace std;
int n,m,map[105][105],xs,ys,cs,smcost=1234567;
bool k,f[105][105];
void findss(int x,int y,int cst,int yp)
{
	if(x==n&&y==n)
	{
		k=1;
		smcost=min(smcost,cst);
		return;
	}
	int xx,yy,cc;
	for(int i=1;i<=4;i++)
	{
		cc=cst;
		if(i==1){xx=x-1;yy=y;}
		if(i==2){xx=x+1;yy=y;}
		if(i==3){xx=x;yy=y-1;}
		if(i==4){xx=x;yy=y+1;}
		if(xx<1||xx>n||yy<1||yy>n||(map[xx][yy]==0&&yp==0)||f[xx][yy]==1)continue;
		if(map[xx][yy]!=map[x][y])cc++;
		else if(map[xx][yy]==0)cc+=2;
		
		f[xx][yy]=1;
		if(map[xx][yy]==0)
		{
			map[xx][yy]=1;
			findss(xx,yy,cc,0);
			map[xx][yy]=2;
			findss(xx,yy,cc,0);
			map[xx][yy]=0;
		}
		else findss(xx,yy,cc,1);
		f[xx][yy]=0;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>xs>>ys>>cs;
		if(cs==0)map[xs][ys]=1;
		if(cs==1)map[xs][ys]=2;
	}
	f[1][1]=1;
	if(map[1][1]==0)
	{
		map[1][1]=1;findss(1,1,2,0);
		map[1][1]=2;findss(1,1,2,0);
	}
	else findss(1,1,0,1);
	if(k==-1)cout<<smcost<<endl;
	else cout<<"-1"<<endl;
	return 0;
}

