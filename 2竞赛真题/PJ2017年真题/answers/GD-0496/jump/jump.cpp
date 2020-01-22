#include<cstdio>
using namespace std;
int s[500000]={0};
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,speed,hope,ans=0,i,juli,score;
	scanf("%d%d%d", &n, &speed, &hope);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d", &juli, &score);
		s[juli]=score;
	}
	while(ans<hope && i<=n)
	{
		if(s[i]>0)
		ans+=s[i];
		i++;
	}
	if(ans<hope) printf("-1");
	else 
	{
		printf("%d", i-speed/2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
