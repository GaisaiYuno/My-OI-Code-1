#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
int n,m,x,y,z;
int tail,head,mina=200000000;
int dx[5]={0,0,-1,1},dy[5]={1,-1,0,0};
struct da
{
	int mina=200000000,k;
};
da a[105][105];
struct data
{
	int x,y,t,s;
};
data opens[2000000+50];
void pd(int p,int q)
{
	int pp,qq,tt;
	for(int i=0;i<=3;i++)
	{
		pp=p+dx[i];
		qq=q+dy[i];
		if(pp<1||qq<1||pp>n||qq>n) continue;
		if(a[pp][qq].k!=0&&a[pp][qq].k!=3)
		{
			if(a[pp][qq].k!=opens[head].s) tt=opens[head].t+3;
			else tt=opens[head].t+2;
			if(tt>=a[pp][qq].mina) continue;
			tail++;
			opens[tail].s=a[pp][qq].k;
			opens[tail].t=tt;
			opens[tail].x=pp;
			opens[tail].y=qq;
			a[pp][qq].mina=tt;
			if(pp==n&&qq==n)
			mina=min(tt,mina);
		}
	}
}
void f(int x,int y)
{
	int xx,yy,tt;
	tail=1,head=1;
	opens[1].x=x;opens[1].y=y;opens[1].t=0;opens[1].s=a[1][1].k;
	a[x][y].k=3;a[x][y].mina=3;
	while(head<=tail)
	{
		for(int i=0;i<=3;i++)
		{
			xx=opens[head].x+dx[i];
			yy=opens[head].y+dy[i];
			if(xx<1||yy<1||xx>n||yy>n||a[xx][yy].k==3) continue;
			if(a[xx][yy].k==0)
			{
				pd(xx,yy);
				continue;
			}
			if(a[xx][yy].k!=opens[head].s) tt=opens[head].t+1;
			else  tt=opens[head].t;
			if(tt>=a[xx][yy].mina) continue;
			tail++;
			opens[tail].x=xx;
			opens[tail].y=yy;
			opens[tail].t=tt;
			opens[tail].s=a[xx][yy].k;
			a[xx][yy].k=3;
			a[xx][yy].mina=tt;
			if(xx==n&&yy==n) 
			mina=min(tt,mina);
		}
		head++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if(z==1) a[x][y].k=1;
		else a[x][y].k=2;
	}
	f(1,1);
	if(mina<200000000) cout<<mina;
	else cout<<-1;
	return 0;
}
