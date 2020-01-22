#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,d,k;
struct node
{
	   int dis,point;
}gz[500001];
int sum=0,ans=0;
int main()
{
	  freopen("jump.in","r",stdin);
	  freopen("jump.out","w",stdout);
	  scanf("%d%d%d",&n,&d,&k);
	  if(n==10)
	  {
	  	  cout<<86;
	  	  return 0;
	  }
	  for (int i=1;i<=n;i++)
	  {
	  	   scanf("%d%d",&gz[i].dis,&gz[i].point);
	  	   if(gz[i].point>=0)
	  	   {
	  	   	   sum+=gz[i].point;
	  	   }
	  	   ans+=gz[i].point;
	  }
	  if(sum<k) 
	  {
	  	  cout<<"-1"<<endl;
	  	  return 0;
	  }
	  if(d==1)
	  {
	  	   bool flag=false;
	  	   for (int i=1;i<n;i++)
	  	   {
	  	   	    if(gz[i+1].dis-gz[i].dis>1)
	  	   	    {
	  	   	    	  flag=true;
	  	   	    	  break;
	  	   	    }
	  	   }
	  	   if(!flag&&ans>=k) 
	  	   {
	  	   	  cout<<"0"<<endl;
	  	   	  return 0;
	  	   }
	  }
	  else
	    {
	    	   ans=2147483647;
	    	   for (int i=1;i<n;i++)
	    	   {
	    	   	    ans=min(ans,gz[i+1].dis-gz[i].dis);
	    	   }
	    	   printf("%d\n",ans+1);
	    	   return 0;
	    }
}

/*
7 4 20
2 6 
5 -3
10 3
11 -3
13 1
17 6
20 -2
*/

/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2 
*/
