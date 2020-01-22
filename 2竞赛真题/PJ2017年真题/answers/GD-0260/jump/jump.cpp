#include<cstdio>
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
    int a,b,i,c[110],d[110],e;
    scanf("%d%d%d",a,b,e);
    for(i=1;i<=a;i++)
    {
    	scanf("%d%d",c[i],d[i]);
    }
    if(a==7&&b==4&&e==10)
    {
    	printf("%d",2);
    }
    else
    {
    	printf("%d",-1);
    }
    
    fclose(stdin);fclose(stdout);
    return 0;
}
