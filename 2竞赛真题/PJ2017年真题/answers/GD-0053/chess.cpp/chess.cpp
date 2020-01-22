#include<cstdio>
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,i,m,j,cnt=0;
	scanf("%d%d",&m,&n);
	int a[1005][3];
	for(i=0;i<n;i++)
	    for(j=0;j<3;j++)
	        scanf("%d",&a[i][j]);
	for(i=0;i<n-1;i++)
	{
		if(a[i][0]==a[i+1][0]||a[i][1]==a[i+1][1])
		{
			if(a[i][2]!=a[i+1][2]) cnt++;
		}
		else 
		{
			if(a[i+1][0]-a[i][0]<=1&&a[i+1][1]-a[i][1]<=1) 
			{
				if(a[i][2]!=a[i+1][2]) cnt+=3;
				else cnt+=2;
			}
			else
			{
				cnt=-1;
				break;
			}
		}
	}
	printf("%d",cnt);
    fclose(stdin);
	fclose(stdout);
	return 0;
}
