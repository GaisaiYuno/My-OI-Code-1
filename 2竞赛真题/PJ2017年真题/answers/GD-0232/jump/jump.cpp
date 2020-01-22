#include <cstdio>
using namespace std;
int i,n,d,k,kk=0,sum=0,ans=0,x[500002],s[500002];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	scanf("%d%d%d",&n,&d,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		if(s[i]>0) sum+=s[i];
	}
	if(sum<k) printf("-1");
	else
	{
		if(x[0])
		for(i=1;i<n;i++)
		{
			if(x[i]>=0)
			{
				if(x[i]-x[i-1]>d)
				{
					ans+=x[i]-x[i-1]-d;
					d=x[i]-x[i-1];
				}
			}
			else
			{
				i++;
				if(x[i]>=0)
				{
					if(x[i]-x[i-2]>d)
					{
						ans+=x[i]-x[i-2]-d;
						d=x[i]-x[i-2];
					}
				}
				else
				{
					i++;
					if(x[i]-x[i-3]>d)
					{
						ans+=x[i]-x[i-3]-d;
						d=x[i]-x[i-3];
					}
				}
			}
		}
		printf("%d",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
