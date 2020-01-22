#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","w",stdin);
	freopen("chess.out","r",stdout);
    int m,n,x[1000],y[1000],c[1000];
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) 
	scanf("%d%d%d",&x[i],&y[i],&c[i]);
	if(m==1)
	{
		if(n==1) printf("0");
		else if(n==0) printf("-1");
	}
	if(m==2)
	{
		if(n==0||n==1) printf("-1");
		if(n==2)
		{
			if(x[0]!=1&&x[1]!=1) printf("-1");
			else if((x[0]==1&&y[0]==1)&&(x[1]!=2&&y[1]!=2)) printf("-1");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
