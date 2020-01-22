#include<cstdio>
bool ce(int i,int j,int q)
{
	while(q--)
	{
		if(i%10!=j%10)	return false;
		i/=10;
		j/=10;
	}
	return true;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
 	int shu[1001],du[1001],lo[1001];
 	int s,d,ans1=10000001;
 	scanf("%d%d",&s,&d);
 	for(int i=0;i<s;i++)	scanf("%d",&shu[i]);
 	for(int i=0;i<d;i++)	scanf("%d%d",&lo[i],&du[i]);
 	for(int i=0;i<d;i++)
 	{
 		for(int j=0;j<s;j++)
 		{
 			if(ce(shu[j],du[i],lo[i])&&ans1>shu[j])
 			{
 				ans1=shu[j];
 			}
 		}
 		if(ans1==10000001)	printf("-1\n");
 		else
 		{
 			printf("%d\n",ans1);
 			ans1=10000001;
 		}
 	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
}
