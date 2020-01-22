#include<cstdio>

const int maxn=500000+2;
int n,d,k,dis,sco;
int house[maxn],score[maxn];
int i,j,p,q,sum=0;

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for(i=0;i<n;i++){
		scanf("%d %d",&dis,&sco);
		if(sco>0)sum+=sco;
		score[dis]=sco;
	}
	if(sum<k)printf("-1");
	
	
	
	
	
	printf("-1");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
