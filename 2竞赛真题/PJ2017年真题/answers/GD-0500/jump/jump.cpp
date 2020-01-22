#include<cstring>
#include<cstdio>

int a[5000100];
int f[5000100];
int x,y,len;

int mymax(int x,int y){return x>y?x:y;}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;scanf("%d %d %d",&n,&d,&k);
	int sum=0;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		int x,s;scanf("%d %d",&x,&s);
		a[x]=s;
		if(i==n)len=x;
		if(s>0)sum+=s;
	}
	if(sum<k){printf("-1");return 0;}
	x=y=d;
	int ans=2;
	while(1)
	{
		int xx,yy;
		if(ans<d)xx=d-ans;else xx=1;
		yy=d+ans;
		for(int i=0;i<=len;i++)
		{
			for(int j=xx;j<=yy;j++)if(a[i+j]!=0)f[i+j]=mymax(f[i]+a[i+j],f[i+j]);
			if(f[i]>=k){printf("%d",ans);return 0;}
		}
		ans++;
	}
}
