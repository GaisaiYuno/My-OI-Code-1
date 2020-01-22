#include <iostream>
#include <cstdio>
#include <cstring>
#define oo 0x3f3f3f
using namespace std;
int n,m,x,y,c;  
int biao[150][150],f[150][150],fmap[150][150];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
     memset(f,oo,sizeof(f));
	 scanf("%d%d",&n,&m);
     for(int i=1;i<=m;i++)
	 {
	 	scanf("%d%d%d",&x);
	 	scanf("%d%d%d",&y);
	 	scanf("%d%d%d",&c);
	     biao[x][y]=c+1;
	     fmap[x][y]=c+1;
     }
     f[1][1]=0;
     for(int i=2;i<=n;i++)
      {
      	if(biao[1][i]==biao[1][i-1]&&biao[1][i]!=0)
      	  f[1][i]=min(f[1][i],f[1][i-1]);
      	else if(biao[1][i]!=0&&biao[1][i-1]!=0) f[1][i]=min(f[1][i],f[1][i-1]+1);
      	if(biao[1][i]!=biao[1][i-1]&&biao[1][i]==0&&fmap[1][i-1]!=0)
		 f[1][i]=min(f[1][i],f[1][i-1]+2),biao[1][i]=biao[1][i-1]; 
      }
    for(int i=2;i<=n;i++)
      {
      	if(biao[i][1]==biao[i-1][1]&&biao[i-1][1]!=0)
      	  f[i][1]=min(f[i][1],f[i-1][1]);
      	else if(biao[i][1]!=0&&biao[i-1][1]!=0) f[i][1]=min(f[i][1],f[i-1][1]+1);
      	if(biao[i][1]!=biao[i-1][1]&&biao[i][1]==0&&fmap[i-1][1]!=0)
		 f[i][1]=min(f[i][1],f[i-1][1]+2),biao[i][1]=biao[i-1][1]; 
      }
     for(int i=2;i<=n;i++)
       for(int j=2;j<=n;j++)
        {
        if(biao[i-1][j]==biao[i][j]&&biao[i][j]!=0) 
		f[i][j]=min(f[i][j],f[i-1][j]);
      	else if(biao[i][j]!=0&&biao[i-1][j]!=0) f[i][j]=min(f[i][j],f[i-1][j]+1);
      	
		if(biao[i][j-1]==biao[i][j]&&biao[i][j]!=0) 
		f[i][j]=min(f[i][j],f[i][j-1]);
      	else if(biao[i][j]!=0&&biao[i][j-1]!=0) f[i][j]=min(f[i][j],f[i][j-1]+1);
      	
      	if(biao[i-1][j]!=biao[i][j]&&biao[i][j]==0&&fmap[i-1][j]!=0) 
		{
			f[i][j]=min(f[i][j],f[i-1][j]+2),biao[i][j]=biao[i-1][j];
		}
      	if(biao[i][j-1]!=biao[i][j]&&biao[i][j]==0&&fmap[i][j-1]!=0) 
		{
			f[i][j]=min(f[i][j],f[i][j-1]+2),biao[i][j]=biao[i][j-1];
		}
        }
        if(f[n][n]==1061109567) cout<<"-1";
        else cout<<f[n][n];
	return 0;
}
