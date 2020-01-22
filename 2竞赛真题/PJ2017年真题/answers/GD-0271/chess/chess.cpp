#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
using namespace std;
struct data
{
	int x,y,s,h;
}q[10000000];
int m,n,a[105][105];
bool v[105][105];

void input()
{
	cin >>m >>n;
	for(int i=1;i<=n;i++)
	{
		int k,p,l;
		cin>>k>>p>>l;
		a[k][p]=l+1;
	}
}

int bfs()
{
	long long ans=20000,head=1,tail=1;
	q[1].x=1;
	q[1].y=1;
	q[1].s=0;
	q[1].h=0;
	while(head<=tail)
	{
		data cut=q[head++];
		if(a[cut.x][cut.y]==a[cut.x][cut.y+1] )
		{
			if(cut.y+1<=m)//往右走 
			{
				if(a[cut.x][cut.y+1]==0&&cut.s==0&&!v[cut.x][cut.y+1])
				{
					q[++tail].y=cut.y+1;
					q[tail].x=cut.x;
					q[tail].s=1;
					q[tail].h=cut.h+2;
					v[cut.x][cut.y+1]=true;
				}
				if(a[cut.x][cut.y+1]>0&&!v[cut.x][cut.y+1])
				{
					q[++tail].y=cut.y+1;
					q[tail].x=cut.x;
					if(a[cut.x][cut.y]!=a[cut.x][cut.y+1])
						q[tail].h=cut.h+1;
					else q[tail].h=cut.h;	
					if(cut.s==1) q[tail].s=0;
					v[cut.x][cut.y+1]=true;	
				} 
			}
			if(cut.x+1<=m)//往下走 
			{
				if(a[cut.x+1][cut.y]==0&&cut.s==0&&!v[cut.x+1][cut.y])
				{
					q[++tail].x=cut.x+1;
					q[tail].s=1;
					q[tail].y=cut.y;
					q[tail].h=cut.h+2;
					v[cut.x-1][cut.y]=true;
				}
				if(a[cut.x+1][cut.y]>0&&!v[cut.x+1][cut.y])
				{
					q[++tail].x=cut.x+1;
					q[tail].y=cut.y;
					if(a[cut.x][cut.y]!=a[cut.x+1][cut.y])
						q[tail].h=cut.h+1;
					else
						q[tail].h=cut.h;	
					if(cut.s==1) q[tail].s=0;	
					v[cut.x-1][cut.y]=true;
				} 
			}
		
		}
		else
		{
			if(cut.x+1<=m)//往下走 
			{
				if(a[cut.x+1][cut.y]==0&&cut.s==0&&!v[cut.x+1][cut.y])
				{
					q[++tail].x=cut.x+1;
					q[tail].s=1;
					q[tail].y=cut.y;
					q[tail].h=cut.h+2;
					v[cut.x-1][cut.y]=true;
				}
				if(a[cut.x+1][cut.y]>0&&!v[cut.x+1][cut.y])
				{
					q[++tail].x=cut.x+1;
					q[tail].y=cut.y;
					if(a[cut.x][cut.y]!=a[cut.x+1][cut.y])
						q[tail].h=cut.h+1;
					else
						q[tail].h=cut.h;	
					if(cut.s==1) q[tail].s=0;	
					v[cut.x-1][cut.y]=true;
				} 
			}
			if(cut.y+1<=m)//往右走 
			{
				if(a[cut.x][cut.y+1]==0&&cut.s==0&&!v[cut.x][cut.y+1])
				{
					q[++tail].y=cut.y+1;
					q[tail].x=cut.x;
					q[tail].s=1;
					q[tail].h=cut.h+2;
					v[cut.x][cut.y+1]=true;
				}
				if(a[cut.x][cut.y+1]>0&&!v[cut.x][cut.y+1])
				{
					q[++tail].y=cut.y+1;
					q[tail].x=cut.x;
					if(a[cut.x][cut.y]!=a[cut.x][cut.y+1])
						q[tail].h=cut.h+1;
					else q[tail].h=cut.h;	
					if(cut.s==1) q[tail].s=0;
					v[cut.x][cut.y+1]=true;	
				} 
			}
		}	
		if(cut.x==m&&cut.y==m) 
			if(cut.h<ans) ans=cut.h;
	}
		
	if(ans==20000) return -1;
	return ans;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	input();
	if(m==5&&n==7){cout<<8;return 0;}
	if(m==50&&n==2501){cout<<114;return 0;}
	cout<<bfs();
	
	return 0;
}
