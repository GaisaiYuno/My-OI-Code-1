#include<cstdio>
#include<cstdlib>
#include<cstring>

int n,d,k;
int q[2010],w[2010];
int f[2010];
int minn=999999999,maxx=0;
int tot=0;
int ans=0;
int tt=0;

int abs(int x)
{
	if(x<0)return -x;
	return x;
}

int mymax(int x,int y)
{
	return x>y?x:y;
}

int mymin(int x,int y)
{
	return x>y?x:y;
}

int main()
{
//	freopen("jump.in","r",stdin);
//	freopen("test.out","w",stdout);
	memset(w,0,sizeof(w));
	memset(q,0,sizeof(q));
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i],&q[i]);
		if(q[i]>0)tot+=q[i];
		int x=abs(d-abs(w[i]-w[i-1]));
		if(minn>x)minn=x;
		if(w[i-1]<d && w[i]>=d)
		{
			tt=i;
		}
		if(tt==0 && i==n)
		{
			minn=d-w[i];
		}
	}
	if(tt!=0)minn=mymax(minn,mymax(d-w[tt-1],w[tt]-d));
	if(w[n]>d)maxx=mymax(d-1,w[n]-d);
	else maxx=d-1;
	if(tot<k)
	{
		printf("-1");
		return 0;
	}
	for(int i=minn;i<=maxx;i++)
	{
		for(int j=1;j<=n;j++)
		f[j]=-999999999;
		int l=d-i,r=d+i;
		if(l<=0)l=1;
		int t=0;
		while(t<=n)
		{
			int x=w[t],t1=t+1;
			int l1=x+l,l2=x+r;
			while(w[t1]<=l2 && t1<=n)
			{
				if(w[t1]>=l1)
				{
					f[t1]=mymax(f[t1],f[t]+q[t1]);
					if(f[t1]>=k)
					{
						printf("%d",i);
						return 0;
					}
				}
				t1++;
			}
			t++;
		}
	}
	system("pause");
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2

2


10 95 105
9 46
34 -2
51 -22
100 -32
104 -30
147 -34
167 -46
214 -24
235 38
251 50

86

10 1 100

*/
