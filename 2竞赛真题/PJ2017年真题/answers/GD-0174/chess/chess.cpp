#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int xx[5]={0,0,0,1,-1};
int yy[5]={0,1,-1,0,0};
int n,m,map[110][110],head,tail,a,b,c,ans,x,y,xz,yz;
int mapp[110][110];
struct www
{
	int x,y,k,c,ans;	
}o[10010];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){scanf("%d%d%d",&a,&b,&c);
		map[a][b]=c+1;
	}
	head=1;tail=1;
	o[1].x=1;
	o[1].y=1;
	o[1].k=0;
	o[1].c=map[1][1];
	o[1].ans=0;
	ans=n*n*2;
	while(head<=tail)
	{
		x=o[head].x;y=o[head].y;
		if(x==n&&y==n)
		{
			if(o[head].ans<ans)ans=o[head].ans;
		}
		for(int i=1;i<=4;i++)
		{
			xz=x+xx[i];yz=y+yy[i];
			if(xz<=0||yz<=0||xz>n||yz>n||mapp[xz][yz]==1)continue;
			if(map[xz][yz]!=o[head].c)
			{
				if(map[xz][yz]>0){
					tail++;
					o[tail].k=0;
					o[tail].x=xz;
					o[tail].y=yz;
					o[tail].c=map[xz][yz];
					o[tail].ans=o[head].ans+1;
					mapp[xz][yz]=1;
				}else 
				if(o[head].k==0)
				{
					tail++;
					o[tail].k=1;
					o[tail].x=xz;
					o[tail].y=yz;
					o[tail].c=o[head].c;
					o[tail].ans=o[head].ans+2;
					mapp[xz][yz]=1;
				}
			}else
			{
					tail++;
					o[tail].k=0;
					o[tail].x=xz;
					o[tail].y=yz;
					o[tail].c=o[head].c;
					o[tail].ans=o[head].ans;
					mapp[xz][yz]=1;
			}
		}
		head++;
	}
	if(ans==n*n*2)cout<<-1;else cout<<ans;
}
