#include<cstdio>
using namespace std;
int n,d,k,g,sum,x[500001],s[500001],l,r;
long long int Max[500001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&s[i]);
		if(s[i]>0)
			sum+=s[i];
	}
	if(sum<k)
	{
		printf("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	do
	{
		l=d-g;
		r=d+g;
		for(int i=1;i<=n;i++)
		{
			if(x[i]-x[i-1]<l)
			{
				g+=l-x[i]+x[i-1]-1;
				break;
			}
			else if(x[i]-x[i-1]>r)
			{
				g+=x[i]-x[i-1]-r-1;
				break;
			}
			Max[i]=-100000000001;
			for(int j=i-1;j>=0&&x[i]-x[j]<=r;j--)
				if(Max[i]<Max[j]+s[i])
					Max[i]=Max[j]+s[i];
			if(Max[i]>=k)
			{
				printf("%d",g-1);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}while(g++<d-1);
	printf("%d",g-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
