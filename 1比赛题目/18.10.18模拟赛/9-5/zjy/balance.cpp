#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define maxn 100005
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N;
struct node{
	int x,y;
	friend bool operator < (node a,node b)
	{
		return a.x<b.x;
	}
}point[maxn];
int anss=0x3f3f3f3f;
int solve(int x,int y)
{
	int ans[5],mx=0;
	for(int i=0;i<=4;i++)
		ans[i]=0;
	for(int i=1;i<=N;i++)
	{
		if(point[i].x<x)
		{
			if(point[i].y>y)
				ans[4]++;
			else
				ans[1]++;
		}else{
			if(point[i].y>y)
				ans[3]++;
			else
				ans[2]++;
		}
	}
	//cout<<"note: ";
	for(int i=1;i<=4;i++)
	{
		if(ans[i]>ans[mx])
			mx=i;
		//cout<<ans[i]<<" ";
	}
	anss=min(anss,ans[mx]);
	return ans[mx];
}
int stx,sty;
int mAx,mAy,mix,miy;
void fire()
{
	double T=999999999999;
	const double delt=0.96;
	int x=stx,y=sty;
	while(T>=0.0000001)
	{
		int t=solve(x,y);
		T*=delt;
		if(solve(x+1,y)>t){
			x++;
			continue ;
		}
		if(solve(x-1,y)>t){
			x--;
			continue ;
		}
		if(solve(x,y+1)>t){
			y++;
			continue ;
		}
		if(solve(x,y-1)>t){
			y--;
			continue ;
		}
		if((rand()*rand())%110<T)
		{
			x=(rand()*rand())%mAx;
			y=(rand()*rand())%mAy;
			continue ;
		}
	}
}
void work()
{
	for(int i=0;i<mAx;i+=2)
		for(int j=0;j<mAy;j+=2)
			solve(i,j);
}
int main()
{
	
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	read(N);
	srand(time(NULL));
	mAx=0,mAy=0,mix=0x3f3f3f3f,miy=0x3f3f3f3f;
	for(int i=1;i<=N;i++)
	{
		read(point[i].x);
		read(point[i].y);
		int x=point[i].x;
		int y=point[i].y;
		mAx=max(mAx,x);
		mAy=max(mAy,y);
		mix=max(mix,x);
		mix=max(miy,y);
	}
	if(N<=10000)
	{
		work();
		cout<<anss;
		return 0;
	}	
	stx=mix+mAx>>1;
	sty=miy+mAy>>1;
	fire();
	cout<<anss;
}
