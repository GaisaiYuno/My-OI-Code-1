#include<cstdio>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,x[50001],ss,s[50001],maxx=0,minn,step,now,anss;
	scanf("%d%d%d",&n,&d,&k);
	for(int i=0;i<=50000;i++)
		s[i]=-100001;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&ss);
		s[x[i]]=ss;
		if(s[x[i]]>0)
			maxx+=s[x[i]];
	}
	if(maxx<k)
	{
		printf("-1");
		return 0;
	}
	else
	{
		for(int i=1;i<d;i++)
		{
			anss=0;
			now=0;
			do{
				maxx=-100001;
				if(d+i<x[n]-now)
					minn=d+i;
				else
					minn=x[n]-now;
				for(int j=d-i;j<=minn;j++)
				{
					if(s[now+j]>maxx)
					{
						step=j;
						maxx=s[now+j];
					}
				}
				anss+=maxx;
				if(anss>=k)
				{
					printf("%d",i);
					return 0;
				}
				now+=step;
			}while(now<x[n]);
		}
		for(int i=d;i<=x[n];i++)
		{
			anss=0;
			now=0;
			do{
				maxx=-100001;
				if(d+i<x[n]-now)
					minn=d+i;
				else
					minn=x[n]-now;
				for(int j=1;j<=minn;j++)
				{
					if(s[now+j]>maxx)
					{
						step=j;
						maxx=s[now+j];
					}
				}
				anss+=maxx;
				if(anss>=k)
				{
					printf("%d",i);
					return 0;
				}
				now+=step;
			}while(now<x[n]);
		}
		printf("-1");
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}
