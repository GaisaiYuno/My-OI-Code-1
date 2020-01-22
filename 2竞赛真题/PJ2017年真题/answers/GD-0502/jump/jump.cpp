#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

void readin()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
}

struct hh{
	int d,dis,num;
}a[500100],b[500100];
int n,d1,k,cnt,tot1,tot,maxn,minn,ans;
int d[500100];

bool cmp(hh a,hh b)
{
	if(a.num==b.num)
		return a.d>b.d;
	return a.num<b.num;
}

int main()
{
	readin();
	cnt=0,tot=0,tot1=0,maxn=-1,minn=2139062143;
	scanf("%d%d%d",&n,&d1,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].dis,&a[i].num);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].num>0) cnt+=a[i].num,d[++tot1]=a[i].dis;
		if(a[i].num<0)
		{
			b[++tot].num=a[i].num;
			int k=i+1;
			while(true)
				if(a[k].num>0)
					break;
				else
				 	k++;
			b[tot].d=max(a[k].dis-a[i].dis,a[i].dis-d[tot1]);
			b[tot].dis=a[i].dis;
		}	
	}
	if(cnt<k)
	{
		puts("-1");
		return 0;
	}
	else
	{
		sort(b+1,b+tot+1,cmp);
		int cnt1=cnt;
		for(int i=1;i<=tot;i++)
		{
			if(cnt1+b[i].num>k)
			{
				cnt1+=b[i].num;
				d[++tot1]=b[i].dis;
			}
		}
		sort(d+1,d+tot1+1);
		/*for(int i=1;i<=tot1;i++)
			printf("%d ",d[i]);
		puts("");*/
		d[0]=0;
		for(int i=1;i<=tot1;i++)
		{
			maxn=max(d[i]-d[i-1],maxn);
			//minn=min(d[i]-d[i-1],minn);
		}
		int ans=maxn-d1;//,ans2=d1-minn;
		/*if(ans1<d1&&ans2>=d1)
		{
			puts("-1");
			return 0;
		}
		if(ans1>d1&&ans2<=d1) ans=min(ans1,ans2);
		if(ans1>=d1) ans=ans1;
		if(ans2<d1) ans=ans2;*/
		if(ans<=0)
			puts("0");
		else
			if(ans<d1)
				printf("%d\n",ans+1);
			else
				printf("%d\n",ans);
	}
	return 0;
}
