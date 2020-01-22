#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q,i,j,ans=2147483647;
int book[1001],xqm[1001],len[1001];
int s[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	  freopen("librarian.in","r",stdin);
	  freopen("librarian.out","w",stdout);
	  scanf("%d%d",&n,&q);
	  for (i=1;i<=n;i++)
	  {
	  	  scanf("%d",&book[i]);
	  }
	  for (i=1;i<=q;i++)
	  {
	  	  scanf("%d%d",&len[i],&xqm[i]);
	  }
	  for (i=1;i<=q;i++)
	  {
	  	   ans=2147483647;
	  	   for (j=1;j<=n;j++)
	  	   {
	  	   	   int cha=book[j]-xqm[i];
	  	   	   if(cha<0) continue;
	  	   	   if(len[i]==1)
	  	   	   {
	  	   	   	    if(cha%s[1]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   }
	  	   	   if(len[i]==2)
	  	   	   {
	  	   	   	    if(cha%s[2]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   }
	  	   	   if(len[i]==3)
	  	   	   {
	  	   	   	    if(cha%s[3]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   }
	  	   	   if(len[i]==4)
	  	   	   {
	  	   	   	    if(cha%s[4]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   }
	  	   	   if(len[i]==5)
	  	   	   {
	  	   	   	    if(cha%s[5]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   }
	  	   	   if(len[i]==6)
	  	   	   {
	  	   	   	    if(cha%s[6]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   }
	  	   	   if(len[i]==7)
	  	   	   {
	  	   	   	    if(cha%s[7]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   } 
	  	   	   if(len[i]==8)
	  	   	   {
	  	   	   	    if(cha%s[8]==0)
	  	   	   	    {
	  	   	   	    	  ans=min(ans,book[j]);
	  	   	   	    }
	  	   	   }
	  	   }
	  	   if(ans==2147483647) ans=-1;
		   printf("%d\n",ans);
	  }
	  return 0;
}
/*
5 5 
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
*/
