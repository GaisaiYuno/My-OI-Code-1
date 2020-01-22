#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	  int x,y,z;
}p[1001];
int map[103][103];
int n,m,sum=0,ans=2147483647;
int i;
bool vis[103][103]={false};
bool cmp(node a,node b)
{
	   if(a.x==b.x)
	   {
	   	   return a.y<b.y;
	   }
	   return a.x<b.x;
}
void dfs(int x,int y)
{ 
       vis[x][y]=true;
       if(x==m&&y==m) 
       {
       	   ans=min(ans,sum);
       	   sum=0;
       	   return ;
       }
       if(x==0||x>m||y==0|y>m) return ;
	   if(map[x+1][y]==map[x][y]&&!vis[x+1][y])
	   {
	   	   dfs(x+1,y);
	   }
	   else 
	   {
	   	  if(map[x][y+1]==map[x][y]&&!vis[x][y+1])
	      {
	   	       dfs(x,y+1);
	      } 
	      else
	        {
	        	   if(!vis[x+1][y]&&map[x+1][y]!=-1)
	        	   {
	        	   	   sum++;
	        	   	   dfs(x+1,y);
	        	   }
	        	  else
				    {
				    	if(!vis[x][y+1]&&map[x][y+1]!=-1)
	        	        {
	        	   	        sum++;
	        	   	        dfs(x,y+1);
	        	         }
	        	         else
	        	            {
	        	            	   sum+=2;
	        	            	   map[x+1][y]=map[x][y];
	        	            	   dfs(x+1,y);
	        	            }
				    } 
	        }
	   }	   
}
int main()
{
	   freopen("chess.in","r",stdin);
	   freopen("chess.out","w",stdout);
	   scanf("%d%d",&m,&n);
	   memset(map,-1,sizeof(map));
	   for (i=1;i<=n;i++)
	   {
	   	    
	   	    scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
   	        map[p[i].x][p[i].y]=p[i].z; 
	   }
	   sort(p+1,p+n+1,cmp);
	   for (i=1;i<n;i++)
	   {
	   	   if(abs(p[i+1].x-p[i].x)>=2&&abs(p[i+1].y-p[i].y)>=2)
	   	   {
//	   	   	   printf("%d %d %d %d\n",p[i+1].x,p[i+1].y,p[i].x,p[i].y);
	   	   	   printf("-1");
	   	   	   return 0;
	   	   }
	   }
	   /*if(map[m-2][m]==-1&&map[m][m-2]==-1&&map[m-1][m-1]==-1) 
	   {
	   	   printf("-1");
	   	   return 0;
	   }*/
	   dfs(1,1);
	   printf("%d",ans);
	   return 0;
}
/*
5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0 
*/

/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/

/*
5 8
1 1 0
2 2 0
1 3 1
1 4 0
2 5 0
3 5 1
4 5 0
5 5 1
*/
