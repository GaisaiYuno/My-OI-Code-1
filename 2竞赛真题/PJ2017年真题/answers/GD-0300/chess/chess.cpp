#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int n,m,x,y,c,map[101][101],mon[101][101],jud[101][101];
void find(int x,int y,int mag,int money)
{
	if (x<1||y<1||x>n||y>n) return;
	if (x==n && y==n) {mon[x][y]=min(money,mon[x][y]); return;}
	mon[x][y]=min(money,mon[x][y]);
	for (int i=1;i<=2;i++)
	 {
	 	if (i==1 && mag)
	 	 {
	 	 	for (int j=0;j<4;j++)
	 	 	 {
	 	 	   if (jud[x+dx[j]][y+dy[j]]==0 && mon[x+dx[j]][y+dy[j]]>money+2)
	 	 	    {
	 	 	    	jud[x+dx[j]][y+dy[j]]=1;	int tmp=map[x+dx[j]][y+dy[j]]; map[x+dx[j]][y+dy[j]]=map[x][y];
	 	 	    	find(x+dx[j],y+dy[j],0,money+2);
	 	 	        map[x+dx[j]][y+dy[j]]=tmp;
	 	 	    	jud[x+dx[j]][y+dy[j]]=0;	
	 	 	    }
	 	 	 }
	 	 	  
	 	 }
	 	if (i==2)
		 {
		 	for (int j=0;j<4;j++)
	 	 	 {
	 	 	   if (jud[x+dx[j]][y+dy[j]]==0 && map[x+dx[j]][y+dy[j]]>0 && mon[x+dx[j]][y+dy[j]]>money+1)
	 	 	    {
	 	 	    	if(map[x+dx[j]][y+dy[j]]==map[x][y] ||(mag==0 && map[x+dx[j]][y+dy[j]]==map[x][y]))
	 	 	    	 jud[x+dx[j]][y+dy[j]]=1,find(x+dx[j],y+dy[j],1,money);
	 	 	    	  else 
						 jud[x+dx[j]][y+dy[j]]=1,find(x+dx[j],y+dy[j],1,money+1);
	 	 	    	jud[x+dx[j]][y+dy[j]]=0;	
	 	 	    }
	 	 	 }
		 } 
	 }
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d%d%d",&x,&y,&c);
	 	map[x][y]=c+1;
	 }
	 for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	   mon[i][j]=2147483647;
	 
	 find(1,1,1,0);
	 
	 if (mon[n][n]!=2147483647) printf("%d\n",mon[n][n]);
	  else printf("-1\n");
	return 0;
}

