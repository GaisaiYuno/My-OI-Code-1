#include<cstdio>
#include<cstring>
int x[500100],s[500100];	
long long  f[501000];
int n,d,k,max=0;
long long sum=0;
long long maxx(long long x,long long y) { return x>y?x:y; } 
long long che(int g)
{
	memset(f,0,sizeof(f));
	if(g>=d)
	{
		for(int i=1;i<=max;i++)
		{
			for(int j=d;j<=d+g;j++)
			{
				int l=0;
				for(int o=1;o<=n;o++) if(x[o]==i-j) l=s[o];
				f[j]=maxx(f[i-j]+l,f[j]);
			}
		}
		return f[max]; 
	}
	else
	{
		for(int i=1;i<=max;i++)
		{
			for(int j=d-g;j<=d+g;j++)
			{
				int l=0;
				for(int o=1;o<=n;o++) if(x[o]==i-j) l=s[o];
				f[j]=maxx(f[i-j]+l,f[j]);
			}
		}
		return f[max]; 
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&s[i]);
		if(s[i]>0)	sum+=s[i]; 
		if(s[i]>max) max=s[i];
	}
	//sum : max
	if(sum<k) { printf("-1"); return 0; }
	//printf("%I64d",sum);
	int an=0;
	for(int g=0;g<=n-d;g++)
	{
		long long na=che(g);
		if(na>=k)
			an=g;	 
	}
	printf("%d",an);
	return 0;
}
/*
7 4 20
2 6 
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
