#include<cstdio>
#include<cstring>

int n,d,k;
struct node{int x,s;}a[500010];

int check(int x)
{
	int ne=0,sum=0,no=0,t=0;
	//printf("111 ");
	while(no<n)
	{
		//t=a[no+1].s;ne=no+1;
		int f=0,ff=0;
		for(int j=no+1;j<=n;j++)
		{
			if(x<d)
			{
				if(((a[j].x-a[no].x)<=(d+x))&&
				((a[j].x-a[no].x)>=(d-x)))
				{
					if(f==0)
					{
						t=a[j].s;ne=j;f=1;ff=1;
					}
					if(a[j].s>t)
					{
						t=a[j].s;
						ne=j;ff=1;
					}
				}
				//if((a[j].x-a[no].x)>=(d-x))
			}
			if(x>=d)
			{
				if(((a[j].x-a[no].x)<=(d+x))&&
				((a[j].x-a[no].x)>=1))
				{
					if(f==0)
					{
						t=a[j].s;ne=j;f=1;ff=1;
					}
					if(a[j].s>t)
					{
						t=a[j].s;
						ne=j;ff=1;
					}
				}
			}	
		}
		if(ff==1)
		{
			sum+=a[ne].s;
			no=ne;ne=0;
			if(sum>=k)return 1;
		}
		else return 0;
	}
	if(sum<k)return 0;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	a[0].x=0;a[0].s=0;
	scanf("%d%d%d",&n,&d,&k);
	int sum=0,tt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].s);
		if(a[i].s>0)sum+=a[i].s;
		if((a[i].x-a[i-1].x)>tt)
		{
			tt=a[i].x-a[i-1].x+2;
		}
	}
	if(sum<k)
	{
		printf("-1\n");return 0;
	}
	int l=1,r=tt;
	//printf("%d",tt);
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			//printf("%d ",mid);
			r=mid;
		}
		else l=mid+1;
	}
	printf("%d",l);
	/*/*for(int i=1;i<=tt;i++)
	{
		if(check(i)==1)
		{
			printf("%d",i);
			return 0;
		}
	}*/
}
/*
8 4 19
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
27 4

*/
