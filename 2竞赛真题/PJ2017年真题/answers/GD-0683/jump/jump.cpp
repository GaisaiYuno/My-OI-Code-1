#include<cstdio>
using namespace std;
struct gz
{
	int di,sc;
}gg[500001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,dis,sco,s=0,g=0,i,he=0;
	int ans[500001];
	scanf("%d %d %d",&n,&d,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%d %d",&dis,&sco);
		gg[i].di=dis;gg[i].sc=sco;
		
		if (sco>0) s=s+sco;
	}
	if (s<k) printf("-1");
	else
	{
		for (i=1;i<=n;i++)
		{
			if (gg[i].di %d==0) he=he+gg[i].sc;
			if (he==k) 
			{
			    printf ("0");
			    return 0;
		    }
		}
		printf("1");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
