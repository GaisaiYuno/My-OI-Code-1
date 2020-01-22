#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n,a,score,s[2][501],tol=0;
bool pa(int k)
{
	int i=1;int ans=s[2][1];
	while(1)
	{
	    if(i>n)
	    break;
		int j=i+1;
		while(s[2][j]>=0)
		{
			j++;
		}
		if(s[1][j]-s[1][i]>=a+k ||s[1][j]-s[1][i]<=abs(a-k))
		{
			i++;
		}else{
			i=j;
	    }
		ans+=s[2][i];
    }
    if(ans>score)
    {
    	return true;
    }else{
    	return false;
    }
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    scanf("%d %d %d",&n,&a,&score);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d %d",&s[1][i],&s[2][i]);
	}
    for(int i=1;i<=500;i++)
    {
   		if(pa(i))
    	{
   		printf("2");
   		return 0;
   		}
   	}
    printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
