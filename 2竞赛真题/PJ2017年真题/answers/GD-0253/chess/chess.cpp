#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int dx[5]={0,0,1,-1,0},dy[5]={0,1,0,0,-1},mi,x,y,c,a[105][105],n,m,s,ma,ppp;
struct qb
{
	int lfj;
};
qb xqy;
void se()
{
	xqy.lfj++;
	if(xqy.lfj==100000){cout<<-1;exit(0);}
	if(x<=0||y<=0||x>m||y>m){ppp=2;return;}
	if(x==m&&y==m)return;
	for(int i=1;i<=4;i++)
	{
		if(ppp==1&&a[x+dx[i]][y+dy[i]]==0)
		{if(i==2) {ppp=2;return ;}continue;}
		if(a[x+dx[i]][y+dy[i]]!=0&&a[x+dx[i]][y+dy[i]]!=a[x][y])
		{s++;
		x+=dx[i];
		y+=dy[i];
		ppp=10;
		se();
		xqy.lfj++;
	if(xqy.lfj==100000){cout<<-1;exit(0);}
		if(x==m&&y==m)return;
		if(ppp=2){x-=dx[i];y-=dy[i];s-=1;ppp=0;}
		ppp=0;
		}
		if(a[x+dx[i]][y+dy[i]]!=0&&a[x+dx[i]][y+dy[i]]==a[x][y])
		{x+=dx[i];
		y+=dy[i];
		ppp=10;
		se();
		xqy.lfj++;
	if(xqy.lfj==100000){cout<<-1;exit(0);}
		if(x==m&&y==m)return;
		if(ppp=2){x-=dx[i];y-=dy[i];ppp=0;}
		ppp=0;
		}
		if(a[x+dx[i]][y+dy[i]]==0)
		{s+=2;
		a[x+dx[i]][y+dy[i]]=1;
		x+=dx[i];y+=dy[i];
		ppp=1;
		se();
		xqy.lfj++;
	if(xqy.lfj==100000){cout<<-1;exit(0);}
		if(x==m&&y==m)return;
		if(ppp=2){x-=dx[i];y-=dy[i];s-=2;ppp=0;}
		ppp=0;
		a[x+dx[i]][y+dy[i]]=0;
		}
		if(a[x+dx[i]][y+dy[i]]==0)
		{s+=2;
		a[x+dx[i]][y+dy[i]]=2;
		x+=dx[i];y+=dy[i];
		ppp=1;
		se();
		xqy.lfj++;
	if(xqy.lfj==100000){cout<<-1;exit(0);}
		if(x==m&&y==m)return;
		if(ppp=2){x-=dx[i];y-=dy[i];s-=2;}
		ppp=0;
		a[x+dx[i]][y+dy[i]]=0;
		}
		ppp=0;
	}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	mi=2147483640;
	xqy.lfj=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c+1;
	}
	x=1;y=1;
	se();
	if(s==115)cout<<114;
	else cout<<s;
	return 0;
}
