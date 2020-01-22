#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,q,a[1010],b,c,e;
struct duzhe
{
  int bianhao,changdu;
}d[1010];
bool pan;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	 scanf("%d%d",&n,&q);
	 for(int i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	   sort(a+1,a+n+1);
	   for(int i=1;i<=q;i++)
	   {
	   	    scanf("%d%d",&d[i].changdu,&d[i].bianhao);
	   	     pan=false;
	   	   for(int j=1;j<=n;j++)
	   	    {
	   	       	if(d[i].bianhao==a[j]%10&&d[i].changdu==1)
	   	       	{
	   	       	  printf("%d\n",a[j]);
	   	       	  pan=true;
	   	       	  break;
	   	       	}
	   	       	if(d[i].bianhao==a[j]%100&&d[i].changdu==2)
	   	       	{
	   	       	  printf("%d\n",a[j]);
	   	       	  pan=true;
	   	       	  break;
	   	       	}
	   	       	if(d[i].bianhao==a[j]%1000&&d[i].changdu==3)
	   	       	{
	   	       	  printf("%d\n",a[j]);
	   	       	  pan=true;
	   	       	  break;
	   	       	}
	   	       	if(d[i].bianhao==a[j]%10000&&d[i].changdu==4)
	   	       	{
	   	       	  printf("%d\n",a[j]);
	   	       	  pan=true;
	   	       	  break;
	   	       	}
	   	       	 	if(d[i].bianhao==a[j]%100000&&d[i].changdu==5)
	   	       	{
	   	       	  printf("%d\n",a[j]);
	   	       	  pan=true;
	   	       	  break;
	   	       	}
	   	       	if(d[i].bianhao==a[j]%1000000&&d[i].changdu==6)
	   	       	{
	   	       	  printf("%d\n",a[j]);
	   	       	  pan=true;
	   	       	  break;
	   	       	}
	   	       	if(d[i].bianhao==a[j]%10000000&&d[i].changdu==7)
	   	       	{
	   	       	  printf("%d\n",a[j]);
	   	       	  pan=true;
	   	       	  break;
	   	       	}
	   	    }
	   	     if(!pan)
	   	      printf("-1\n");
	   }
	return 0;
}

