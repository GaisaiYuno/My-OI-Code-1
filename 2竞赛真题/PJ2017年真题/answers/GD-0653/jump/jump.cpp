#include<cstdio>
#include<cstdlib>
#include<cstring>
int n,d,k;
int x[500010],s[500010],f[500010];//f[i]表示到达格子i的最大值 
int l,r;

int max(int xx,int yy)
{
	return xx>yy?xx:yy;
}

bool tfz(int g)
{
	int c=0;
	int zx,zd;
	if (g<d) zx=d-g;
	else zx=1;
	zd=d+g;
	int t=0;
	/*printf("zx=%d zd=%d\n",zx,zd);
	system("pause");*/
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		bool tf=false;
		f[i]=f[t];
		for (int j=t;j<i;j++)
		{
			if (x[i]-x[j]<zx)
			{
				tf=true;
				break;
			}
			else if (x[i]-x[j]>zd)
			{
				t=j+1;
				f[i]=f[t];
				continue;
			}
			/*printf("i=%d j=%d f[i]=%d f[j]=%d\n",i,j,f[i],f[j]);
			system("pause");*/
			f[i]=max(f[i],f[j]);
		}
		if (tf==false) f[i]+=s[i];
		//printf("c=%d i=%d f[i]=%d\n",c,i,f[i]);
		if (f[i]>c) c=f[i];
	}
	/*printf("c=%d\n",c);
	system("pause");*/
	if (c>=k) return true;
	return false;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	int sum=0,ex;
	int ans=-1;
	x[0]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&s[i]);
		if (s[i]>0)
		{
			sum+=s[i];
			ex=x[i];
		}
	}
	if (sum<k)
	{
		printf("-1\n");
		return 0;
	}
	l=1,r=ex-d;
	while (l<=r)
	{
		int mid=(l+r)/2;
		//printf("mid=%d\n",mid);
		//system("pause");
		if (tfz(mid)==true)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d",ans);
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
