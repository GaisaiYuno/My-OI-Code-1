#include<cstdio>
typedef struct point{
	int far;
	int score;
}P;
P *p;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,sum=0;
	scanf(" %d %d %d",&n,&d,&k);
	p=new P[n];
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d",&p[i].far,&p[i].score);
		if(p[i].score>=0)
		{
			sum+=p[i].score;
		}
	}
	if(sum<k)
	{
		printf("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
