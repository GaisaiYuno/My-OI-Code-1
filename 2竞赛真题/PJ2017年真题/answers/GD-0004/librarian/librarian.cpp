#include <cstdio>
#include <cstring>

int n,m;
int a[1010];
int f[9]={1,1,10,100,1000,10000,100000,1000000,10000000};
void kk(int x,int y)
{
	int l=x,r=y;
	int mid=a[(x+y)/2];
	while(l<=r)
	{
		while(a[l]<mid)l++;
		while(a[r]>mid)r--;
		if(l<=r)
		{
			int t=a[l];
			a[l]=a[r];
			a[r]=t;
			l++;r--;
		}
	}
	if(l<y)kk(l,y);
	if(x<r)kk(x,r);
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	kk(1,n);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		bool v=false;
		int ans=0;
		for(int j=n;j>=1;j--)
		{
			if(a[j]<y)break;
			if((a[j]-y)%f[x+1]==0)
			{
				v=true;
				ans=a[j];
			}
			
		}
		if(v)printf("%d\n",ans);
		else printf("-1\n");
	}
}
