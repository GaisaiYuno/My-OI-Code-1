#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#define maxn 300
#define yep cout<<"yep"<<endl;
using namespace std;
inline void read(double &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
double N,W;
double w[maxn],t[maxn];
struct node{
	int u[maxn];
	double f;
	void cal()
	{
		double wt=0,tt=0;
		for(int i=1;i<=N;i++)
			if(u[i])
				wt+=w[i],tt+=t[i];
		if(wt<W)
			f=-1;
		else
			f=tt/wt;
	}
	friend bool operator < (node a,node b)
	{
		return a.f>b.f;
	}
}group[1005];
inline void getnew(int x)
{
	for(int i=1;i<=N;i++)
		group[x].u[i]=rand()%2;
	group[x].cal();
}
node fuck(node fa,node ma)
{
	int c;
	node child;
	for(int i=1;i<=N;i++)
	{
		c=rand()%2;
		if(c)
			child.u[i]=fa.u[i];
		else
			child.u[i]=ma.u[i];
	}
	child.cal();
	return child;
}
int main()
{
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	srand(time(NULL));
	read(N);read(W);
	double tw=0,tt=0;
	for(int i=1;i<=N;i++){read(w[i]);read(t[i]);}
	int T=400;
	for(int i=1;i<=T;i++)	
	{
		while(group[i].f<=0)
			getnew(i);
	}
	for(int i=1;i<=T;i++)
	{
		sort(group+1,group+T+1);
		for(int i=T/2+1;i<=T;i++)
			group[i]=fuck(group[i-T/2],group[i-T/2+1]);
	}
	sort(group+1,group+T+1);
	double ans;
	ans=group[1].f;
	ans*=1000;
	printf("%d",int(ans));
}
